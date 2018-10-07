/****************************************************************************
** Meta object code from reading C++ file 'detecteurdesommet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Graphe/detecteurdesommet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'detecteurdesommet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DetecteurDeSommet_t {
    QByteArrayData data[5];
    char stringdata[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DetecteurDeSommet_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DetecteurDeSommet_t qt_meta_stringdata_DetecteurDeSommet = {
    {
QT_MOC_LITERAL(0, 0, 17), // "DetecteurDeSommet"
QT_MOC_LITERAL(1, 18, 13), // "sourisCliquee"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 12), // "sourisPartie"
QT_MOC_LITERAL(4, 46, 14) // "sourisCliqueee"

    },
    "DetecteurDeSommet\0sourisCliquee\0\0"
    "sourisPartie\0sourisCliqueee"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DetecteurDeSommet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   31,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void DetecteurDeSommet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DetecteurDeSommet *_t = static_cast<DetecteurDeSommet *>(_o);
        switch (_id) {
        case 0: _t->sourisCliquee(); break;
        case 1: _t->sourisPartie(); break;
        case 2: _t->sourisCliqueee(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DetecteurDeSommet::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DetecteurDeSommet::sourisCliquee)) {
                *result = 0;
            }
        }
        {
            typedef void (DetecteurDeSommet::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DetecteurDeSommet::sourisPartie)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DetecteurDeSommet::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DetecteurDeSommet.data,
      qt_meta_data_DetecteurDeSommet,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DetecteurDeSommet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DetecteurDeSommet::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DetecteurDeSommet.stringdata))
        return static_cast<void*>(const_cast< DetecteurDeSommet*>(this));
    return QWidget::qt_metacast(_clname);
}

int DetecteurDeSommet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DetecteurDeSommet::sourisCliquee()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void DetecteurDeSommet::sourisPartie()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
