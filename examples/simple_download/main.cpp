#include <QCoreApplication>
#include <iostream>
#include "../../QEasyDownloader.hpp"

int main(int argc , char **argv){
	QCoreApplication app(argc , argv);
	QEasyDownloader Downloader;
	
	QObject::connect(&Downloader , &QEasyDownloader::DownloadFinished , [&](QUrl Url , QString file)
	{
		qDebug() << "Downloaded :: " << file << " :: FROM :: " << Url;
		app.quit();
	});

	QObject::connect(&Downloader , &QEasyDownloader::DownloadProgress ,
	[&](qint64 rec, qint64 total , int percentage , double speed , QString unit , QUrl Url , QString file)
	{
		qDebug() << "Downloading " << percentage << "% at " << speed << unit << " :: FROM :: " << Url
		<< " :: TO :: " << file;

		qDebug() << "Downloaded :: " << rec << " out of " << total << " Bytes.";
	});	
										

	Downloader.Download("http://speedtest-ny.turnkeyinternet.net/100mb.bin");
	
	

	return app.exec();
}
