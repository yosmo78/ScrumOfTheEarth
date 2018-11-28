#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include "shape.h"
#include "square.h"
#include "circle.h"
#include <iostream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent, bool admin) :
   isAdmin(admin), QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_FileButton_clicked()
{
    //ask for file. If exists, clear vector and render are, call shape parser, and call paint event
    bool ok;
    file = QInputDialog::getText(this, tr("Open File"), tr("File Name with extension:"), QLineEdit::Normal, QString(), &ok);
    if(ok)
    {
     // shape_parser(ui->widget->shapesList, file.toLocal8Bit().toStdString().c_str());
      Shape * ptr = new Square(1500,15,20,40,Qt::blue,Qt::black,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin,Qt::SolidPattern,5);
      Shape * cptr = new Circle(12000,100,100,10,Qt::red,Qt::red,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin,Qt::SolidPattern,2);
      ui->widget->shapesList.push_back(ptr);
      ui->widget->shapesList.push_back(cptr);
      ui->widget->update();
    }
}

void MainWindow::on_Save_clicked()
{
    if(isAdmin)
    {


    }
    else
    {
        QMessageBox::warning(this,"Save","Access denied. Login as admin");
    }
}
