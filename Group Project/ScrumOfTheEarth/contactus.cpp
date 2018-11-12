#include "contactus.h"
#include "ui_contactus.h"

ContactUs::ContactUs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactUs)
{
    ui->setupUi(this);
    Qpixmap pic("");
    ui->label->setPixmap(pic);
}

ContactUs::~ContactUs()
{
    delete ui;
}
