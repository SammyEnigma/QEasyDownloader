/*
 * BSD 3-Clause License
 *
 * Copyright (c) 2018, Antony jr
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
 *  @filename 	 	: QEasyDownloader.cc
 *  @description 	: Header for QEasyDownloader.
 * -----------------------------------------------------------------------------
*/
#if !defined(QEASY_DOWNLOADER_HPP_INCLUDED)
#define QEASY_DOWNLOADER_HPP_INCLUDED
#include <QtCore>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#define NONEED(x) (void)x

/*
 * Class QEasyDownloader <- Inherits QObject
 * --------------------
 *
 *  The main class that handles downloads like a pro.
 *
 *  Constructors:
 *  	QEasyDownloader(QObject *parent = NULL , QNetworkAccessManager *toUseManager = NULL);
 *
 * 	Assigns a parent if the user gives one or assigns a QNetworkAccessManager if the user
 * 	already uses a single NetworkManager for his/her application.
 *
 *  Methods:
 *  	void Debug(bool) -  Enable or Disable Debuging
 *  	void Iterated(bool) - Enable iterated Downloading.
 *  			      ( i.e Download a file in Queue , Stop , Get Approved then Download again.)
 *  	void ResumeDownloads(bool) - Enable or Disable Resuming of Downloads!
 *
 *  	Warning: Disabling Resuming of Downloads will overwrite the file if found!
 *
 * 	void setTimeoutTime(int) - sets the timeout time (in miliseconds) for a request! default is 5000 = 5 secs
 * 	void setRetryTime(int)   - sets the retry time (in miliseconds) for a request! default is 6000 = 6 secs
 *
 *  Private Slots:
 *	void download() - Starts the download with the current pointer _URL and _qsFileName
 *	void finishedHead() - Checks if the source has partial download.
 *   	void finished() - Frees the file that is beign downloaded.
 *   	void downloadProgress(qint64 , qint64) - Writes to file on each progress.
 *   	void error(QNetworkReply::NetworkError) - Inturn emits a signal to make the user handle it.
 *   	void timeout() - Inturn emits a signal to make the user handle the timeout.
 *
 *  Public Slots:
 *	void Download(const QString& , const QString&) - Download a file and save it in the location provided.
 *	void Download(const QString&) - Simply download a file.
 *	void Pause() - Pause the current download.
 *	void Resume() - Resume any paused download.
 *
 *	void Get(const QUrl&) - Simple HTTP/HTTPS GET Request.
 *
 *  Signals:
 *  	void Finished() - Emitted when all jobs are done.
 *  	void DownloadFinished(const QUrl &url, const QString& fileName) - Emitted when a single file is downloaded.
 *  	void DownloadProgress(qint64 bytesReceived,
 *                        qint64 bytesTotal,
 *                        int percent,
 *                        double speed,
 *                        const QString &unit,
 *                        const QUrl &url,
 *                        const QString &fileName) - Full Download Progress , Emitted on every download.
 *      void Error(QNetworkReply::NetworkError errorCode,
 *  	           const QUrl &url,
 *  	           const QString &fileName) - Emitted on error.
 *      void Timeout(const QUrl &url, const QString &fileName) - Emitted when there is a timeout.
 *
 *
 * 	void GetResponse(const QString&) - Emitted when Get(const QUrl&) is successfull.
 *
*/
class QEasyDownloader : public QObject
{
    Q_OBJECT
public:
    explicit QEasyDownloader(QObject *parent = nullptr, QNetworkAccessManager *toUseManager = nullptr);
    void Debug(bool);
    void Iterated(bool);
    void ResumeDownloads(bool);
    void setTimeoutTime(int);
    void setRetryTime(int);
    ~QEasyDownloader();
private slots:
    void download();
    void checkHead(qint64 bytesRecived, qint64 bytesTotal);
    void finished();
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void startNextDownload();
    void error(QNetworkReply::NetworkError errorCode);
    void timeout();
    QString saveFileName(const QString& url);
public slots:
    void Download(const QString& givenURL, const QString& fileName);
    void Download(const QString& givenURL);
    void Pause();
    void Resume();
    bool isNext();
    void Next();
    void Retry(QNetworkAccessManager::NetworkAccessibility access);
    void Get(const QUrl &url);
signals:
    void Finished();
    void DownloadFinished(const QUrl &url, const QString& fileName);
    void DownloadProgress(qint64 bytesReceived,
                          qint64 bytesTotal,
                          int percent,
                          double speed,
                          const QString &unit,
                          const QUrl &url,
                          const QString &fileName);
    void Error(QNetworkReply::NetworkError errorCode, const QUrl &url, const QString &fileName);
    void Timeout(const QUrl &url, const QString &fileName);
    void GetResponse(const QString &content);

private:
    QNetworkAccessManager    *_pManager = NULL;
    QNetworkRequest           _CurrentRequest;
    QNetworkReply            *_pCurrentReply = NULL,
                              *_pCurrentGetReply = NULL;
    QFile		     *_pFile = NULL;

    QTimer _Timer;
    QTime  downloadSpeed;
    QUrl    _URL;
    QString _qsFileName;
    QQueue<QStringList> downloadQueue;

    int _nDownloadTotal = 0,
        _nDownloadSize = 0,
        _nDownloadSizeAtPause = 0,
        _DownloadedCount = 0,
        _TimeoutTime = 5000,
        _RetryTime = 6000;
    bool _bAcceptRanges = false,
         StopDownload = false,
         isError = false,
         doResumeDownloads = true,
         NewDownload = true,
         doIterate = false,
         canIterate = false,
         doDebug = false;
};  // Class QEasyDownloader END
#endif // QEASY_DOWNLOADER_HPP_INCLUDED
