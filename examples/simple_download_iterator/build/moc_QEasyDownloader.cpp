/****************************************************************************
** Meta object code from reading C++ file 'QEasyDownloader.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/QEasyDownloader.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QEasyDownloader.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QEasyDownloader_t {
    QByteArrayData data[30];
    char stringdata0[334];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QEasyDownloader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QEasyDownloader_t qt_meta_stringdata_QEasyDownloader = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QEasyDownloader"
QT_MOC_LITERAL(1, 16, 8), // "Finished"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "Debugger"
QT_MOC_LITERAL(4, 35, 6), // "Paused"
QT_MOC_LITERAL(5, 42, 7), // "Resumed"
QT_MOC_LITERAL(6, 50, 16), // "DownloadFinished"
QT_MOC_LITERAL(7, 67, 16), // "DownloadProgress"
QT_MOC_LITERAL(8, 84, 5), // "Error"
QT_MOC_LITERAL(9, 90, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(10, 118, 9), // "errorCode"
QT_MOC_LITERAL(11, 128, 3), // "url"
QT_MOC_LITERAL(12, 132, 8), // "fileName"
QT_MOC_LITERAL(13, 141, 7), // "Timeout"
QT_MOC_LITERAL(14, 149, 8), // "download"
QT_MOC_LITERAL(15, 158, 9), // "checkHead"
QT_MOC_LITERAL(16, 168, 8), // "finished"
QT_MOC_LITERAL(17, 177, 16), // "downloadProgress"
QT_MOC_LITERAL(18, 194, 17), // "startNextDownload"
QT_MOC_LITERAL(19, 212, 5), // "retry"
QT_MOC_LITERAL(20, 218, 43), // "QNetworkAccessManager::Networ..."
QT_MOC_LITERAL(21, 262, 5), // "error"
QT_MOC_LITERAL(22, 268, 10), // "printDebug"
QT_MOC_LITERAL(23, 279, 7), // "timeout"
QT_MOC_LITERAL(24, 287, 12), // "saveFileName"
QT_MOC_LITERAL(25, 300, 8), // "Download"
QT_MOC_LITERAL(26, 309, 5), // "Pause"
QT_MOC_LITERAL(27, 315, 6), // "Resume"
QT_MOC_LITERAL(28, 322, 6), // "IsNext"
QT_MOC_LITERAL(29, 329, 4) // "Next"

    },
    "QEasyDownloader\0Finished\0\0Debugger\0"
    "Paused\0Resumed\0DownloadFinished\0"
    "DownloadProgress\0Error\0"
    "QNetworkReply::NetworkError\0errorCode\0"
    "url\0fileName\0Timeout\0download\0checkHead\0"
    "finished\0downloadProgress\0startNextDownload\0"
    "retry\0QNetworkAccessManager::NetworkAccessibility\0"
    "error\0printDebug\0timeout\0saveFileName\0"
    "Download\0Pause\0Resume\0IsNext\0Next"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QEasyDownloader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  134,    2, 0x06 /* Public */,
       3,    1,  135,    2, 0x06 /* Public */,
       4,    2,  138,    2, 0x06 /* Public */,
       5,    2,  143,    2, 0x06 /* Public */,
       6,    2,  148,    2, 0x06 /* Public */,
       7,    7,  153,    2, 0x06 /* Public */,
       8,    3,  168,    2, 0x06 /* Public */,
      13,    2,  175,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  180,    2, 0x08 /* Private */,
      15,    2,  181,    2, 0x08 /* Private */,
      16,    0,  186,    2, 0x08 /* Private */,
      17,    2,  187,    2, 0x08 /* Private */,
      18,    0,  192,    2, 0x08 /* Private */,
      19,    1,  193,    2, 0x08 /* Private */,
      21,    1,  196,    2, 0x08 /* Private */,
      22,    1,  199,    2, 0x08 /* Private */,
      23,    0,  202,    2, 0x08 /* Private */,
      24,    1,  203,    2, 0x08 /* Private */,
      25,    2,  206,    2, 0x0a /* Public */,
      25,    1,  211,    2, 0x0a /* Public */,
      26,    0,  214,    2, 0x0a /* Public */,
      27,    0,  215,    2, 0x0a /* Public */,
      28,    0,  216,    2, 0x0a /* Public */,
      29,    0,  217,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QUrl, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QUrl, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QUrl, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, QMetaType::Int, QMetaType::Double, QMetaType::QString, QMetaType::QUrl, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QUrl, QMetaType::QString,   10,   11,   12,
    QMetaType::Void, QMetaType::QUrl, QMetaType::QString,   11,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    2,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,

       0        // eod
};

void QEasyDownloader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QEasyDownloader *_t = static_cast<QEasyDownloader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Finished(); break;
        case 1: _t->Debugger((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->Paused((*reinterpret_cast< const QUrl(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->Resumed((*reinterpret_cast< const QUrl(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->DownloadFinished((*reinterpret_cast< const QUrl(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->DownloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QUrl(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7]))); break;
        case 6: _t->Error((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1])),(*reinterpret_cast< const QUrl(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 7: _t->Timeout((*reinterpret_cast< const QUrl(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->download(); break;
        case 9: _t->checkHead((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 10: _t->finished(); break;
        case 11: _t->downloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 12: _t->startNextDownload(); break;
        case 13: _t->retry((*reinterpret_cast< QNetworkAccessManager::NetworkAccessibility(*)>(_a[1]))); break;
        case 14: _t->error((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 15: _t->printDebug((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->timeout(); break;
        case 17: { QString _r = _t->saveFileName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 18: _t->Download((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 19: _t->Download((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->Pause(); break;
        case 21: _t->Resume(); break;
        case 22: { bool _r = _t->IsNext();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 23: _t->Next(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QEasyDownloader::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEasyDownloader::Finished)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QEasyDownloader::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEasyDownloader::Debugger)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QEasyDownloader::*_t)(const QUrl & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEasyDownloader::Paused)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QEasyDownloader::*_t)(const QUrl & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEasyDownloader::Resumed)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (QEasyDownloader::*_t)(const QUrl & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEasyDownloader::DownloadFinished)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (QEasyDownloader::*_t)(qint64 , qint64 , int , double , const QString & , const QUrl & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEasyDownloader::DownloadProgress)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (QEasyDownloader::*_t)(QNetworkReply::NetworkError , const QUrl & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEasyDownloader::Error)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (QEasyDownloader::*_t)(const QUrl & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEasyDownloader::Timeout)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QEasyDownloader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QEasyDownloader.data,
      qt_meta_data_QEasyDownloader,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QEasyDownloader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QEasyDownloader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QEasyDownloader.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QEasyDownloader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void QEasyDownloader::Finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QEasyDownloader::Debugger(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QEasyDownloader::Paused(const QUrl & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QEasyDownloader::Resumed(const QUrl & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QEasyDownloader::DownloadFinished(const QUrl & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QEasyDownloader::DownloadProgress(qint64 _t1, qint64 _t2, int _t3, double _t4, const QString & _t5, const QUrl & _t6, const QString & _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QEasyDownloader::Error(QNetworkReply::NetworkError _t1, const QUrl & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QEasyDownloader::Timeout(const QUrl & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
