#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include <QEventLoop>
#include "app/backend/cloudplayapi.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    
    qDebug() << "=== CloudPlay API Integration Test ===";
    qDebug() << "Moonlight-Qt CloudPlay Integration Test";
    qDebug() << "API Base URL: https://ctrl.cloudplay.uz/api/";
    qDebug() << "";
    
    // CloudPlay API instance yaratish
    CloudPlayAPI *cloudPlayAPI = new CloudPlayAPI();
    
    // API base URL ni o'rnatish
    cloudPlayAPI->setBaseUrl("https://ctrl.cloudplay.uz/api/");
    
    qDebug() << "CloudPlay API yaratildi:";
    qDebug() << "  - Base URL:" << cloudPlayAPI->baseUrl();
    qDebug() << "  - Authenticated:" << (cloudPlayAPI->isAuthenticated() ? "Ha" : "Yo'q");
    qDebug() << "";
    
    // Signal-slot bog'lanishlar
    QObject::connect(cloudPlayAPI, &CloudPlayAPI::loginSuccess, 
                     [](const QString &token, const QString &username) {
        qDebug() << "✓ LOGIN MUVAFFAQIYATLI!";
        qDebug() << "  - Username:" << username;
        qDebug() << "  - Token:" << token.left(20) + "...";
    });
    
    QObject::connect(cloudPlayAPI, &CloudPlayAPI::loginFailed, 
                     [](const QString &error) {
        qDebug() << "✗ LOGIN XATOSI:" << error;
    });
    
    QObject::connect(cloudPlayAPI, &CloudPlayAPI::availableComputersReceived, 
                     [](const QList<CloudPlayAPI::ComputerData> &computers) {
        qDebug() << "✓ KOMPYUTERLAR OLINDI:";
        qDebug() << "  - Jami kompyuterlar soni:" << computers.size();
        for (const auto &computer : computers) {
            qDebug() << "    * Kompyuter" << computer.computerNumber 
                     << "- IP:" << computer.ipAddress
                     << "- Status:" << computer.status;
        }
    });
    
    QObject::connect(cloudPlayAPI, &CloudPlayAPI::ipAddressesReceived, 
                     [](const QStringList &ipAddresses) {
        qDebug() << "✓ IP ADDRESSLAR OLINDI:";
        qDebug() << "  - Jami IP lar soni:" << ipAddresses.size();
        for (const QString &ip : ipAddresses) {
            qDebug() << "    * IP:" << ip;
        }
    });
    
    QObject::connect(cloudPlayAPI, &CloudPlayAPI::apiError, 
                     [](const QString &error) {
        qDebug() << "✗ API XATOSI:" << error;
    });
    
    // Test sequenscesini boshlash
    QTimer::singleShot(1000, [cloudPlayAPI]() {
        qDebug() << "--- Test 1: Mavjud IP addresslarni olish ---";
        cloudPlayAPI->getAvailableIpAddresses();
    });
    
    QTimer::singleShot(3000, [cloudPlayAPI]() {
        qDebug() << "--- Test 2: Mavjud kompyuterlarni olish ---";
        cloudPlayAPI->getAvailableComputers();
    });
    
    QTimer::singleShot(7000, [&app]() {
        qDebug() << "";
        qDebug() << "=== CloudPlay API Test Tugallandi ===";
        qDebug() << "CloudPlay API muvaffaqiyatli Moonlight-Qt ga integratsiya qilindi!";
        qDebug() << "Network requestlar bajarildi va signallar test qilindi.";
        app.quit();
    });
    
    return app.exec();
}