/****************************************************************************
** Meta object code from reading C++ file 'fenetreprincipale.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Graphe/fenetreprincipale.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fenetreprincipale.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FenetrePrincipale_t {
    QByteArrayData data[17];
    char stringdata[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FenetrePrincipale_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FenetrePrincipale_t qt_meta_stringdata_FenetrePrincipale = {
    {
QT_MOC_LITERAL(0, 0, 17), // "FenetrePrincipale"
QT_MOC_LITERAL(1, 18, 13), // "sourisCliquee"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 10), // "parcourrir"
QT_MOC_LITERAL(4, 44, 8), // "executer"
QT_MOC_LITERAL(5, 53, 5), // "aProp"
QT_MOC_LITERAL(6, 59, 13), // "changementTab"
QT_MOC_LITERAL(7, 73, 1), // "i"
QT_MOC_LITERAL(8, 75, 8), // "bipartie"
QT_MOC_LITERAL(9, 84, 8), // "gloutonC"
QT_MOC_LITERAL(10, 93, 10), // "gloutonMCP"
QT_MOC_LITERAL(11, 104, 14), // "gloutonMCPReel"
QT_MOC_LITERAL(12, 119, 8), // "nouveauG"
QT_MOC_LITERAL(13, 128, 11), // "coloration5"
QT_MOC_LITERAL(14, 140, 24), // "reinitialiserLesCouleurs"
QT_MOC_LITERAL(15, 165, 12), // "recuitSimule"
QT_MOC_LITERAL(16, 178, 15) // "ordreSimplicial"

    },
    "FenetrePrincipale\0sourisCliquee\0\0"
    "parcourrir\0executer\0aProp\0changementTab\0"
    "i\0bipartie\0gloutonC\0gloutonMCP\0"
    "gloutonMCPReel\0nouveauG\0coloration5\0"
    "reinitialiserLesCouleurs\0recuitSimule\0"
    "ordreSimplicial"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FenetrePrincipale[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    1,   88,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    0,   97,    2, 0x08 /* Private */,
      15,    0,   98,    2, 0x08 /* Private */,
      16,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FenetrePrincipale::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FenetrePrincipale *_t = static_cast<FenetrePrincipale *>(_o);
        switch (_id) {
        case 0: _t->sourisCliquee(); break;
        case 1: _t->parcourrir(); break;
        case 2: _t->executer(); break;
        case 3: _t->aProp(); break;
        case 4: _t->changementTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->bipartie(); break;
        case 6: _t->gloutonC(); break;
        case 7: _t->gloutonMCP(); break;
        case 8: _t->gloutonMCPReel(); break;
        case 9: _t->nouveauG(); break;
        case 10: _t->coloration5(); break;
        case 11: _t->reinitialiserLesCouleurs(); break;
        case 12: _t->recuitSimule(); break;
        case 13: _t->ordreSimplicial(); break;
        default: ;
        }
    }
}

const QMetaObject FenetrePrincipale::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FenetrePrincipale.data,
      qt_meta_data_FenetrePrincipale,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FenetrePrincipale::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FenetrePrincipale::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FenetrePrincipale.stringdata))
        return static_cast<void*>(const_cast< FenetrePrincipale*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FenetrePrincipale::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
