<p align="center">
  <img src=".img/poster.png" height="350px" width=auto alt="QEasyDownloader Poster">  <br>
</p>

# QEasyDownloader [![GitHub issues](https://img.shields.io/github/issues/antony-jr/QEasyDownloader.svg?style=flat-square)](https://github.com/antony-jr/QEasyDownloader/issues) [![GitHub forks](https://img.shields.io/github/forks/antony-jr/QEasyDownloader.svg?style=flat-square)](https://github.com/antony-jr/QEasyDownloader/network) [![GitHub stars](https://img.shields.io/github/stars/antony-jr/QEasyDownloader.svg?style=flat-square)](https://github.com/antony-jr/QEasyDownloader/stargazers) [![GitHub license](https://img.shields.io/github/license/antony-jr/QEasyDownloader.svg?style=flat-square)](https://github.com/antony-jr/QEasyDownloader/blob/master/LICENSE) [![Codacy Badge](https://api.codacy.com/project/badge/Grade/6f7381a508c14a6a91b1f77b375f080d)](https://www.codacy.com/app/antony-jr/QEasyDownloader?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=antony-jr/QEasyDownloader&amp;utm_campaign=Badge_Grade)

Have you ever choked on the **QNetworkAccessManager** to download **large files and also resume downloads   
automatically** ? I did , So thats why I created this small header file which made my day easier and so I   
think it will make yours too. :heart: This small header contains the **QEasyDownloader** class which   
downloads files that you queue and also automatically resumes the downloads (**Partial Download** ?).   
**QEasyDownloader** also handles **network interruptions** automatically! :dog: And the best part is ,   
**its just a header!** :cat:

### Features
* In-Built Download Queue support :heart:
* Automatically Resumes Downloads , can be disabled if the user wants to! :dog:
* Automatically handles **Network Interruptions**. :cat:
* **Pause** and **Resume** Downloads like a charm. :rocket:
* Resource manipulation , **Use your own QNetworkAccessManager** too. :sunglasses:

# Usage
```
#include <QCoreApplication>
#include "QEasyDownloader.hpp"

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
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
    Downloader.Download("http://www.divineimagination.com/gallery/movie/roving_web.wmv");
    return app.exec();
}
```

Refer the **Class Anatomy** for more information on the **QEasyDownloader** class , [QEasyDownloader Class Anatomy](#class-anatomy)

# Installation

```
 $ wget "https://github.com/antony-jr/QEasyDownloader/releases/download/v0.0.1/QEasyDownloader.hpp"
 $ # Thats it , You just have to download the header
```

**Just add the header file to your qt project file (.pro) and include the header in your source files!**   
Take a look at the examples in the **examples** directory of this repo.

# Class Anatomy

**QEasyDownloader** is the main class that handles downloads like a pro , it is **inherited from QObject**.

### Constructors

| QEasyDownloader(QObject *parent = NULL , QNetworkAccessManager *toUseManager = NULL); | Assigns a parent if the user gives one and assigns a QNetworkAccessManager if the user already uses a single NetworkManager for his/her application. |
|---------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------|   

### Methods

**Warning:** Disabling Resuming of Downloads will **overwrite the file if found!**

| void ResumeDownloads(bool); 	| Enable or Disable Resuming of Downloads!                                       	|
|-----------------------------	|--------------------------------------------------------------------------------	|
| void Debug(bool);           	| Enable or Disable Debuging                                                     	|
| void setTimeoutTime(int);   	| sets the timeout time (in miliseconds) for a request! default is 5000 = 5 secs 	|
| void setRetryTime(int)      	| sets the retry time (in miliseconds) for a request! default is 6000 = 6 secs   	|

### Slots

| void Download(const QString& , const QString&); 	| Download a file and save it in the location provided. 	|
|-------------------------------------------------	|-------------------------------------------------------	|
| void Download(const QString&);                  	| Simply download a file.                               	|
| void Pause();                                   	| Pause the current download.                           	|
| void Resume();                                  	| Resume any paused download.                           	|

### Signals

| void Finished() 	| Emitted when all jobs are done. 	|
|------------------------------------------------------------------------------------------------------------------------------------------------------------	|-----------------------------------------------------	|
| void DownloadFinished(const QUrl &url, const QString& fileName) 	| Emitted when a single file is downloaded. 	|
| void DownloadProgress(qint64 bytesReceived, qint64 bytesTotal, int percent, double speed, const QString &unit,  const QUrl &url,  const QString &fileName) 	| Full Download Progress , Emitted on every download. 	|
| void Error(QNetworkReply::NetworkError errorCode, const QUrl &url, const QString &fileName) 	| Emitted on error. 	|
| void Timeout(const QUrl &url, const QString &fileName) 	| Emitted when there is a timeout. 	|  



# Deploying your apps

I really recommend you all to use dynamic linking on all platforms and then pack it with simple containers this way you can   
avoid the overhead of static compiling and also make it just work! :dog:

In windows you can simply throw in the dll files and compress it into a setup file and distribute it to the users but its   
different in linux , refer this [Qt Doc](http://doc.qt.io/qt-5/linux-deployment.html) for information on deploying qt apps.   

In addition you can use [AppImages](https://github.com/appImage/appimagekit) and [linuxdeployqt](https://github.com/probonopd/linuxdeployqt).

# Thank You ![Thank You](https://img.shields.io/badge/Always-Say%20Thank%20You!-blue.svg?style=flat-square)

I really need to thank the developers of this libraries for creating it because QEasyDownloader is elegant because of them! :heart:   

* [Qt](https://github.com/qt)


# Support [![Liberapay](https://liberapay.com/assets/widgets/donate.svg)](https://liberapay.com/antonyjr/donate) [![Twitter](https://img.shields.io/twitter/url/https/github.com/antony-jr/QEasyDownloader.svg?style=social)](https://twitter.com/intent/tweet?text=Checkout%20%23QEasyDownloader%20by%20%40antonyjr0%20%20%2C%20its%20cool.%20Try%20it%20at%20https%3A%2F%2Fgithub.com%2Fantony-jr%2FQEasyDownloader)

If you think that this project is **cool** then you can give it a :star: or :fork_and_knife: it if you want to improve it with me. I really :heart: stars though!   

<p align="center">
    <a href="https://liberapay.com/antonyjr/donate">
       <img src="https://liberapay.com/assets/widgets/donate.svg">
    </a>
</p>


If you want to do something that stands out then you can click the **donate** button at the top to make a monthly donation , So   
I will make sure that I stay healthy and keep on to do my work. :briefcase: Supporting me means supporting all of my projects , So   
you are like **Tony Stark** :heart: who backs **Spider-Man**! Thank you for your extra care! :dog:   

You can also tweet about me on twitter , get connected with me [@antonyjr0](https://twitter.com/antonyjr0)

Thank You! :smiley_cat:

# License

The BSD 3-clause "New" or "Revised" License.

Copyright (C) 2017 , antony jr.   
All Rights Reserved.
