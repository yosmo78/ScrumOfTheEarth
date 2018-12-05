#include "addshape.h"
#include "ui_addshape.h"
#include "shape_parser.h"
#include "getstrings.h"

AddShape::AddShape(QWidget *parent,myStd::vector<Shape *> & shapes, bool & ok) :
    QMainWindow(parent),
    ui(new Ui::AddShape)
{
    ui->setupUi(this);
    vecPointer = &shapes;
    var = &ok;
}

AddShape::~AddShape()
{
    delete ui;
}

void AddShape::on_AddSquare_clicked()
{
    std::string penColor = getColor(ui->PenColors->currentIndex());
    std::string penStyle = getPenStyle(ui->PenStyles->currentIndex());
    std::string penCapStyle = getPenCapStyle(ui->PenCapStyles->currentIndex());
    std::string penJoinStyle = getPenJoinStyle(ui->PenJoinStyles->currentIndex());
    std::string brushColor = getColor(ui->BrushColors->currentIndex());
    std::string brushStyle = getBrushStyle(ui->BrushStyles->currentIndex());
    int penWidth = atoi(ui->PenWidth->text().toStdString().c_str());
    int shapeID = atoi(ui->ShapeID->text().toStdString().c_str());
    int x = atoi(ui->xData->text().toStdString().c_str());
    int y = atoi(ui->yData->text().toStdString().c_str());
    int length = atoi(ui->LengthInput->text().toStdString().c_str());
    Shape * shape = NULL;

    shape = new Square(shapeID,x,y,length, convertColor(penColor), convertColor(brushColor), convertPenStyle(penStyle), convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), convertBrushStyle(brushStyle), penWidth);
    vecPointer->push_back(shape);
    hide();
    *var = false;
    emit update_Window();
}


void AddShape::on_RAddRectangle_clicked()
{
    std::string penColor = getColor(ui->RPenColors->currentIndex());
    std::string penStyle = getPenStyle(ui->RPenStyles->currentIndex());
    std::string penCapStyle = getPenCapStyle(ui->RPenCapStyles->currentIndex());
    std::string penJoinStyle = getPenJoinStyle(ui->RPenJoinStyles->currentIndex());
    std::string brushColor = getColor(ui->RBrushColors->currentIndex());
    std::string brushStyle = getBrushStyle(ui->RBrushStyles->currentIndex());
    int penWidth = atoi(ui->RPenWidth->text().toStdString().c_str());
    int shapeID = atoi(ui->RShapeID->text().toStdString().c_str());
    int x = atoi(ui->RxData->text().toStdString().c_str());
    int y = atoi(ui->RyData->text().toStdString().c_str());
    int length = atoi(ui->RLengthInput->text().toStdString().c_str());
    int width = atoi(ui->RWidthInput->text().toStdString().c_str());
    Shape * shape = NULL;

    shape = new Rectangle(shapeID,x,y,length,width, convertColor(penColor), convertColor(brushColor), convertPenStyle(penStyle), convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), convertBrushStyle(brushStyle), penWidth);
    vecPointer->push_back(shape);
    hide();
    *var = false;
    emit update_Window();
}

void AddShape::on_CAddCircle_clicked()
{
    std::string penColor = getColor(ui->CPenColors->currentIndex());
    std::string penStyle = getPenStyle(ui->CPenStyles->currentIndex());
    std::string penCapStyle = getPenCapStyle(ui->CPenCapStyles->currentIndex());
    std::string penJoinStyle = getPenJoinStyle(ui->CPenJoinStyles->currentIndex());
    std::string brushColor = getColor(ui->CBrushColors->currentIndex());
    std::string brushStyle = getBrushStyle(ui->CBrushStyles->currentIndex());
    int penWidth = atoi(ui->CPenWidth->text().toStdString().c_str());
    int shapeID = atoi(ui->CShapeID->text().toStdString().c_str());
    int x = atoi(ui->CxData->text().toStdString().c_str());
    int y = atoi(ui->CyData->text().toStdString().c_str());
    int radius = atoi(ui->CRadiusInput->text().toStdString().c_str());

    Shape * shape = NULL;

    shape = new Circle(shapeID,x,y,radius, convertColor(penColor), convertColor(brushColor), convertPenStyle(penStyle), convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), convertBrushStyle(brushStyle), penWidth);
    vecPointer->push_back(shape);
    hide();
    *var = false;
    emit update_Window();
}
