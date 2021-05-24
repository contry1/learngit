#include "addressbar.h"

AddressBar::AddressBar(QWidget * par):QWidget(par)
{
    this->addressEdit =   new QLineEdit(par);
    this->pbtn = new QPushButton("go",par);

    layout = new QHBoxLayout;
    layout->addWidget(addressEdit);
    layout->addWidget(pbtn);
    this->setLayout(layout);

  //  connect(pbtn,SIGNAL(clicked()),this,SLOT(go(QUrl)));
    connect(pbtn,SIGNAL(clicked()),this,SLOT(gotosite()));

    connect(addressEdit,SIGNAL(returnPressed()),this,SLOT(gotosite()));


}

AddressBar::~AddressBar()
{
   if(addressEdit)
      delete addressEdit;
   if(pbtn)
       delete pbtn;
   if(layout)
       delete layout;
}

void AddressBar::gotosite()
{
    QString addr = addressEdit->text();
    emit go(QUrl(addr));
}
