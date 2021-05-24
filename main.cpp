#include "mainwindow.h"
#include <QApplication>
#include <QWebEngineView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    QWebEngineView * ev  = new QWebEngineView;
//    ev->setUrl(QUrl("http://192.168.2.201:8081/login"));
//    ev->show();

    return a.exec();
}
