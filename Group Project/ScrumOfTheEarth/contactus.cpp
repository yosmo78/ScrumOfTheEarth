#include "contactus.h"
#include "ui_contactus.h"

ContactUs::ContactUs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactUs)
{
    char relPath[] = "/SCRUM LOGO.jpg";
    size_t relPathSize = strlen(relPath);
    char * absPath = getcwd(relPath,100*relPathSize);
    QPixmap pic(absPath);
    ui->label->setPixmap(pic);
    ui->setupUi(this);

}

ContactUs::~ContactUs()
{
    delete ui;
}
