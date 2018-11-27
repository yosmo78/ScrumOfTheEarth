#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include "shape.h"
#include "square.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent, bool admin) :
    QMainWindow(parent), isAdmin(admin),
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
    file = QInputDialog::getText(this, tr("Open File"), tr("File Name with extension:"), QLineEdit::Normal);
    //shape_parser(shapesList, file.toLocal8Bit().toStdString().c_str());
    Shape * ptr = new Square(0,0,0,40,Qt::blue,Qt::black,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin,Qt::SolidPattern,5);
    ui->widget->shapesList.push_back(ptr);
    ui->widget->update();
}
