#include "viewweb.h"
#include <QWebEngineView>
//using namespace view;

viewweb::viewweb(QWidget *par):QWebEngineView(par)
{

}

void viewweb::loadnextpage(const QUrl &url)
{
     // QWebEngineView  *ev = new QWebEngineView;
      this->load(url);

}
