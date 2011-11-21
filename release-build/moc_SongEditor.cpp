/****************************************************************************
** Meta object code from reading C++ file 'SongEditor.hpp'
**
** Created: Sun Nov 20 16:29:19 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LatexSongbook/src/SongEditor.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SongEditor.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SongEditor[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      31,   22,   11,   11, 0x0a,
      49,   11,   11,   11, 0x2a,
      65,   11,   60,   11, 0x0a,
      76,   22,   60,   11, 0x0a,
      96,   11,   60,   11, 0x2a,
     114,  109,   11,   11, 0x0a,
     131,   11,   11,   11, 0x0a,
     149,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SongEditor[] = {
    "SongEditor\0\0newSong()\0fileName\0"
    "openSong(QString)\0openSong()\0bool\0"
    "saveSong()\0saveAsSong(QString)\0"
    "saveAsSong()\0flag\0setAsSaved(bool)\0"
    "updateSongState()\0updateWindowTitle()\0"
};

const QMetaObject SongEditor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SongEditor,
      qt_meta_data_SongEditor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SongEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SongEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SongEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SongEditor))
        return static_cast<void*>(const_cast< SongEditor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SongEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newSong(); break;
        case 1: openSong((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: openSong(); break;
        case 3: { bool _r = saveSong();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = saveAsSong((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = saveAsSong();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: setAsSaved((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: updateSongState(); break;
        case 8: updateWindowTitle(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
