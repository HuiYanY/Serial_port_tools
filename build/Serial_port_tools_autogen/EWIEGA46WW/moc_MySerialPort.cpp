/****************************************************************************
** Meta object code from reading C++ file 'MySerialPort.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MySerialPort.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MySerialPort.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MySerialPort_t {
    QByteArrayData data[18];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MySerialPort_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MySerialPort_t qt_meta_stringdata_MySerialPort = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MySerialPort"
QT_MOC_LITERAL(1, 13, 14), // "openSerialPort"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "portName"
QT_MOC_LITERAL(4, 38, 21), // "QSerialPort::BaudRate"
QT_MOC_LITERAL(5, 60, 8), // "bandRate"
QT_MOC_LITERAL(6, 69, 21), // "QSerialPort::DataBits"
QT_MOC_LITERAL(7, 91, 7), // "dataBit"
QT_MOC_LITERAL(8, 99, 19), // "QSerialPort::Parity"
QT_MOC_LITERAL(9, 119, 6), // "parity"
QT_MOC_LITERAL(10, 126, 21), // "QSerialPort::StopBits"
QT_MOC_LITERAL(11, 148, 7), // "stopBit"
QT_MOC_LITERAL(12, 156, 18), // "serialPort_Receive"
QT_MOC_LITERAL(13, 175, 15), // "QPlainTextEdit*"
QT_MOC_LITERAL(14, 191, 13), // "plainTextEdit"
QT_MOC_LITERAL(15, 205, 6), // "isTime"
QT_MOC_LITERAL(16, 212, 5), // "isHex"
QT_MOC_LITERAL(17, 218, 10) // "isLineFeed"

    },
    "MySerialPort\0openSerialPort\0\0portName\0"
    "QSerialPort::BaudRate\0bandRate\0"
    "QSerialPort::DataBits\0dataBit\0"
    "QSerialPort::Parity\0parity\0"
    "QSerialPort::StopBits\0stopBit\0"
    "serialPort_Receive\0QPlainTextEdit*\0"
    "plainTextEdit\0isTime\0isHex\0isLineFeed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MySerialPort[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    5,   24,    2, 0x0a /* Public */,
      12,    4,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 8, 0x80000000 | 10,    3,    5,    7,    9,   11,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   14,   15,   16,   17,

       0        // eod
};

void MySerialPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MySerialPort *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openSerialPort((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QSerialPort::BaudRate(*)>(_a[2])),(*reinterpret_cast< QSerialPort::DataBits(*)>(_a[3])),(*reinterpret_cast< QSerialPort::Parity(*)>(_a[4])),(*reinterpret_cast< QSerialPort::StopBits(*)>(_a[5]))); break;
        case 1: _t->serialPort_Receive((*reinterpret_cast< QPlainTextEdit*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QPlainTextEdit* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MySerialPort::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MySerialPort.data,
    qt_meta_data_MySerialPort,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MySerialPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MySerialPort::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MySerialPort.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MySerialPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
