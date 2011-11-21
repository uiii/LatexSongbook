/****************************************************************************
** Meta object code from reading C++ file 'instrumentsettings.h'
**
** Created: Wed Aug 31 11:58:13 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../latexsongbook-gui/instrumentsettings.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'instrumentsettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_InstrumentSettings[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,
      41,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   19,   19,   19, 0x08,
      73,   19,   19,   19, 0x08,
      88,   19,   19,   19, 0x08,
     108,   19,   19,   19, 0x08,
     120,   19,   19,   19, 0x08,
     133,   19,   19,   19, 0x08,
     147,   19,   19,   19, 0x08,
     187,   19,   19,   19, 0x08,
     201,   19,   19,   19, 0x08,
     214,   19,  209,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_InstrumentSettings[] = {
    "InstrumentSettings\0\0imageLoaded(QString)\0"
    "saved()\0instrumentChanged_(int)\0"
    "browseImage_()\0chordsDefChanged_()\0"
    "clearAll_()\0enableAll_()\0disableAll_()\0"
    "controlButtonClicked_(QAbstractButton*)\0"
    "setUnsaved_()\0save_()\0bool\0maybeSave_()\0"
};

const QMetaObject InstrumentSettings::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_InstrumentSettings,
      qt_meta_data_InstrumentSettings, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &InstrumentSettings::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *InstrumentSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *InstrumentSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InstrumentSettings))
        return static_cast<void*>(const_cast< InstrumentSettings*>(this));
    return QWidget::qt_metacast(_clname);
}

int InstrumentSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: imageLoaded((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: saved(); break;
        case 2: instrumentChanged_((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: browseImage_(); break;
        case 4: chordsDefChanged_(); break;
        case 5: clearAll_(); break;
        case 6: enableAll_(); break;
        case 7: disableAll_(); break;
        case 8: controlButtonClicked_((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 9: setUnsaved_(); break;
        case 10: save_(); break;
        case 11: { bool _r = maybeSave_();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void InstrumentSettings::imageLoaded(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void InstrumentSettings::saved()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
