/****************************************************************************
** Meta object code from reading C++ file 'SongManager.h'
**
** Created: Wed Nov 16 21:45:56 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SongManager/SongManager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SongManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SongManager[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_SongManager[] = {
    "SongManager\0"
};

const QMetaObject SongManager::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SongManager,
      qt_meta_data_SongManager, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SongManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SongManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SongManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SongManager))
        return static_cast<void*>(const_cast< SongManager*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SongManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
