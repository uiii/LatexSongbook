/****************************************************************************
** Meta object code from reading C++ file 'songbook.h'
**
** Created: Wed Aug 31 21:05:04 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../latexsongbook-gui/songbook.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'songbook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Songbook[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      27,    9,    9,    9, 0x05,
      42,    9,    9,    9, 0x05,
      58,    9,    9,    9, 0x05,
      85,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     104,    9,   99,    9, 0x0a,
     118,    9,    9,    9, 0x0a,
     142,  137,    9,    9, 0x0a,
     164,  137,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Songbook[] = {
    "Songbook\0\0unfiledChanged()\0filedChanged()\0"
    "eventsChanged()\0instrumentChanged(QString)\0"
    "sizeChanged()\0bool\0fileUnfiled()\0"
    "updateInstrument()\0size\0setPaperSize(QString)\0"
    "setFontSize(QString)\0"
};

const QMetaObject Songbook::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Songbook,
      qt_meta_data_Songbook, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Songbook::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Songbook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Songbook::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Songbook))
        return static_cast<void*>(const_cast< Songbook*>(this));
    return QObject::qt_metacast(_clname);
}

int Songbook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: unfiledChanged(); break;
        case 1: filedChanged(); break;
        case 2: eventsChanged(); break;
        case 3: instrumentChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: sizeChanged(); break;
        case 5: { bool _r = fileUnfiled();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: updateInstrument(); break;
        case 7: setPaperSize((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: setFontSize((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Songbook::unfiledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Songbook::filedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Songbook::eventsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Songbook::instrumentChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Songbook::sizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
