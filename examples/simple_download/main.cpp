#include <QCoreApplication>
#include "../../QEasyDownloader.hpp"

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

    /*
     * By Default auto Resuming of Downloads is true.
     *
     * You can also disable auto resuming of downloads.
     * But I strongly recommend you don't!
    */
    // Downloader.ResumeDownloads(false);

    /*
     * Connect Callbacks!
    */
    QObject::connect(&Downloader, &QEasyDownloader::DownloadFinished,
    [&](QUrl Url, QString file) {
        qDebug() << "Downloaded :: " << file << " :: FROM :: " << Url;
        app.quit();
    });

    /*
     * Just Download!
    */
    Downloader.Download("https://github.com/antony-jr/QArchive/releases/download/v0.0.2/QArchive-v0.0.2.tar.gz");
    return app.exec();
}
