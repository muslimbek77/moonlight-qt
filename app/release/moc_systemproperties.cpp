/****************************************************************************
** Meta object code from reading C++ file 'systemproperties.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../backend/systemproperties.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'systemproperties.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SystemProperties_t {
    QByteArrayData data[22];
    char stringdata0[378];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SystemProperties_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SystemProperties_t qt_meta_stringdata_SystemProperties = {
    {
QT_MOC_LITERAL(0, 0, 16), // "SystemProperties"
QT_MOC_LITERAL(1, 17, 23), // "unmappedGamepadsChanged"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 15), // "refreshDisplays"
QT_MOC_LITERAL(4, 58, 19), // "getNativeResolution"
QT_MOC_LITERAL(5, 78, 12), // "displayIndex"
QT_MOC_LITERAL(6, 91, 21), // "getSafeAreaResolution"
QT_MOC_LITERAL(7, 113, 14), // "getRefreshRate"
QT_MOC_LITERAL(8, 128, 23), // "hasHardwareAcceleration"
QT_MOC_LITERAL(9, 152, 24), // "rendererAlwaysFullScreen"
QT_MOC_LITERAL(10, 177, 16), // "isRunningWayland"
QT_MOC_LITERAL(11, 194, 17), // "isRunningXWayland"
QT_MOC_LITERAL(12, 212, 7), // "isWow64"
QT_MOC_LITERAL(13, 220, 22), // "friendlyNativeArchName"
QT_MOC_LITERAL(14, 243, 21), // "hasDesktopEnvironment"
QT_MOC_LITERAL(15, 265, 10), // "hasBrowser"
QT_MOC_LITERAL(16, 276, 21), // "hasDiscordIntegration"
QT_MOC_LITERAL(17, 298, 16), // "unmappedGamepads"
QT_MOC_LITERAL(18, 315, 17), // "maximumResolution"
QT_MOC_LITERAL(19, 333, 13), // "versionString"
QT_MOC_LITERAL(20, 347, 11), // "supportsHdr"
QT_MOC_LITERAL(21, 359, 18) // "usesMaterial3Theme"

    },
    "SystemProperties\0unmappedGamepadsChanged\0"
    "\0refreshDisplays\0getNativeResolution\0"
    "displayIndex\0getSafeAreaResolution\0"
    "getRefreshRate\0hasHardwareAcceleration\0"
    "rendererAlwaysFullScreen\0isRunningWayland\0"
    "isRunningXWayland\0isWow64\0"
    "friendlyNativeArchName\0hasDesktopEnvironment\0"
    "hasBrowser\0hasDiscordIntegration\0"
    "unmappedGamepads\0maximumResolution\0"
    "versionString\0supportsHdr\0usesMaterial3Theme"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SystemProperties[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
      14,   50, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x02 /* Public */,
       4,    1,   41,    2, 0x02 /* Public */,
       6,    1,   44,    2, 0x02 /* Public */,
       7,    1,   47,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::QRect, QMetaType::Int,    5,
    QMetaType::QRect, QMetaType::Int,    5,
    QMetaType::Int, QMetaType::Int,    5,

 // properties: name, type, flags
       8, QMetaType::Bool, 0x00095401,
       9, QMetaType::Bool, 0x00095401,
      10, QMetaType::Bool, 0x00095401,
      11, QMetaType::Bool, 0x00095401,
      12, QMetaType::Bool, 0x00095401,
      13, QMetaType::QString, 0x00095401,
      14, QMetaType::Bool, 0x00095401,
      15, QMetaType::Bool, 0x00095401,
      16, QMetaType::Bool, 0x00095401,
      17, QMetaType::QString, 0x00495003,
      18, QMetaType::QSize, 0x00095401,
      19, QMetaType::QString, 0x00095401,
      20, QMetaType::Bool, 0x00095401,
      21, QMetaType::Bool, 0x00095401,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,

       0        // eod
};

void SystemProperties::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SystemProperties *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->unmappedGamepadsChanged(); break;
        case 1: _t->refreshDisplays(); break;
        case 2: { QRect _r = _t->getNativeResolution((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QRect*>(_a[0]) = std::move(_r); }  break;
        case 3: { QRect _r = _t->getSafeAreaResolution((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QRect*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->getRefreshRate((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SystemProperties::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SystemProperties::unmappedGamepadsChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SystemProperties *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->hasHardwareAcceleration; break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->rendererAlwaysFullScreen; break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->isRunningWayland; break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->isRunningXWayland; break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->isWow64; break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->friendlyNativeArchName; break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->hasDesktopEnvironment; break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->hasBrowser; break;
        case 8: *reinterpret_cast< bool*>(_v) = _t->hasDiscordIntegration; break;
        case 9: *reinterpret_cast< QString*>(_v) = _t->unmappedGamepads; break;
        case 10: *reinterpret_cast< QSize*>(_v) = _t->maximumResolution; break;
        case 11: *reinterpret_cast< QString*>(_v) = _t->versionString; break;
        case 12: *reinterpret_cast< bool*>(_v) = _t->supportsHdr; break;
        case 13: *reinterpret_cast< bool*>(_v) = _t->usesMaterial3Theme; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SystemProperties *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 9:
            if (_t->unmappedGamepads != *reinterpret_cast< QString*>(_v)) {
                _t->unmappedGamepads = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->unmappedGamepadsChanged();
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject SystemProperties::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SystemProperties.data,
    qt_meta_data_SystemProperties,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SystemProperties::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SystemProperties::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SystemProperties.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SystemProperties::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 14;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void SystemProperties::unmappedGamepadsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
