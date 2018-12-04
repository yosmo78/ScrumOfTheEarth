#include "addshape.h"
#include "ui_addshape.h"
#include "shape_parser.h"
#include "getstrings.h"

AddShape::AddShape(QWidget *parent,myStd::vector<Shape *> & shapes) :
    QMainWindow(parent),
    ui(new Ui::AddShape)
{
    ui->setupUi(this);
    vecPointer = &shapes;
}

AddShape::~AddShape()
{
    delete ui;
}

void AddShape::on_AddSquare_clicked()
{
    std::string penColor = getColor(ui->PenColors->currentIndex());
    std::string brushColor = getColor(ui->BrushColors->currentIndex());
    Shape * shape = NULL;




   // shape = new Square(shapeID,shapeDemensions[0],shapeDemensions[1],shapeDemensions[2], convertColor(penColor), convertColor(brushColor), convertPenStyle(penStyle), convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), convertBrushStyle(brushStyle), penWidth);
    vecPointer->push_back(shape);
}

