#ifndef ADDRESSBAR_H
#define ADDRESSBAR_H

#include<QWidget>
#include<qlineedit.h>
#include<qpushbutton.h>
#include<QHBoxLayout>
#include<qurl.h>
#include<qstring.h>

class AddressBar:public QWidget
{
    Q_OBJECT

public:
    explicit AddressBar(QWidget *parent = 0);
   ~AddressBar();

signals:
    void go(QUrl);

 public slots:
    void gotosite();

private:
    QLineEdit *addressEdit;
    QPushButton *pbtn;
    QHBoxLayout *layout;

};

#endif // ADDRESSBAR_H
