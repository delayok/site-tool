/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileProcessWorker_t {
    QByteArrayData data[17];
    char stringdata0[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileProcessWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileProcessWorker_t qt_meta_stringdata_FileProcessWorker = {
    {
QT_MOC_LITERAL(0, 0, 17), // "FileProcessWorker"
QT_MOC_LITERAL(1, 18, 15), // "progressChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 5), // "value"
QT_MOC_LITERAL(4, 41, 13), // "statusMessage"
QT_MOC_LITERAL(5, 55, 7), // "message"
QT_MOC_LITERAL(6, 63, 10), // "logMessage"
QT_MOC_LITERAL(7, 74, 8), // "finished"
QT_MOC_LITERAL(8, 83, 13), // "errorOccurred"
QT_MOC_LITERAL(9, 97, 5), // "error"
QT_MOC_LITERAL(10, 103, 12), // "processFiles"
QT_MOC_LITERAL(11, 116, 10), // "sourcePath"
QT_MOC_LITERAL(12, 127, 10), // "targetPath"
QT_MOC_LITERAL(13, 138, 14), // "useBracketRule"
QT_MOC_LITERAL(14, 153, 15), // "useFileNameRule"
QT_MOC_LITERAL(15, 169, 11), // "useTimeRule"
QT_MOC_LITERAL(16, 181, 14) // "overwriteFiles"

    },
    "FileProcessWorker\0progressChanged\0\0"
    "value\0statusMessage\0message\0logMessage\0"
    "finished\0errorOccurred\0error\0processFiles\0"
    "sourcePath\0targetPath\0useBracketRule\0"
    "useFileNameRule\0useTimeRule\0overwriteFiles"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileProcessWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,
       7,    0,   53,    2, 0x06 /* Public */,
       8,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    6,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   11,   12,   13,   14,   15,   16,

       0        // eod
};

void FileProcessWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileProcessWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->progressChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->statusMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->logMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->finished(); break;
        case 4: _t->errorOccurred((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->processFiles((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FileProcessWorker::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileProcessWorker::progressChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FileProcessWorker::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileProcessWorker::statusMessage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FileProcessWorker::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileProcessWorker::logMessage)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FileProcessWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileProcessWorker::finished)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FileProcessWorker::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileProcessWorker::errorOccurred)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileProcessWorker::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_FileProcessWorker.data,
    qt_meta_data_FileProcessWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FileProcessWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileProcessWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileProcessWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FileProcessWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void FileProcessWorker::progressChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileProcessWorker::statusMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FileProcessWorker::logMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FileProcessWorker::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void FileProcessWorker::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[354];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 33), // "on_pushButtonBrowseSource_cli..."
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 33), // "on_pushButtonBrowseTarget_cli..."
QT_MOC_LITERAL(4, 80, 26), // "on_pushButtonStart_clicked"
QT_MOC_LITERAL(5, 107, 25), // "on_pushButtonStop_clicked"
QT_MOC_LITERAL(6, 133, 29), // "on_pushButtonClearLog_clicked"
QT_MOC_LITERAL(7, 163, 25), // "on_pushButtonExit_clicked"
QT_MOC_LITERAL(8, 189, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(9, 213, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(10, 238, 23), // "onWorkerProgressChanged"
QT_MOC_LITERAL(11, 262, 5), // "value"
QT_MOC_LITERAL(12, 268, 21), // "onWorkerStatusMessage"
QT_MOC_LITERAL(13, 290, 7), // "message"
QT_MOC_LITERAL(14, 298, 18), // "onWorkerLogMessage"
QT_MOC_LITERAL(15, 317, 16), // "onWorkerFinished"
QT_MOC_LITERAL(16, 334, 13), // "onWorkerError"
QT_MOC_LITERAL(17, 348, 5) // "error"

    },
    "MainWindow\0on_pushButtonBrowseSource_clicked\0"
    "\0on_pushButtonBrowseTarget_clicked\0"
    "on_pushButtonStart_clicked\0"
    "on_pushButtonStop_clicked\0"
    "on_pushButtonClearLog_clicked\0"
    "on_pushButtonExit_clicked\0"
    "on_actionExit_triggered\0"
    "on_actionAbout_triggered\0"
    "onWorkerProgressChanged\0value\0"
    "onWorkerStatusMessage\0message\0"
    "onWorkerLogMessage\0onWorkerFinished\0"
    "onWorkerError\0error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    1,   87,    2, 0x08 /* Private */,
      12,    1,   90,    2, 0x08 /* Private */,
      14,    1,   93,    2, 0x08 /* Private */,
      15,    0,   96,    2, 0x08 /* Private */,
      16,    1,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButtonBrowseSource_clicked(); break;
        case 1: _t->on_pushButtonBrowseTarget_clicked(); break;
        case 2: _t->on_pushButtonStart_clicked(); break;
        case 3: _t->on_pushButtonStop_clicked(); break;
        case 4: _t->on_pushButtonClearLog_clicked(); break;
        case 5: _t->on_pushButtonExit_clicked(); break;
        case 6: _t->on_actionExit_triggered(); break;
        case 7: _t->on_actionAbout_triggered(); break;
        case 8: _t->onWorkerProgressChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->onWorkerStatusMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->onWorkerLogMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->onWorkerFinished(); break;
        case 12: _t->onWorkerError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
