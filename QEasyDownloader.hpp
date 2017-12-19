/*
 * BSD 3-Clause License
 *
 * Copyright (c) 2017, Antony jr
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * -----------------------------------------------------------------------------
 *  @filename 	 	: QEasyDownloader.hpp
 *  @description 	: A Simple and Powerful Downloader Header writen in C++   
 *  			  with Qt5. This small header helps you Download and   
 *  			  Resume Downloads Elegantly , Only for HTTP.
 * -----------------------------------------------------------------------------
*/
#if !defined(QEASY_DOWNLOADER_HPP_INCLUDED)
#define QEASY_DOWNLOADER_HPP_INCLUDED
#include <QtCore>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>


/*
 * Class QEasyDownloader <- Inherits QObject
 * --------------------
 *
 *  The main class that handles downloads like a pro.
 *
 *  Constructors:
 *	QEasyDownloader(QObject *parent = NULL);
 *  	QEasyDownloader(QObject *parent = NULL , QNetworkManager *toUseManager);
 *
 *  Methods:
 *  	void Debug();
 *  	void ResumeDownloads();
 *  	void SaveState();
 *  
 *  Private Slots:
 *	void download();
 *	void finishedHead();
 *   	void finished();
 *   	void downloadProgress(qint64 , qint64);
 *  Public Slots:
 *	void Download(const QUrl& , const QString&);
 *	void Download(const QUrl&);
 *	void Stop();
 *	void Resume();
 *  Signals:
 *	void DownloadFinished(const QString&);
 *	void DownloadProgress(qint64 , qint64 , qint64);
 *	void error(QNetworkReply::NetworkError);
 *	void timeout();
 *  Private:
 *	QNetworkAccessManager* _pManager;
 *	QNetworkRequest _CurrentRequest;
 *	QNetworkReply* _pCurrentReply;	
 *	int _nDownloadTotal,
 *	    _nDownloadSize, 
 *	    _nDownloadSizeAtPause;
 *   	bool _bAcceptRanges,
 *	     StopDownload = false,
 *	     doResumeDownload = false,
 *	     doSaveState = false,
 *	     doDebug = false;
 *   	QTimer _Timer;	
 *
*/
class QEasyDownloader : public QObject {
	Q_OBJECT
public:
    explicit QEasyDownloader(QObject *parent = NULL)
	    : QObject(parent)
    {
	    _pManager = new QNetworkAccessManager(this);
	    _Access   = new QMutex(this);
    }

    explicit QEasyDownloader(QObject *parent = NULL , QNetworkManager *toUseManager)
    	    : QObject(parent)
    {
	    _pManager = toUseManger;
	    _Access   = new QMutex(this);
    }
    
    void Debug()
    {
	doDebug = !doDebug;
    }

    void ResumeDownloads()
    {
	doResumeDownloads = !doResumeDownloads;
    }

    void SaveState()
    {
	doSaveState = !doSaveState;
    }

    ~QEasyDownloader()
    {
	    _pManager->deleteLater();
	    _Access->deleteLater();
    }

private slots:
    void download()
    {
    }

    void finishedHead()
    {
    }

    void finished()
    {
    }

    void downloadProgress(qint64 bytesReceived , qint64 bytesTotal)
    {
    }

public slots:
    void Download(const QUrl& givenURL , const QString& fileName)
    {
    }
    
    void Download(const QUrl& givenURL)
    {
    }

    void Stop()
    {
    }

    void Resume()
    {
    }

signals:
    /*
     * I'm only giving the parameters a name because it would be easy to
     * find its meaning!
    */
    void DownloadFinished(const QString& fileName);
    void DownloadProgress(qint64 bytesReceived , qint64 bytesTotal qint64 speed);
    void error(QNetworkReply::NetworkError errorCode);
    void timeout();

private:
    QNetworkAccessManager*    _pManager;
    QNetworkRequest           _CurrentRequest;
    QNetworkReply*            _pCurrentReply;
    QMutex*		      _Access;
    int _nDownloadTotal = 0,
	_nDownloadSize = 0,
	_nDownloadSizeAtPause = 0;
    bool _bAcceptRanges = false,
	 StopDownload = false,
	 doResumeDownloads = false,
	 doSaveState = false,
	 doDebug = false;
    QTimer _Timer;

};  // Class QEasyDownloader END
#endif // QEASY_DOWNLOADER_HPP_INCLUDED
