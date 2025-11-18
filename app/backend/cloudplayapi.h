#ifndef CLOUDPLAYAPI_H
#define CLOUDPLAYAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QUrl>

// Forward declarations
class ComputerManager;

class CloudPlayAPI : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool authenticated READ authenticated NOTIFY authenticationChanged)
    Q_PROPERTY(QString username READ username NOTIFY usernameChanged)

public:
    explicit CloudPlayAPI(QObject *parent = nullptr);
    
    struct ComputerData {
        int computerNumber;
        QString ipAddress;
        QString status;
        QString assignedUser;
    };
    
    struct UserCredentials {
        QString username;
        QString password;
        QString token;
        bool isAuthenticated;
    };
    
    // Property getters
    bool authenticated() const { return !m_authToken.isEmpty(); }
    QString username() const { return m_userCredentials.username; }
    QString baseUrl() const { return m_baseUrl; }
    void setBaseUrl(const QString &url) { m_baseUrl = url; }
    QString authToken() const { return m_authToken; }
    
    // QML-accessible methods
    Q_INVOKABLE void logout();
    
    // Moonlight Integration methods
    Q_INVOKABLE void addCloudPlayIPsToMoonlight();
    Q_INVOKABLE void syncProfilesWithMoonlight();
    Q_INVOKABLE void autoConnectToCloudPlay(const QString &ipAddress);
    
    // Gaming Profile Management
    Q_INVOKABLE void getGamingProfiles();
    Q_INVOKABLE void createGamingProfile(const QString &name, const QString &gameId);
    Q_INVOKABLE void updateGamingProfile(const QString &profileId, const QVariantMap &settings);
    Q_INVOKABLE void deleteGamingProfile(const QString &profileId);
    Q_INVOKABLE void startGamingSession(const QString &profileId, const QString &ipAddress);

public slots:
    // Authentication methods
    Q_INVOKABLE void loginUser(const QString &username, const QString &password);
    Q_INVOKABLE void registerUser(const QString &username, const QString &password, const QString &email);
    void refreshToken();
    
    // Computer management
    Q_INVOKABLE void getComputerData(int computerNumber);
    Q_INVOKABLE void assignComputerData(int computerNumber);
    Q_INVOKABLE void getAvailableComputers();
    Q_INVOKABLE void assignComputerToUser(int computerNumber, const QString &username);
    
    // IP management  
    Q_INVOKABLE void getIPAddresses();
    Q_INVOKABLE void getAvailableIpAddresses();
    Q_INVOKABLE void createIPAddress(const QString &address);
    Q_INVOKABLE void deleteIPAddress(const QString &id);
    Q_INVOKABLE void toggleIPActive(const QString &id);

signals:
    // Property change signals
    void authenticationChanged();
    void usernameChanged();
    
    // Authentication signals
    void loginSuccess(const QVariantMap &userData);
    void loginError(const QString &errorMessage);
    void registrationSuccess(const QString &message);
    void registrationFailed(const QString &errorMessage);
    
    // Computer management signals
    void computerDataReceived(const QVariantMap &data);
    void computerAssigned(int computerNumber, const QString &ipAddress);
    void computerAssignmentFailed(const QString &errorMessage);
    void computersReceived(const QVariantMap &computers);
    void availableComputersReceived(const QVariantList &computers);
    
    // IP management signals
    void ipAddressesReceived(const QVariantList &addresses);
    void ipAddressCreated(const QVariantMap &address);
    void ipAddressDeleted(const QString &id);
    void apiError(const QString &errorMessage);
    
    // Moonlight integration signals
    void cloudPlayIPsAdded(int count);
    void profilesSynced(bool success);
    void autoConnectionResult(bool success, const QString &message);
    
    // Gaming Profile Management signals
    void gamingProfilesReceived(const QVariantList &profiles);
    void gamingProfileCreated(const QVariantMap &profile);
    void gamingProfileUpdated(const QString &profileId);
    void gamingProfileDeleted(const QString &profileId);
    void gamingSessionStarted(const QString &sessionId, const QString &streamUrl);

private slots:
    void handleNetworkReply();
    void handleNetworkError(QNetworkReply::NetworkError error);

private:
    QNetworkAccessManager *m_networkManager;
    QString m_baseUrl;
    QString m_authToken;
    UserCredentials m_userCredentials;
    
    void makeRequest(const QString &endpoint, const QJsonObject &data = QJsonObject(), const QString &method = "GET");
    void setAuthHeader(QNetworkRequest &request);
    QJsonObject parseJsonResponse(QNetworkReply *reply);
};

#endif // CLOUDPLAYAPI_H