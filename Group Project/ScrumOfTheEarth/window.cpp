#include "window.h"
#include "ui_window.h"
#include <QMessageBox>
#include <iostream>
#include <QFile>
Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->GuestLogin->setAttribute(Qt::WA_DeleteOnClose);
    ui->label->setAttribute(Qt::WA_DeleteOnClose);
    ui->PassText->setAttribute(Qt::WA_DeleteOnClose);
    ui->Password->setAttribute(Qt::WA_DeleteOnClose);
    ui->UserText->setAttribute(Qt::WA_DeleteOnClose);
    ui->Username->setAttribute(Qt::WA_DeleteOnClose);
    ui->centralWidget->setAttribute(Qt::WA_DeleteOnClose);
    ui->groupBox->setAttribute(Qt::WA_DeleteOnClose);
    ui->layoutWidget->setAttribute(Qt::WA_DeleteOnClose);
    ui->pushButton->setAttribute(Qt::WA_DeleteOnClose);
    ui->layoutWidget1->setAttribute(Qt::WA_DeleteOnClose);
    ui->menuBar->setAttribute(Qt::WA_DeleteOnClose);
    ui->Contact->setAttribute(Qt::WA_DeleteOnClose);
}

Window::~Window()
{
    delete ui;
}

void Window::on_pushButton_clicked()
{
    QString username = ui->UserText->text();
    QString password = ui->PassText->text();
    create_login_file();
    if(!(Check_Admin(QString("admin_list.txt").toStdString(), username.toStdString(), password.toStdString())))
    {
        QMessageBox::warning(this,"Login","You have entered an incorrect password!");
    }
    else
    {
        hide();
        mainwindow = new MainWindow(this, true);
        mainwindow->show();

    }
}

void Window::on_PassText_returnPressed()
{
    //copy from on_pushButton_clicked()
    QString username = ui->UserText->text();
    QString password = ui->PassText->text();
    create_login_file();
    if(!(Check_Admin(QString("admin_list.txt").toStdString(), username.toStdString(), password.toStdString())))
    {
        QMessageBox::warning(this,"Login","You have entered an incorrect password!");

    }
    else
    {
        hide();
        mainwindow = new MainWindow(this, true);
        mainwindow->show();
    }
}

void Window::on_Contact_clicked()
{
    contactus = new ContactUs(this);
    contactus->show();
}

void Window::on_GuestLogin_clicked()
{
  hide();
  mainwindow = new MainWindow(this, false);
  mainwindow->show();
}
