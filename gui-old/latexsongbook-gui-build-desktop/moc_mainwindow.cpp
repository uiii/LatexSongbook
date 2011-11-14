/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Nov 12 15:29:16 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../latexsongbook-gui/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      26,   11,   11,   11, 0x0a,
      41,   11,   11,   11, 0x0a,
      56,   11,   11,   11, 0x0a,
      73,   11,   11,   11, 0x0a,
      83,   11,   11,   11, 0x0a,
     107,   97,   11,   11, 0x0a,
     149,   11,   11,   11, 0x0a,
     161,   11,   11,   11, 0x0a,
     176,   11,   11,   11, 0x0a,
     189,   11,   11,   11, 0x0a,
     208,   11,  203,   11, 0x08,
     221,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0newSongbook()\0loadSongbook()\0"
    "saveSongbook()\0saveAsSongbook()\0"
    "addSong()\0fileUnfiled()\0selected,\0"
    "changeTime(QItemSelection,QItemSelection)\0"
    "selectNow()\0setAsUnsaved()\0setAsSaved()\0"
    "updateTitle()\0bool\0maybeSave_()\0"
    "setRecommendedFontSize_(int)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newSongbook(); break;
        case 1: loadSongbook(); break;
        case 2: saveSongbook(); break;
        case 3: saveAsSongbook(); break;
        case 4: addSong(); break;
        case 5: fileUnfiled(); break;
        case 6: changeTime((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 7: selectNow(); break;
        case 8: setAsUnsaved(); break;
        case 9: setAsSaved(); break;
        case 10: updateTitle(); break;
        case 11: { bool _r = maybeSave_();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: setRecommendedFontSize_((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
