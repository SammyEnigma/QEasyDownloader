---
id: UsingDownloader
title: Simple Download with QEasyDownloader
sidebar_label: A Simple Downloader in QEasyDownloader
---

This is a basic downloader which downloads a demo video and saves it in the current working directory.

## main.cpp

```
#include <QCoreApplication>
#include "QEasyDownloader/QEasyDownloader.hpp"

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    /*
     * Construct
    */
    QEasyDownloader Downloader;

    /*
     * By Default Debug is false , make it true to print the download progress and
     * other stuff!
    */
    Downloader.Debug(true);

    QObject::connect(&Downloader, &QEasyDownloader::DownloadFinished,
    [&](QUrl Url, QString file) {
        qDebug() << "Downloaded :: " << file << " :: FROM :: " << Url;
        app.quit();
    });
    /*
     * Just Download!
    */
    Downloader.Download("http://sample-videos.com/video/mp4/720/big_buck_bunny_720p_5mb.mp4");
    return app.exec();
}
```

## simple_download.pro

```
TARGET = simple_download
TEMPLATE = app

QT += core network

SOURCES += main.cpp
HEADERS += QEasyDownloader/QEasyDownloader.hpp
```

## Compilation and Execution

```
 $ mkdir build
 $ cd build
 $ qmake ../simple_download.pro
 $ make -j4
 $ ./simple_download
 $ # now you will have big_buck_bunny_720p_5mb.mp4 saved
 $ # Try aborting the download and starting it again
```

This Program is created in the examples tree on the official repo.

