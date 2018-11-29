#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include "shape.h"
#include "square.h"
#include "circle.h"
#include "ellipse.h"
#include "polygon.h"
#include "line.h"
#include "vector.h"
#include <QPoint>
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
      //bool fileok;
      //shape_parser(ui->widget->shapesList, file.toLocal8Bit().toStdString().c_str(), fileok);
      //if(fileok)
      //{

        Shape * ptr = new Square(1500,15,20,40,Qt::blue,Qt::black,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin,Qt::SolidPattern,5);
        myStd::vector<QPoint> tst;
        tst.push_back(QPoint(500,125));
        tst.push_back(QPoint(510,150));
        tst.push_back(QPoint(490,150));
        Shape * pptr = new Polygon(1400,tst,Qt::red,Qt::red,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin,Qt::SolidPattern,2);
        Shape * cptr = new Circle(12000,100,100,10,Qt::red,Qt::red,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin,Qt::SolidPattern,2);
        Shape * eptr = new Ellipse(17000,150,150,10,15,Qt::red,Qt::red,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin,Qt::SolidPattern,2);
        Shape * lptr = new Line(300,100,100, 50,50, Qt::green, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin, 5);
        ui->widget->shapesList.push_back(ptr);
        ui->widget->shapesList.push_back(cptr);
        ui->widget->shapesList.push_back(eptr);
        ui->widget->shapesList.push_back(pptr);
        ui->widget->shapesList.push_back(lptr);
        ui->widget->update();
      //}
      //else
      //{
      //    QMessageBox::warning(this,"Open File","File failed to open");
     // }
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

void MainWindow::on_AddShape_clicked()
{
    if(isAdmin)
    {

    }
    else
    {
        QMessageBox::warning(this,"Add Shape","Access denied. Login as admin");

    }
}

void MainWindow::on_DeleteShape_clicked()
{
    if(isAdmin)
    {

    }
    else
    {
        QMessageBox::warning(this,"Delete Shape","Access denied. Login as admin");

    }
}
