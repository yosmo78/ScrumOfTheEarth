#include "contactus.h"
#include "ui_contactus.h"
#include <limits.h>
#include <stdlib.h>
#include<string.h>
ContactUs::ContactUs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactUs)
{
//   const char path[100] = "SCRUM LOGO.png";
//   char buf[PATH_MAX+1];
//   char * ptr = realpath(path,buf);
//    QPixmap pic(buf);
    ui->setupUi(this);
//    ui->label->setPixmap(pic);
}

ContactUs::~ContactUs()
{
    delete ui;
}
