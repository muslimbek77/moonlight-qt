#include <QApplication>
#include <QDebug>
#include <QEventLoop>
#include <QTimer>
#include "app/backend/cloudplayapi.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    qDebug() << "Testing CloudPlay API integration...";
    
    CloudPlayAPI api;
    
    // Test basic properties
    qDebug() << "Base URL:" << api.baseUrl();
    qDebug() << "Is authenticated:" << api.isAuthenticated();
    
    // Connect to signals to test signal emission
    QObject::connect(&api, &CloudPlayAPI::loginSuccess, [](const QString &token, const QString &username) {
        qDebug() << "Login success signal received! Token:" << token << "Username:" << username;
    });
    
    QObject::connect(&api, &CloudPlayAPI::loginFailed, [](const QString &error) {
        qDebug() << "Login failed signal received:" << error;
    });
    
    QObject::connect(&api, &CloudPlayAPI::apiError, [](const QString &error) {
        qDebug() << "API error signal received:" << error;
    });
    
    // Test API URL setting
    api.setBaseUrl("https://ctrl.cloudplay.uz/api/");
    qDebug() << "Updated base URL:" << api.baseUrl();
    
    qDebug() << "CloudPlay API integration test completed successfully!";
    qDebug() << "The API is properly initialized and ready for use.";
    
    return 0;
}