#include <QCoreApplication>
#include <QEasyDownloader>

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

    QObject::connect(&Downloader, &QEasyDownloader::Finished,
    [&](){
       qDebug() << "Downloaded Everything!";
       app.quit();
    });

    QObject::connect(&Downloader, &QEasyDownloader::DownloadFinished,
    [&](QUrl Url, QString file) {
        qDebug() << "Downloaded :: " << file << " :: FROM :: " << Url;
        if(Downloader.isNext()){
	qDebug() << "Downloading the Next Download... ";
	}else{
	qDebug() << "Finishing All Downloads... ";
	}
	Downloader.Next();
    });
    
    Downloader.Iterated(true); // Make it iterated
    
    /*
     * Just Download!
    */
    Downloader.Download("http://sample-videos.com/video/mp4/720/big_buck_bunny_720p_5mb.mp4");
    Downloader.Download("http://sample-videos.com/video/mp4/720/big_buck_bunny_720p_5mb.mp4" , "Next.mp4");
    return app.exec();
}
