#include "window.h"
#include "ui_window.h"
#include <QMessageBox>
Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
}

Window::~Window()
{
    delete ui;
}

void Window::on_pushButton_clicked()
{
    QString username = ui->UserText->text();
    QString password = ui->PassText->text();
    if(username != "admin" || password != "admin")
    {
        QMessageBox::warning(this,"Login","You have entered an incorrect password!");
    }
    else
    {
        hide();
    }
}

void Window::on_PassText_returnPressed()
{
    //copy from on_pushButton_clicked()
    QString username = ui->UserText->text();
    QString password = ui->PassText->text();
    if(username != "admin" || password != "admin")
    {
        QMessageBox::warning(this,"Login","You have entered an incorrect password!");

    }
    else
    {
        hide();
    }
}

void Window::on_Contact_clicked()
{
    hide();
    contactus = new ContactUs(this);
    contactus->show();
}
