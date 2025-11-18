/****************************************************************************
** Meta object code from reading C++ file 'cloudplayapi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "app/backend/cloudplayapi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
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
    QByteArrayData data[36];
    char stringdata0[524];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CloudPlayAPI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CloudPlayAPI_t qt_meta_stringdata_CloudPlayAPI = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CloudPlayAPI"
QT_MOC_LITERAL(1, 13, 12), // "loginSuccess"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "token"
QT_MOC_LITERAL(4, 33, 8), // "username"
QT_MOC_LITERAL(5, 42, 11), // "loginFailed"
QT_MOC_LITERAL(6, 54, 12), // "errorMessage"
QT_MOC_LITERAL(7, 67, 19), // "registrationSuccess"
QT_MOC_LITERAL(8, 87, 7), // "message"
QT_MOC_LITERAL(9, 95, 18), // "registrationFailed"
QT_MOC_LITERAL(10, 114, 20), // "computerDataReceived"
QT_MOC_LITERAL(11, 135, 12), // "ComputerData"
QT_MOC_LITERAL(12, 148, 4), // "data"
QT_MOC_LITERAL(13, 153, 16), // "computerAssigned"
QT_MOC_LITERAL(14, 170, 14), // "computerNumber"
QT_MOC_LITERAL(15, 185, 9), // "ipAddress"
QT_MOC_LITERAL(16, 195, 24), // "computerAssignmentFailed"
QT_MOC_LITERAL(17, 220, 26), // "availableComputersReceived"
QT_MOC_LITERAL(18, 247, 19), // "QList<ComputerData>"
QT_MOC_LITERAL(19, 267, 9), // "computers"
QT_MOC_LITERAL(20, 277, 19), // "ipAddressesReceived"
QT_MOC_LITERAL(21, 297, 11), // "ipAddresses"
QT_MOC_LITERAL(22, 309, 8), // "apiError"
QT_MOC_LITERAL(23, 318, 9), // "loginUser"
QT_MOC_LITERAL(24, 328, 8), // "password"
QT_MOC_LITERAL(25, 337, 12), // "registerUser"
QT_MOC_LITERAL(26, 350, 5), // "email"
QT_MOC_LITERAL(27, 356, 12), // "refreshToken"
QT_MOC_LITERAL(28, 369, 15), // "getComputerData"
QT_MOC_LITERAL(29, 385, 20), // "assignComputerToUser"
QT_MOC_LITERAL(30, 406, 21), // "getAvailableComputers"
QT_MOC_LITERAL(31, 428, 23), // "getAvailableIpAddresses"
QT_MOC_LITERAL(32, 452, 18), // "handleNetworkReply"
QT_MOC_LITERAL(33, 471, 18), // "handleNetworkError"
QT_MOC_LITERAL(34, 490, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(35, 518, 5) // "error"

    },
    "CloudPlayAPI\0loginSuccess\0\0token\0"
    "username\0loginFailed\0errorMessage\0"
    "registrationSuccess\0message\0"
    "registrationFailed\0computerDataReceived\0"
    "ComputerData\0data\0computerAssigned\0"
    "computerNumber\0ipAddress\0"
    "computerAssignmentFailed\0"
    "availableComputersReceived\0"
    "QList<ComputerData>\0computers\0"
    "ipAddressesReceived\0ipAddresses\0"
    "apiError\0loginUser\0password\0registerUser\0"
    "email\0refreshToken\0getComputerData\0"
    "assignComputerToUser\0getAvailableComputers\0"
    "getAvailableIpAddresses\0handleNetworkReply\0"
    "handleNetworkError\0QNetworkReply::NetworkError\0"
    "error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CloudPlayAPI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  109,    2, 0x06 /* Public */,
       5,    1,  114,    2, 0x06 /* Public */,
       7,    1,  117,    2, 0x06 /* Public */,
       9,    1,  120,    2, 0x06 /* Public */,
      10,    1,  123,    2, 0x06 /* Public */,
      13,    2,  126,    2, 0x06 /* Public */,
      16,    1,  131,    2, 0x06 /* Public */,
      17,    1,  134,    2, 0x06 /* Public */,
      20,    1,  137,    2, 0x06 /* Public */,
      22,    1,  140,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    2,  143,    2, 0x0a /* Public */,
      25,    3,  148,    2, 0x0a /* Public */,
      27,    0,  155,    2, 0x0a /* Public */,
      28,    1,  156,    2, 0x0a /* Public */,
      29,    2,  159,    2, 0x0a /* Public */,
      30,    0,  164,    2, 0x0a /* Public */,
      31,    0,  165,    2, 0x0a /* Public */,
      32,    0,  166,    2, 0x08 /* Private */,
      33,    1,  167,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   14,   15,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::QStringList,   21,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,   24,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,   24,   26,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   14,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 34,   35,

       0        // eod
};

void CloudPlayAPI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CloudPlayAPI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loginSuccess((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->loginFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->registrationSuccess((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->registrationFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->computerDataReceived((*reinterpret_cast< const ComputerData(*)>(_a[1]))); break;
        case 5: _t->computerAssigned((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->computerAssignmentFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->availableComputersReceived((*reinterpret_cast< const QList<ComputerData>(*)>(_a[1]))); break;
        case 8: _t->ipAddressesReceived((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 9: _t->apiError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->loginUser((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 11: _t->registerUser((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 12: _t->refreshToken(); break;
        case 13: _t->getComputerData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->assignComputerToUser((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 15: _t->getAvailableComputers(); break;
        case 16: _t->getAvailableIpAddresses(); break;
        case 17: _t->handleNetworkReply(); break;
        case 18: _t->handleNetworkError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CloudPlayAPI::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::loginSuccess)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::loginFailed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::registrationSuccess)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::registrationFailed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const ComputerData & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::computerDataReceived)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::computerAssigned)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::computerAssignmentFailed)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QList<ComputerData> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::availableComputersReceived)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QStringList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::ipAddressesReceived)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (CloudPlayAPI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CloudPlayAPI::apiError)) {
                *result = 9;
                return;
            }
        }
    }
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
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void CloudPlayAPI::loginSuccess(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CloudPlayAPI::loginFailed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CloudPlayAPI::registrationSuccess(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CloudPlayAPI::registrationFailed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CloudPlayAPI::computerDataReceived(const ComputerData & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CloudPlayAPI::computerAssigned(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CloudPlayAPI::computerAssignmentFailed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CloudPlayAPI::availableComputersReceived(const QList<ComputerData> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void CloudPlayAPI::ipAddressesReceived(const QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void CloudPlayAPI::apiError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
