#include "contactus.h"
#include "ui_contactus.h"

ContactUs::ContactUs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactUs)
{
    ui->setupUi(this);
    char relPath[] = "/ScrumOfTheEarth/Group Project/ScrumOfTheEarth/SCRUM LOGO.jpg";
    size_t relPathSize = strlen(relPath);
    char * absPath = getcwd(relPath,relPathSize);
    QPixmap pic(absPath);
    ui->label->setPixmap(pic);
}

ContactUs::~ContactUs()
{
    delete ui;
}
