/****************************************************************************
** Meta object code from reading C++ file 'cryptocontroller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Lab_2/cryptocontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cryptocontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cryptoController_t {
    const uint offsetsAndSize[34];
    char stringdata0[225];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_cryptoController_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_cryptoController_t qt_meta_stringdata_cryptoController = {
    {
QT_MOC_LITERAL(0, 16), // "cryptoController"
QT_MOC_LITERAL(17, 11), // "sendDbToQml"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 12), // "db_decrypted"
QT_MOC_LITERAL(43, 16), // "sendMessageToQml"
QT_MOC_LITERAL(60, 7), // "message"
QT_MOC_LITERAL(68, 14), // "check_password"
QT_MOC_LITERAL(83, 8), // "password"
QT_MOC_LITERAL(92, 17), // "text_to_clipboard"
QT_MOC_LITERAL(110, 4), // "text"
QT_MOC_LITERAL(115, 3), // "pin"
QT_MOC_LITERAL(119, 15), // "decrypt_db_file"
QT_MOC_LITERAL(135, 9), // "record_id"
QT_MOC_LITERAL(145, 11), // "is_password"
QT_MOC_LITERAL(157, 15), // "encrypt_db_file"
QT_MOC_LITERAL(173, 25), // "decrypt_login_or_password"
QT_MOC_LITERAL(199, 25) // "encrypt_login_or_password"

    },
    "cryptoController\0sendDbToQml\0\0"
    "db_decrypted\0sendMessageToQml\0message\0"
    "check_password\0password\0text_to_clipboard\0"
    "text\0pin\0decrypt_db_file\0record_id\0"
    "is_password\0encrypt_db_file\0"
    "decrypt_login_or_password\0"
    "encrypt_login_or_password"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cryptoController[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   86,    2, 0x06,    1 /* Public */,
       4,    1,   89,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   92,    2, 0x0a,    5 /* Public */,
       8,    2,   95,    2, 0x0a,    7 /* Public */,
      11,    3,  100,    2, 0x0a,   10 /* Public */,
      11,    2,  107,    2, 0x2a,   14 /* Public | MethodCloned */,
      11,    1,  112,    2, 0x2a,   17 /* Public | MethodCloned */,
      14,    3,  115,    2, 0x0a,   19 /* Public */,
      14,    2,  122,    2, 0x2a,   23 /* Public | MethodCloned */,
      14,    1,  127,    2, 0x2a,   26 /* Public | MethodCloned */,
      15,    2,  130,    2, 0x0a,   28 /* Public */,
      16,    1,  135,    2, 0x0a,   31 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    7,   12,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    7,   12,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    7,   12,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    7,   12,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,    7,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void cryptoController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<cryptoController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendDbToQml((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->sendMessageToQml((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: { bool _r = _t->check_password((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->text_to_clipboard((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->decrypt_db_file((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 5: _t->decrypt_db_file((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 6: _t->decrypt_db_file((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->encrypt_db_file((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 8: _t->encrypt_db_file((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 9: _t->encrypt_db_file((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: { QString _r = _t->decrypt_login_or_password((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->encrypt_login_or_password((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (cryptoController::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cryptoController::sendDbToQml)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (cryptoController::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cryptoController::sendMessageToQml)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject cryptoController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_cryptoController.offsetsAndSize,
    qt_meta_data_cryptoController,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_cryptoController_t
, QtPrivate::TypeAndForceComplete<cryptoController, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *cryptoController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cryptoController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cryptoController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cryptoController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void cryptoController::sendDbToQml(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void cryptoController::sendMessageToQml(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
