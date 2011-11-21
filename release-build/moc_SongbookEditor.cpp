/****************************************************************************
** Meta object code from reading C++ file 'SongbookEditor.hpp'
**
** Created: Sun Nov 20 16:29:19 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LatexSongbook/src/SongbookEditor.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SongbookEditor.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SongbookEditor[] = {

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
      16,   15,   15,   15, 0x0a,
      39,   30,   15,   15, 0x0a,
      61,   15,   15,   15, 0x2a,
      81,   15,   76,   15, 0x0a,
      96,   30,   76,   15, 0x0a,
     120,   15,   76,   15, 0x2a,
     142,  137,   15,   15, 0x0a,
     159,   15,   15,   15, 0x0a,
     181,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SongbookEditor[] = {
    "SongbookEditor\0\0newSongbook()\0fileName\0"
    "openSongbook(QString)\0openSongbook()\0"
    "bool\0saveSongbook()\0saveAsSongbook(QString)\0"
    "saveAsSongbook()\0flag\0setAsSaved(bool)\0"
    "updateSongbookState()\0updateWindowTitle()\0"
};

const QMetaObject SongbookEditor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SongbookEditor,
      qt_meta_data_SongbookEditor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SongbookEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SongbookEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SongbookEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SongbookEditor))
        return static_cast<void*>(const_cast< SongbookEditor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SongbookEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newSongbook(); break;
        case 1: openSongbook((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: openSongbook(); break;
        case 3: { bool _r = saveSongbook();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = saveAsSongbook((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = saveAsSongbook();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: setAsSaved((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: updateSongbookState(); break;
        case 8: updateWindowTitle(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
