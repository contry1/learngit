#include <QGridLayout>
#include <QtWidgets>
#include "addressbar.h"
#include "viewweb.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //1.create widget
    QWidget * centralWidget = new QWidget(this);
    AddressBar * bar = new AddressBar;
    viewweb *v = new viewweb;

    //2.add wdgit to layout
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(bar,0,0,1,10);
    layout->addWidget(v,1,0,1,10);
    centralWidget->setLayout(layout);

    //3.connect widget


    // bool QObject::connect(object::sender,const char *signal,const QObject*rece,const char*member);

      connect(bar,SIGNAL(go(QUrl)),v,SLOT(loadnextpage(QUrl)));


     setCentralWidget(centralWidget);
     setWindowTitle("geography test v1.0");
     resize(640,480);

}

MainWindow::~MainWindow()
{
    delete ui;
}
