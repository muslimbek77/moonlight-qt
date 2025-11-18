/****************************************************************************
** Meta object code from reading C++ file 'cloudplayapi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../backend/cloudplayapi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cloudplayapi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CloudPlayAPI_t {
    QByteArrayData data[74];
    char stringdata0[1110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CloudPlayAPI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CloudPlayAPI_t qt_meta_stringdata_CloudPlayAPI = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CloudPlayAPI"
QT_MOC_LITERAL(1, 13, 21), // "authenticationChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 15), // "usernameChanged"
QT_MOC_LITERAL(4, 52, 12), // "loginSuccess"
QT_MOC_LITERAL(5, 65, 8), // "userData"
QT_MOC_LITERAL(6, 74, 10), // "loginError"
QT_MOC_LITERAL(7, 85, 12), // "errorMessage"
QT_MOC_LITERAL(8, 98, 19), // "registrationSuccess"
QT_MOC_LITERAL(9, 118, 7), // "message"
QT_MOC_LITERAL(10, 126, 18), // "registrationFailed"
QT_MOC_LITERAL(11, 145, 20), // "computerDataReceived"
QT_MOC_LITERAL(12, 166, 4), // "data"
QT_MOC_LITERAL(13, 171, 16), // "computerAssigned"
QT_MOC_LITERAL(14, 188, 14), // "computerNumber"
QT_MOC_LITERAL(15, 203, 9), // "ipAddress"
QT_MOC_LITERAL(16, 213, 24), // "computerAssignmentFailed"
QT_MOC_LITERAL(17, 238, 17), // "computersReceived"
QT_MOC_LITERAL(18, 256, 9), // "computers"
QT_MOC_LITERAL(19, 266, 26), // "availableComputersReceived"
QT_MOC_LITERAL(20, 293, 19), // "ipAddressesReceived"
QT_MOC_LITERAL(21, 313, 9), // "addresses"
QT_MOC_LITERAL(22, 323, 16), // "ipAddressCreated"
QT_MOC_LITERAL(23, 340, 7), // "address"
QT_MOC_LITERAL(24, 348, 16), // "ipAddressDeleted"
QT_MOC_LITERAL(25, 365, 2), // "id"
QT_MOC_LITERAL(26, 368, 8), // "apiError"
QT_MOC_LITERAL(27, 377, 17), // "cloudPlayIPsAdded"
QT_MOC_LITERAL(28, 395, 5), // "count"
QT_MOC_LITERAL(29, 401, 14), // "profilesSynced"
QT_MOC_LITERAL(30, 416, 7), // "success"
QT_MOC_LITERAL(31, 424, 20), // "autoConnectionResult"
QT_MOC_LITERAL(32, 445, 22), // "gamingProfilesReceived"
QT_MOC_LITERAL(33, 468, 8), // "profiles"
QT_MOC_LITERAL(34, 477, 20), // "gamingProfileCreated"
QT_MOC_LITERAL(35, 498, 7), // "profile"
QT_MOC_LITERAL(36, 506, 20), // "gamingProfileUpdated"
QT_MOC_LITERAL(37, 527, 9), // "profileId"
QT_MOC_LITERAL(38, 537, 20), // "gamingProfileDeleted"
QT_MOC_LITERAL(39, 558, 20), // "gamingSessionStarted"
QT_MOC_LITERAL(40, 579, 9), // "sessionId"
QT_MOC_LITERAL(41, 589, 9), // "streamUrl"
QT_MOC_LITERAL(42, 599, 9), // "loginUser"
QT_MOC_LITERAL(43, 609, 8), // "username"
QT_MOC_LITERAL(44, 618, 8), // "password"
QT_MOC_LITERAL(45, 627, 12), // "registerUser"
QT_MOC_LITERAL(46, 640, 5), // "email"
QT_MOC_LITERAL(47, 646, 12), // "refreshToken"
QT_MOC_LITERAL(48, 659, 15), // "getComputerData"
QT_MOC_LITERAL(49, 675, 18), // "assignComputerData"
QT_MOC_LITERAL(50, 694, 21), // "getAvailableComputers"
QT_MOC_LITERAL(51, 716, 20), // "assignComputerToUser"
QT_MOC_LITERAL(52, 737, 14), // "getIPAddresses"
QT_MOC_LITERAL(53, 752, 23), // "getAvailableIpAddresses"
QT_MOC_LITERAL(54, 776, 15), // "createIPAddress"
QT_MOC_LITERAL(55, 792, 15), // "deleteIPAddress"
QT_MOC_LITERAL(56, 808, 14), // "toggleIPActive"
QT_MOC_LITERAL(57, 823, 18), // "handleNetworkReply"
QT_MOC_LITERAL(58, 842, 18), // "handleNetworkError"
QT_MOC_LITERAL(59, 861, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(60, 889, 5), // "error"
QT_MOC_LITERAL(61, 895, 6), // "logout"
QT_MOC_LITERAL(62, 902, 26), // "addCloudPlayIPsToMoonlight"
QT_MOC_LITERAL(63, 929, 25), // "syncProfilesWithMoonlight"
QT_MOC_LITERAL(64, 955, 22), // "autoConnectToCloudPlay"
QT_MOC_LITERAL(65, 978, 17), // "getGamingProfiles"
QT_MOC_LITERAL(66, 996, 19), // "createGamingProfile"
QT_MOC_LITERAL(67, 1016, 4), // "name"
QT_MOC_LITERAL(68, 1021, 6), // "gameId"
QT_MOC_LITERAL(69, 1028, 19), // "updateGamingProfile"
QT_MOC_LITERAL(70, 1048, 8), // "settings"
QT_MOC_LITERAL(71, 1057, 19), // "deleteGamingProfile"
QT_MOC_LITERAL(72, 1077, 18), // "startGamingSession"
QT_MOC_LITERAL(73, 1096, 13) // "authenticated"

    },
    "CloudPlayAPI\0authenticationChanged\0\0"
    "usernameChanged\0loginSuccess\0userData\0"
    "loginError\0errorMessage\0registrationSuccess\0"
    "message\0registrationFailed\0"
    "computerDataReceived\0data\0computerAssigned\0"
    "computerNumber\0ipAddress\0"
    "computerAssignmentFailed\0computersReceived\0"
    "computers\0availableComputersReceived\0"
    "ipAddressesReceived\0addresses\0"
    "ipAddressCreated\0address\0ipAddressDeleted\0"
    "id\0apiError\0cloudPlayIPsAdded\0count\0"
    "profilesSynced\0success\0autoConnectionResult\0"
    "gamingProfilesReceived\0profiles\0"
    "gamingProfileCreated\0profile\0"
    "gamingProfileUpdated\0profileId\0"
    "gamingProfileDeleted\0gamingSessionStarted\0"
    "sessionId\0streamUrl\0loginUser\0username\0"
    "password\0registerUser\0email\0refreshToken\0"
    "getComputerData\0assignComputerData\0"
    "getAvailableComputers\0assignComputerToUser\0"
    "getIPAddresses\0getAvailableIpAddresses\0"
    "createIPAddress\0deleteIPAddress\0"
    "toggleIPActive\0handleNetworkReply\0"
    "handleNetworkError\0QNetworkReply::NetworkError\0"
    "error\0logout\0addCloudPlayIPsToMoonlight\0"
    "syncProfilesWithMoonlight\0"
    "autoConnectToCloudPlay\0getGamingProfiles\0"
    "createGamingProfile\0name\0gameId\0"
    "updateGamingProfile\0settings\0"
    "deleteGamingProfile\0startGamingSession\0"
    "authenticated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CloudPlayAPI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      46,   14, // methods
       2,  380, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      23,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  244,    2, 0x06 /* Public */,
       3,    0,  245,    2, 0x06 /* Public */,
       4,    1,  246,    2, 0x06 /* Public */,
       6,    1,  249,    2, 0x06 /* Public */,
       8,    1,  252,    2, 0x06 /* Public */,
      10,    1,  255,    2, 0x06 /* Public */,
      11,    1,  258,    2, 0x06 /* Public */,
      13,    2,  261,    2, 0x06 /* Public */,
      16,    1,  266,    2, 0x06 /* Public */,
      17,    1,  269,    2, 0x06 /* Public */,
      19,    1,  272,    2, 0x06 /* Public */,
      20,    1,  275,    2, 0x06 /* Public */,
      22,    1,  278,    2, 0x06 /* Public */,
      24,    1,  281,    2, 0x06 /* Public */,
      26,    1,  284,    2, 0x06 /* Public */,
      27,    1,  287,    2, 0x06 /* Public */,
      29,    1,  290,    2, 0x06 /* Public */,
      31,    2,  293,    2, 0x06 /* Public */,
      32,    1,  298,    2, 0x06 /* Public */,
      34,    1,  301,    2, 0x06 /* Public */,
      36,    1,  304,    2, 0x06 /* Public */,
      38,    1,  307,    2, 0x06 /* Public */,
      39,    2,  310,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      42,    2,  315,    2, 0x0a /* Public */,
      45,    3,  320,    2, 0x0a /* Public */,
      47,    0,  327,    2, 0x0a /* Public */,
      48,    1,  328,    2, 0x0a /* Public */,
      49,    1,  331,    2, 0x0a /* Public */,
      50,    0,  334,    2, 0x0a /* Public */,
      51,    2,  335,    2, 0x0a /* Public */,
      52,    0,  340,    2, 0x0a /* Public */,
      53,    0,  341,    2, 0x0a /* Public */,
      54,    1,  342,    2, 0x0a /* Public */,
      55,    1,  345,    2, 0x0a /* Public */,
      56,    1,  348,    2, 0x0a /* Public */,
      57,    0,  351,    2, 0x08 /* Private */,
      58,    1,  352,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      61,    0,  355,    2, 0x02 /* Public */,
      62,    0,  356,    2, 0x02 /* Public */,
      63,    0,  357,    2, 0x02 /* Public */,
      64,    1,  358,    2, 0x02 /* Public */,
      65,    0,  361,    2, 0x02 /* Public */,
      66,    2,  362,    2, 0x02 /* Public */,
      69,    2,  367,    2, 0x02 /* Public */,
      71,    1,  372,    2, 0x02 /* Public */,
      72,    2,  375,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantMap,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QVariantMap,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   14,   15,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QVariantMap,   18,
    QMetaType::Void, QMetaType::QVariantList,   18,
    QMetaType::Void, QMetaType::QVariantList,   21,
    QMetaType::Void, QMetaType::QVariantMap,   23,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   30,    9,
    QMetaType::Void, QMetaType::QVariantList,   33,
    QMetaType::Void, QMetaType::QVariantMap,   35,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   40,   41,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   43,   44,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   43,   44,   46,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   14,   43,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 59,   60,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   67,   68,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariantMap,   37,   70,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   37,   15,

 // properties: name, type, flags
      73, QMetaType::Bool, 0x00495001,
      43, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void CloudPlayAPI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CloudPlayAPI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->authenticationChanged(); break;
        case 1: _t->usernameChanged(); break;
        case 2: _t->loginSuccess((*reinterpret_cast< const QVariantMap(*)>(_a[1]))); break;
        case 3: _t->loginError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->registrationSuccess((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->registrationFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->computerDataReceived((*reinterpret_cast< const QVariantMap(*)>(_a[1]))); break;
        case 7: _t->computerAssigned((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->computerAssignmentFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->computersReceived((*reinterpret_cast< const QVariantMap(*)>(_a[1]))); break;
        case 10: _t->availableComputersReceived((*reinterpret_cast< const QVariantList(*)>(_a[1]))); break;
        case 11: _t->ipAddressesReceived((*reinterpret_cast< const QVariantList(*)>(_a[1]))); break;
        case 12: _t->ipAddressCreated((*reinterpret_cast< const QVariantMap(*)>(_a[1]))); break;
        case 13: _t->ipAddressDeleted((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->apiError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->cloudPlayIPsAdded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->profilesSynced((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->autoConnectionResult((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 18: _t->gamingProfilesReceived((*reinterpret_cast< const QVariantList(*)>(_a[1]))); break;
        case 19: _t->gamingProfileCreated((*reinterpret_cast< const QVariantMap(*)>(_a[1]))); break;
        case 20: _t->gamingProfileUpdated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: _t->gamingProfileDeleted((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->gamingSessionStarted((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 23: _t->loginUser((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 24: _t->registerUser((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 25: _t->refreshToken(); break;
        case 26: _t->getComputerData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->assignComputerData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->getAvailableComputers(); break;
        case 29: _t->assignComputerToUser((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 30: _t->getIPAddresses(); break;
        case 31: _t->getAvailableIpAddresses(); break;
        case 32: _t->createIPAddress((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 33: _t->deleteIPAddress((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 34: _t->toggleIPActive((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 35: _t->handleNetworkReply(); break;
        case 36: _t->handleNetworkError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 37: _t->logout(); break;
        case 38: _t->addCloudPlayIPsToMoonlight(); break;
        case 39: _t->syncProfilesWithMoonlight(); break;
        case 40: _t->autoConnectToCloudPlay((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 41: _t->getGamingProfiles(); break;
        case 42: _t->createGamingProfile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 43: _t->updateGamingProfile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2]))); break;
        case 44: _t->deleteGamingProfile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 45: _t->startGamingSession((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 36:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CloudPlayAPI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::authenticationChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::usernameChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QVariantMap & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::loginSuccess)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::loginError)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::registrationSuccess)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::registrationFailed)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QVariantMap & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::computerDataReceived)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::computerAssigned)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::computerAssignmentFailed)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QVariantMap & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::computersReceived)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QVariantList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::availableComputersReceived)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QVariantList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::ipAddressesReceived)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QVariantMap & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::ipAddressCreated)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::ipAddressDeleted)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::apiError)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::cloudPlayIPsAdded)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::profilesSynced)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(bool , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::autoConnectionResult)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QVariantList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::gamingProfilesReceived)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QVariantMap & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::gamingProfileCreated)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::gamingProfileUpdated)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::gamingProfileDeleted)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::gamingSessionStarted)) {
                *result = 22;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CloudPlayAPI *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->authenticated(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->username(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CloudPlayAPI::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CloudPlayAPI.data,
    qt_meta_data_CloudPlayAPI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CloudPlayAPI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CloudPlayAPI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CloudPlayAPI.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CloudPlayAPI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CloudPlayAPI::authenticationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CloudPlayAPI::usernameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CloudPlayAPI::loginSuccess(const QVariantMap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CloudPlayAPI::loginError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CloudPlayAPI::registrationSuccess(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CloudPlayAPI::registrationFailed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CloudPlayAPI::computerDataReceived(const QVariantMap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CloudPlayAPI::computerAssigned(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void CloudPlayAPI::computerAssignmentFailed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void CloudPlayAPI::computersReceived(const QVariantMap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void CloudPlayAPI::availableComputersReceived(const QVariantList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void CloudPlayAPI::ipAddressesReceived(const QVariantList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void CloudPlayAPI::ipAddressCreated(const QVariantMap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void CloudPlayAPI::ipAddressDeleted(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void CloudPlayAPI::apiError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void CloudPlayAPI::cloudPlayIPsAdded(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void CloudPlayAPI::profilesSynced(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void CloudPlayAPI::autoConnectionResult(bool _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void CloudPlayAPI::gamingProfilesReceived(const QVariantList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void CloudPlayAPI::gamingProfileCreated(const QVariantMap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void CloudPlayAPI::gamingProfileUpdated(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void CloudPlayAPI::gamingProfileDeleted(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void CloudPlayAPI::gamingSessionStarted(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
