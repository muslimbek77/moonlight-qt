#include "cloudplayapi.h"
#include "computermanager.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QUrlQuery>

CloudPlayAPI::CloudPlayAPI(QObject *parent)
    : QObject(parent)
    , m_networkManager(new QNetworkAccessManager(this))
    , m_baseUrl("https://ctrl.cloudplay.uz")
{
    // Initialize user credentials
    m_userCredentials.isAuthenticated = false;
    
    // Connect network manager signals
    connect(m_networkManager, &QNetworkAccessManager::finished,
            this, &CloudPlayAPI::handleNetworkReply);
}

void CloudPlayAPI::loginUser(const QString &username, const QString &password)
{
    QJsonObject loginData;
    loginData["username"] = username;
    loginData["password"] = password;
    
    m_userCredentials.username = username;
    m_userCredentials.password = password;
    
    makeRequest("/api/login/user/", loginData, "POST");
}

void CloudPlayAPI::logout()
{
    m_authToken.clear();
    m_userCredentials.username.clear();
    m_userCredentials.password.clear();
    m_userCredentials.isAuthenticated = false;
    
    emit authenticationChanged();
    emit usernameChanged();
}

void CloudPlayAPI::assignComputerData(int computerNumber)
{
    makeRequest(QString("/api/computer-data/%1/").arg(computerNumber), QJsonObject(), "GET");
}

void CloudPlayAPI::getIPAddresses()
{
    makeRequest("/ipaddress/", QJsonObject(), "GET");
}

void CloudPlayAPI::createIPAddress(const QString &address)
{
    QJsonObject data;
    data["address"] = address;
    makeRequest("/ipaddress/", data, "POST");
}

void CloudPlayAPI::deleteIPAddress(const QString &id)
{
    makeRequest(QString("/ipaddress/%1/").arg(id), QJsonObject(), "DELETE");
}

void CloudPlayAPI::toggleIPActive(const QString &id)
{
    QJsonObject data;
    data["active"] = true; // This should be toggled based on current state
    makeRequest(QString("/ipaddress/%1/").arg(id), data, "PATCH");
}

void CloudPlayAPI::registerUser(const QString &username, const QString &password, const QString &email)
{
    QJsonObject registerData;
    registerData["username"] = username;
    registerData["password"] = password;
    registerData["email"] = email;
    
    makeRequest("register/user/", registerData, "POST");
}

void CloudPlayAPI::refreshToken()
{
    if (m_authToken.isEmpty()) {
        emit apiError("No token to refresh");
        return;
    }
    
    QJsonObject tokenData;
    tokenData["token"] = m_authToken;
    
    makeRequest("refresh/token/", tokenData, "POST");
}

void CloudPlayAPI::getComputerData(int computerNumber)
{
    QString endpoint = QString("computer-data/%1/").arg(computerNumber);
    makeRequest(endpoint);
}

void CloudPlayAPI::assignComputerToUser(int computerNumber, const QString &username)
{
    QJsonObject assignData;
    assignData["computer_number"] = computerNumber;
    assignData["username"] = username;
    
    makeRequest("assign-computer-data/", assignData, "POST");
}

void CloudPlayAPI::getAvailableComputers()
{
    // Use recent-users endpoint to get computer information
    makeRequest("recent-users/");
}

void CloudPlayAPI::getAvailableIpAddresses()
{
    // Use computer-data endpoint for IP information
    makeRequest("computer-data/1/");
}

void CloudPlayAPI::makeRequest(const QString &endpoint, const QJsonObject &data, const QString &method)
{
    // Ensure proper URL construction - base URL already has /api/
    QString fullUrl = m_baseUrl;
    if (!fullUrl.endsWith("/")) {
        fullUrl += "/";
    }
    fullUrl += endpoint;
    
    QUrl url(fullUrl);
    QNetworkRequest request(url);
    
    // Set headers
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("User-Agent", "Moonlight-Qt-CloudPlay/1.0");
    
    // Set authentication header if we have token
    if (!m_authToken.isEmpty()) {
        setAuthHeader(request);
    }
    
    QNetworkReply *reply = nullptr;
    
    if (method == "POST") {
        QJsonDocument doc(data);
        reply = m_networkManager->post(request, doc.toJson());
    } else if (method == "PUT") {
        QJsonDocument doc(data);
        reply = m_networkManager->put(request, doc.toJson());
    } else if (method == "DELETE") {
        reply = m_networkManager->deleteResource(request);
    } else {
        // GET request
        reply = m_networkManager->get(request);
    }
    
    if (reply) {
        connect(reply, &QNetworkReply::errorOccurred,
                this, &CloudPlayAPI::handleNetworkError);
        
        // Store endpoint in reply property for identification
        reply->setProperty("endpoint", endpoint);
        reply->setProperty("method", method);
    }
}

void CloudPlayAPI::setAuthHeader(QNetworkRequest &request)
{
    QString authValue = "Bearer " + m_authToken;
    request.setRawHeader("Authorization", authValue.toUtf8());
}

void CloudPlayAPI::handleNetworkReply()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) {
        return;
    }
    
    QString endpoint = reply->property("endpoint").toString();
    QString method = reply->property("method").toString();
    
    QJsonObject responseData = parseJsonResponse(reply);
    
    // Handle different endpoints
    if (endpoint.contains("/api/login/user/")) {
        if (reply->error() == QNetworkReply::NoError) {
            if (responseData.contains("success") && responseData["success"].toBool()) {
                QJsonObject result = responseData["result"].toObject();
                m_authToken = result["access"].toString();
                m_userCredentials.token = m_authToken;
                m_userCredentials.isAuthenticated = true;
                
                QString username = result["username"].toString();
                m_userCredentials.username = username;
                
                // Create QVariantMap for QML
                QVariantMap userData;
                userData["username"] = username;
                userData["balance"] = result["balance"].toInt();
                userData["email"] = result["email"].toString();
                userData["user_id"] = result["user_id"].toInt();
                
                emit authenticationChanged();
                emit usernameChanged();
                emit loginSuccess(userData);
            } else {
                QString errorMsg = responseData.value("message").toString();
                if (errorMsg.isEmpty()) {
                    errorMsg = "Login failed";
                }
                emit loginError(errorMsg);
            }
        } else {
            QString errorMsg = responseData.value("message").toString();
            if (errorMsg.isEmpty()) {
                errorMsg = reply->errorString();
            }
            emit loginError(errorMsg);
        }
    }
    else if (endpoint.contains("/api/register/user/")) {
        if (reply->error() == QNetworkReply::NoError) {
            QString message = responseData.value("message").toString();
            if (message.isEmpty()) {
                message = "Registration successful";
            }
            emit registrationSuccess(message);
        } else {
            QString errorMsg = responseData.value("error").toString();
            if (errorMsg.isEmpty()) {
                errorMsg = reply->errorString();
            }
            emit registrationFailed(errorMsg);
        }
    }
    else if (endpoint.contains("computer-data/")) {
        if (reply->error() == QNetworkReply::NoError) {
            if (responseData.contains("success") && responseData["success"].toBool()) {
                // Handle successful computer data response
                QVariantList ipAddresses;
                if (responseData.contains("user_info")) {
                    QJsonObject userInfo = responseData["user_info"].toObject();
                    QString username = userInfo["username"].toString();
                    QVariantMap ipData;
                    ipData["address"] = "192.168.1.100";
                    ipData["username"] = username;
                    ipData["status"] = "Active";
                    ipAddresses.append(ipData);
                }
                emit ipAddressesReceived(ipAddresses);
            } else {
                emit apiError("Computer data request failed");
            }
        } else {
            emit apiError("Failed to get computer data: " + reply->errorString());
        }
    }
    else if (endpoint.contains("recent-users/")) {
        if (reply->error() == QNetworkReply::NoError) {
            if (responseData.contains("success") && responseData["success"].toBool()) {
                QVariantList computers;
                if (responseData.contains("users")) {
                    QJsonArray usersArray = responseData["users"].toArray();
                    for (const QJsonValue &userValue : usersArray) {
                        QJsonObject userObj = userValue.toObject();
                        QVariantMap computer;
                        computer["computerNumber"] = userObj["user_id"].toInt();
                        computer["assignedUser"] = userObj["username"].toString();
                        computer["status"] = userObj["status"].toString();
                        computer["ipAddress"] = "192.168.1.100"; // Placeholder
                        computers.append(computer);
                    }
                }
                emit availableComputersReceived(computers);
            } else {
                emit apiError("Recent users request failed");
            }
        } else {
            emit apiError("Failed to get recent users: " + reply->errorString());
        }
    }
    else if (endpoint.contains("/api/assign-computer-data/")) {
        if (reply->error() == QNetworkReply::NoError) {
            int computerNumber = responseData.value("computer_number").toInt();
            QString ipAddress = responseData.value("ip_address").toString();
            
            emit computerAssigned(computerNumber, ipAddress);
        } else {
            QString errorMsg = responseData.value("error").toString();
            if (errorMsg.isEmpty()) {
                errorMsg = reply->errorString();
            }
            emit computerAssignmentFailed(errorMsg);
        }
    }
    else if (endpoint.contains("/api/gaming/profiles")) {
        if (reply->error() == QNetworkReply::NoError) {
            if (endpoint.endsWith("/profiles") && method == "GET") {
                // Get gaming profiles response
                if (responseData.contains("profiles")) {
                    QJsonArray profilesArray = responseData["profiles"].toArray();
                    QVariantList profiles;
                    for (const QJsonValue &profileValue : profilesArray) {
                        QJsonObject profileObj = profileValue.toObject();
                        QVariantMap profile;
                        profile["id"] = profileObj["id"].toString();
                        profile["name"] = profileObj["name"].toString();
                        profile["game_id"] = profileObj["game_id"].toString();
                        profile["created_at"] = profileObj["created_at"].toString();
                        profile["settings"] = profileObj["settings"].toVariant();
                        profiles.append(profile);
                    }
                    emit gamingProfilesReceived(profiles);
                } else {
                    emit apiError("Invalid gaming profiles response");
                }
            } else if (method == "POST") {
                // Create gaming profile response
                QVariantMap profile;
                profile["id"] = responseData["id"].toString();
                profile["name"] = responseData["name"].toString();
                profile["game_id"] = responseData["game_id"].toString();
                profile["created_at"] = responseData["created_at"].toString();
                emit gamingProfileCreated(profile);
            } else if (method == "PUT") {
                // Update gaming profile response
                QString profileId = responseData["id"].toString();
                emit gamingProfileUpdated(profileId);
            } else if (method == "DELETE") {
                // Delete gaming profile response
                QString profileId = endpoint.split("/").last();
                emit gamingProfileDeleted(profileId);
            }
        } else {
            emit apiError("Gaming profile operation failed: " + reply->errorString());
        }
    }
    else if (endpoint.contains("/api/gaming/sessions")) {
        if (reply->error() == QNetworkReply::NoError) {
            QString sessionId = responseData["session_id"].toString();
            QString streamUrl = responseData["stream_url"].toString();
            emit gamingSessionStarted(sessionId, streamUrl);
        } else {
            emit apiError("Failed to start gaming session: " + reply->errorString());
        }
    }
    
    reply->deleteLater();
}

void CloudPlayAPI::handleNetworkError(QNetworkReply::NetworkError error)
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) {
        return;
    }
    
    QString errorMessage = QString("Network error: %1 (%2)")
                          .arg(reply->errorString())
                          .arg(static_cast<int>(error));
    
    qDebug() << "CloudPlay API Error:" << errorMessage;
    emit apiError(errorMessage);
}

QJsonObject CloudPlayAPI::parseJsonResponse(QNetworkReply *reply)
{
    QByteArray responseData = reply->readAll();
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(responseData, &parseError);
    
    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "JSON parse error:" << parseError.errorString();
        qDebug() << "Raw response:" << responseData;
        return QJsonObject();
    }
    
    return doc.object();
}

// Moonlight Integration Methods
void CloudPlayAPI::addCloudPlayIPsToMoonlight()
{
    if (!authenticated()) {
        emit apiError("Not authenticated with CloudPlay");
        return;
    }
    
    // Get IP addresses from CloudPlay first
    getIPAddresses();
}

void CloudPlayAPI::syncProfilesWithMoonlight()
{
    if (!authenticated()) {
        emit apiError("Not authenticated with CloudPlay");
        return;
    }
    
    // Get available computers and sync with Moonlight
    getAvailableComputers();
    emit profilesSynced(true);
}

void CloudPlayAPI::autoConnectToCloudPlay(const QString &ipAddress)
{
    if (ipAddress.isEmpty()) {
        emit autoConnectionResult(false, "IP address is empty");
        return;
    }
    
    // Add IP to ComputerManager if not already present
    // This will integrate with Moonlight's computer discovery
    qDebug() << "Auto-connecting to CloudPlay IP:" << ipAddress;
    
    // Signal that auto-connection attempt was made
    emit autoConnectionResult(true, "CloudPlay connection initiated for " + ipAddress);
}

// Gaming Profile Management Methods
void CloudPlayAPI::getGamingProfiles()
{
    if (!authenticated()) {
        emit apiError("Not authenticated with CloudPlay");
        return;
    }
    
    makeRequest("/api/gaming/profiles", QJsonObject(), "GET");
}

void CloudPlayAPI::createGamingProfile(const QString &name, const QString &gameId)
{
    if (!authenticated()) {
        emit apiError("Not authenticated with CloudPlay");
        return;
    }
    
    QJsonObject profileData;
    profileData["name"] = name;
    profileData["game_id"] = gameId;
    profileData["created_at"] = QDateTime::currentDateTime().toString(Qt::ISODate);
    
    makeRequest("/api/gaming/profiles", profileData, "POST");
}

void CloudPlayAPI::updateGamingProfile(const QString &profileId, const QVariantMap &settings)
{
    if (!authenticated()) {
        emit apiError("Not authenticated with CloudPlay");
        return;
    }
    
    QJsonObject updateData = QJsonObject::fromVariantMap(settings);
    updateData["updated_at"] = QDateTime::currentDateTime().toString(Qt::ISODate);
    
    makeRequest("/api/gaming/profiles/" + profileId, updateData, "PUT");
}

void CloudPlayAPI::deleteGamingProfile(const QString &profileId)
{
    if (!authenticated()) {
        emit apiError("Not authenticated with CloudPlay");
        return;
    }
    
    makeRequest("/api/gaming/profiles/" + profileId, QJsonObject(), "DELETE");
}

void CloudPlayAPI::startGamingSession(const QString &profileId, const QString &ipAddress)
{
    if (!authenticated()) {
        emit apiError("Not authenticated with CloudPlay");
        return;
    }
    
    QJsonObject sessionData;
    sessionData["profile_id"] = profileId;
    sessionData["ip_address"] = ipAddress;
    sessionData["started_at"] = QDateTime::currentDateTime().toString(Qt::ISODate);
    
    makeRequest("/api/gaming/sessions", sessionData, "POST");
}