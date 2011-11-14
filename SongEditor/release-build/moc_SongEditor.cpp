/****************************************************************************
** Meta object code from reading C++ file 'SongEditor.hpp'
**
** Created: Sun Nov 13 12:26:30 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SongEditor/SongEditor.hpp"
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
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      31,   22,   11,   11, 0x0a,
      49,   11,   11,   11, 0x2a,
      60,   11,   11,   11, 0x0a,
      71,   22,   11,   11, 0x0a,
      91,   11,   11,   11, 0x2a,
     104,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SongEditor[] = {
    "SongEditor\0\0newSong()\0fileName\0"
    "openSong(QString)\0openSong()\0saveSong()\0"
    "saveAsSong(QString)\0saveAsSong()\0"
    "updateWindowTitle()\0"
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
        case 3: saveSong(); break;
        case 4: saveAsSong((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: saveAsSong(); break;
        case 6: updateWindowTitle(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
