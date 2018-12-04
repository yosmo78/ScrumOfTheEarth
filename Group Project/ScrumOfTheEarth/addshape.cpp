#include "addshape.h"
#include "ui_addshape.h"

AddShape::AddShape(QWidget *parent,myStd::vector<Shape *> & shapes) :
    QMainWindow(parent),
    ui(new Ui::AddShape)
{
    ui->setupUi(this);
}

AddShape::~AddShape()
{
    delete ui;
}
