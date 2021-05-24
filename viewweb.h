#ifndef VIEWWEB_H
#define VIEWWEB_H

#include <QtWidgets>
#include <QWebEngineView>
//namespace view {
//class view:public QtWidget
class viewweb : public QWebEngineView
{
    Q_OBJECT
public:
    viewweb(QWidget *par = 0);
 signals:

  public  slots:
    void loadnextpage(const QUrl &url);


};
//}


#endif // VIEW_H
