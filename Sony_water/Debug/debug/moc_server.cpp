/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_server_t {
    QByteArrayData data[15];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_server_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_server_t qt_meta_stringdata_server = {
    {
QT_MOC_LITERAL(0, 0, 6), // "server"
QT_MOC_LITERAL(1, 7, 11), // "new_connect"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "readmessage"
QT_MOC_LITERAL(4, 32, 11), // "updateline1"
QT_MOC_LITERAL(5, 44, 11), // "updateline2"
QT_MOC_LITERAL(6, 56, 11), // "updateline3"
QT_MOC_LITERAL(7, 68, 11), // "updateline4"
QT_MOC_LITERAL(8, 80, 10), // "switchmode"
QT_MOC_LITERAL(9, 91, 8), // "switch4G"
QT_MOC_LITERAL(10, 100, 7), // "testTDS"
QT_MOC_LITERAL(11, 108, 7), // "testTEM"
QT_MOC_LITERAL(12, 116, 6), // "testTU"
QT_MOC_LITERAL(13, 123, 6), // "testPH"
QT_MOC_LITERAL(14, 130, 5) // "start"

    },
    "server\0new_connect\0\0readmessage\0"
    "updateline1\0updateline2\0updateline3\0"
    "updateline4\0switchmode\0switch4G\0testTDS\0"
    "testTEM\0testTU\0testPH\0start"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_server[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06 /* Public */,
       3,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       5,    1,   90,    2, 0x06 /* Public */,
       6,    1,   93,    2, 0x06 /* Public */,
       7,    1,   96,    2, 0x06 /* Public */,
       8,    0,   99,    2, 0x06 /* Public */,
       9,    0,  100,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  101,    2, 0x0a /* Public */,
      11,    0,  102,    2, 0x0a /* Public */,
      12,    0,  103,    2, 0x0a /* Public */,
      13,    0,  104,    2, 0x0a /* Public */,
      14,    0,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<server *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->new_connect((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 1: _t->readmessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updateline1((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->updateline2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->updateline3((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->updateline4((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->switchmode(); break;
        case 7: _t->switch4G(); break;
        case 8: _t->testTDS(); break;
        case 9: _t->testTEM(); break;
        case 10: _t->testTU(); break;
        case 11: _t->testPH(); break;
        case 12: _t->start(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (server::*)(QString , quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&server::new_connect)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (server::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&server::readmessage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (server::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&server::updateline1)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (server::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&server::updateline2)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (server::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&server::updateline3)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (server::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&server::updateline4)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (server::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&server::switchmode)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (server::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&server::switch4G)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject server::staticMetaObject = { {
    &QTcpServer::staticMetaObject,
    qt_meta_stringdata_server.data,
    qt_meta_data_server,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *server::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_server.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void server::new_connect(QString _t1, quint16 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void server::readmessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void server::updateline1(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void server::updateline2(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void server::updateline3(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void server::updateline4(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void server::switchmode()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void server::switch4G()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
