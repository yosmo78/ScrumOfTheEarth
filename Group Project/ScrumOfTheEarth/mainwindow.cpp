#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include "shape.h"
#include "globalvec.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
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
    QString text = QInputDialog::getText(this, tr("File Input"), tr("File Name:"), QLineEdit::Normal);
    shape_parser(shapes, ui->widget, text.toLocal8Bit().toStdString().c_str());
}
