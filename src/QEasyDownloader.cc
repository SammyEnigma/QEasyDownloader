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
 *  @description 	: Source for QEasyDownloader.
 * -----------------------------------------------------------------------------
*/
#include <QEasyDownloader.hpp>

/*
 * Constructor and Destructor
 * ---------------------------
 *
*/
QEasyDownloader::QEasyDownloader(QObject *parent, QNetworkAccessManager *toUseManager)
    : QObject(parent)
{
    _pManager = (toUseManager == nullptr) ? new QNetworkAccessManager(this) : toUseManager;
    _pManager->setRedirectPolicy(QNetworkRequest::NoLessSafeRedirectPolicy);
    connect(_pManager, &QNetworkAccessManager::networkAccessibleChanged, this, &QEasyDownloader::Retry);
    return;
}

QEasyDownloader::~QEasyDownloader()
{
    _pManager->deleteLater();
    return;
}

/*
 * ------
*/

/*
 * Public Methods
 * --------------------------
*/
void QEasyDownloader::setDebug(bool ch)
{
    QMutexLocker locker(&mutex);
    doDebug = ch;
    return;
}

void QEasyDownloader::setIterated(bool ch)
{
    QMutexLocker locker(&mutex);
    doIterate = ch;
    return;
}

void QEasyDownloader::setResumeDownloads(bool ch)
{
    QMutexLocker locker(&mutex);
    doResumeDownloads = ch;
    return;
}

void QEasyDownloader::setTimeoutTime(int time)
{
    QMutexLocker locker(&mutex);
    	_TimeoutTime = time;
    return;
}

void QEasyDownloader::setRetryTime(int time)
{
    QMutexLocker locker(&mutex);
    	_RetryTime = time;
    return;
}

/*
 * ------
*/

/*
 * Private Slots
 * ---------------------
*/
void QEasyDownloader::download()
{
    if (_bAcceptRanges) {
        QByteArray rangeHeaderValue = "bytes=" + QByteArray::number(_nDownloadSizeAtPause) + "-";
        if (_nDownloadTotal > 0) {
            rangeHeaderValue += QByteArray::number(_nDownloadTotal);
        }
        _CurrentRequest.setRawHeader("Range", rangeHeaderValue);
    }

    _pCurrentReply = _pManager->get(_CurrentRequest);

    _Timer.setInterval(_TimeoutTime);
    _Timer.setSingleShot(true);

    connect(&_Timer, SIGNAL(timeout()), this, SLOT(timeout()));

    _Timer.start();
    downloadSpeed.start();

    connect(_pCurrentReply, SIGNAL(finished()), this, SLOT(finished()));
    connect(_pCurrentReply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downloadProgress(qint64,qint64)));
    connect(_pCurrentReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));

    return;
}

void QEasyDownloader::checkHead(qint64 bytesRecived, qint64 bytesTotal)
{

    NONEED(bytesRecived); // We do not need any progress.

    /*
     * Disconnect the reply as soon as possible since it may cause collison.
    */
    disconnect(_pCurrentReply, SIGNAL(downloadProgress(qint64, qint64)),
               this, SLOT(checkHead(qint64, qint64)));


    _Timer.stop();
    _bAcceptRanges = false;


    _nDownloadTotal = bytesTotal; // less expensive than parsing the content length header.
    if(_pCurrentReply->attribute( QNetworkRequest::HttpStatusCodeAttribute ).toInt() >= 400) {
        if(!doIterate) {
            startNextDownload();
        } else {
            canIterate = true;
        }
        return;
    }

    if (_pCurrentReply->hasRawHeader("Accept-Ranges")) {
        QString qstrAcceptRanges = _pCurrentReply->rawHeader("Accept-Ranges");
        _bAcceptRanges = (qstrAcceptRanges.compare("bytes", Qt::CaseInsensitive) == 0);
    }

    /*
     * Delete it little later.
    */
    _pCurrentReply->abort(); // stop the request.
    _pCurrentReply->deleteLater();
    _pCurrentReply = NULL;

    /*
     * Set the new request to download the file.
     */
    _CurrentRequest.setRawHeader("Connection", "Keep-Alive");
    _CurrentRequest.setAttribute(QNetworkRequest::HttpPipeliningAllowedAttribute, true);
    _pFile = new QFile(_qsFileName);

    /*
     * Check if we want to delete the old file.
    */
    if (!_bAcceptRanges) {
        _pFile->remove();
    }
    if(!doResumeDownloads) {
        _pFile->remove();
    }

    _pFile->open(QIODevice::ReadWrite | QIODevice::Append);
    _nDownloadSizeAtPause = _pFile->size();

    /*
     * If the total download size and download size at pause
     * is equal then the file is fully retrived so no need
     * to range request it again as it may give UnknownContentError
    */
    if(_nDownloadTotal == _nDownloadSizeAtPause) {
        emit(finished());
        return;
    }

    download();
    return;
}

void QEasyDownloader::finished()
{
    if(isError) {
        isError = false;
        return;
    }
    
    _Timer.stop();
    _pFile->close();
    _pFile = NULL;
    _pCurrentReply = 0;

    if(!doIterate) {
        startNextDownload();
    } else {
        canIterate = true;
    }
    emit DownloadFinished(_URL, _qsFileName);
    return;
}

void QEasyDownloader::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    _Timer.stop();

    _nDownloadSize = _nDownloadSizeAtPause + bytesReceived;
    _pFile->write(_pCurrentReply->readAll());

    int nPercentage =
        static_cast<int>(
            (static_cast<float>
             (
                 _nDownloadSizeAtPause + bytesReceived
             ) * 100.0
            ) / static_cast<float>
            (
                _nDownloadSizeAtPause + bytesTotal
            )
        );

    double speed = bytesReceived * 1000.0 / downloadSpeed.elapsed();
    QString unit;
    if (speed < 1024) {
        unit = "bytes/sec";
    } else if (speed < 1024*1024) {
        speed /= 1024;
        unit = "kB/s";
    } else {
        speed /= 1024*1024;
        unit = "MB/s";
    }

    emit DownloadProgress(bytesReceived,
                          bytesTotal,
                          nPercentage,
                          speed,
                          unit,
                          _URL,
                          _qsFileName);
    _Timer.start(_TimeoutTime);
    return;
}

void QEasyDownloader::startNextDownload()
{
    if(StopDownload) {
        return;
    }

    if (downloadQueue.isEmpty()) {
        _bAutoStartDownload  = true;
        emit(Finished());
        return;
    }

    QStringList DownloadInformation = downloadQueue.dequeue();

    _URL = QUrl(DownloadInformation.at(0));
    _qsFileName = DownloadInformation.at(1);

    if(_URL.isEmpty() || _qsFileName.isEmpty()) {
        QTimer::singleShot(0, this, SLOT(startNextDownload()));
        return;
    }


    _nDownloadSize = 0;
    _nDownloadSizeAtPause = 0;

    _CurrentRequest = QNetworkRequest(_URL);

    /*
     * You may ask why we are not using HEAD ?
     * Because in some servers HEAD request is not supported or
     * not allowed but **range request** may be allowed.
     * Example:- Amazon AWS.
     *
     * So to solve this , We check the head by giving a get request
     * and abort it in a very short time. Getting all the information
     * like HEAD but having the advantages of GET.
    */
    _pCurrentReply = _pManager->get(_CurrentRequest);

    _Timer.setInterval(_TimeoutTime);
    _Timer.setSingleShot(true);

    connect(&_Timer, SIGNAL(timeout()), this, SLOT(timeout()));
    _Timer.start();

    connect(_pCurrentReply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(checkHead(qint64,qint64)));
    connect(_pCurrentReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));
    return;
}

void QEasyDownloader::retry(QNetworkAccessManager::NetworkAccessibility access)
{
    if(access == QNetworkAccessManager::NotAccessible || access == QNetworkAccessManager::UnknownAccessibility) {
        isError = false;
        QTimer::singleShot(500, this, SLOT(Pause()));
        return;
    }
    QTimer::singleShot(_RetryTime, this, SLOT(Resume()));
    return;
}


void QEasyDownloader::error(QNetworkReply::NetworkError errorCode)
{
    /*
     * Avoid Operation cancel errors.
    */
    if(errorCode == QNetworkReply::OperationCanceledError) {
        return;
    }

    isError = true;
    emit Error(errorCode, _URL, _qsFileName);
    return;
}

void QEasyDownloader::timeout()
{
    emit Timeout(_URL, _qsFileName);
    return;
}

QString QEasyDownloader::saveFileName(const QString& url)
{
    QString path = QUrl(url).path();
    QString basename = QFileInfo(path).fileName();

    if (basename.isEmpty()) {
        basename = "download";
    }
    return basename;
}

void QEasyDownloader::printDebug(const QString &msg)
{
    if(_bDoDebug){
        emit(Debugger(msg));
    }
    return;
}

/*
 * ------
*/

/*
 * Public Slots
 * ---------------------
*/

void QEasyDownloader::Download(const QString& givenURL, const QString& fileName)
{
    QMutexLocker locker(&mutex);
    QStringList DownloadInformation;
    DownloadInformation << givenURL << fileName;
    downloadQueue.enqueue(DownloadInformation);

    /*
     * Debug
    */

    printDebug("Queued:: " + givenURL + " -> " + fileName);

    // --- 

    if(_bAutoStartDownload ) { // Do not use downloadQueue.size() == 1.
        _bAutoStartDownload  = false;
        emit(startNextDownload());
    }
    return;
}

void QEasyDownloader::Download(const QString& givenURL)
{
    Download(givenURL, saveFileName(givenURL));
    return;
}

void QEasyDownloader::Pause()
{
    QMutexLocker locker(&mutex);
    if (_pCurrentReply == NULL || StopDownload) {
        return;
    }

    _Timer.stop();
    disconnect(&_Timer, SIGNAL(timeout()), this, SLOT(timeout()));
    disconnect(_pCurrentReply, SIGNAL(finished()), this, SLOT(finished()));
    disconnect(_pCurrentReply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downloadProgress(qint64,qint64)));
    disconnect(_pCurrentReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));

    _pCurrentReply->abort();
    _pFile->flush();
    _pCurrentReply = 0;
    _nDownloadSizeAtPause = _nDownloadSize;
    _nDownloadSize = 0;
    StopDownload = true;
   
    /*
     * Debug and Reporting! 
    */

    printDebug("Paused:: " + _URL.toString());
    emit(Paused(_URL , _qsFileName));

    // ----

    return;
}

void QEasyDownloader::Resume()
{
    QMutexLocker locker(&mutex);
    if(!StopDownload || _pCurrentReply != NULL) {
        return;
    }
    StopDownload = false;
    download();
    
    /*
     * Debug and Reporting! 
    */

    printDebug("Resumed:: " + _URL.toString());
    emit(Resumed(_URL , _qsFileName));

    // ----

    return;
}


bool QEasyDownloader::isNext()
{
    QMutexLocker locker(&mutex);
    return !downloadQueue.isEmpty();
}

void QEasyDownloader::Next()
{
    QMutexLocker locker(&mutex);
    if(!doIterate) {
        return;
    }

    if(canIterate) {
        emit(startNextDownload());
        canIterate = false;
    }
    return;
}

/*
 * ---------------
*/
