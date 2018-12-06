#include "addshape.h"
#include "ui_addshape.h"
#include "shape_parser.h"
#include "getstrings.h"

//try catch blocks in the instantiate text segment


AddShape::AddShape(QWidget *parent,myStd::vector<Shape *> & shapes, bool & ok) :
    QMainWindow(parent),
    ui(new Ui::AddShape)
{
    ui->setupUi(this);
    vecPointer = &shapes;
    var = &ok;
    setAttribute(Qt::WA_DeleteOnClose, true);
    ui->tabWidget->setAttribute(Qt::WA_DeleteOnClose);
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

void AddShape::on_EAddEllipse_clicked()
{
    std::string penColor = getColor(ui->EPenColors->currentIndex());
    std::string penStyle = getPenStyle(ui->EPenStyles->currentIndex());
    std::string penCapStyle = getPenCapStyle(ui->EPenCapStyles->currentIndex());
    std::string penJoinStyle = getPenJoinStyle(ui->EPenJoinStyles->currentIndex());
    std::string brushColor = getColor(ui->EBrushColors->currentIndex());
    std::string brushStyle = getBrushStyle(ui->EBrushStyles->currentIndex());
    int penWidth = atoi(ui->EPenWidth->text().toStdString().c_str());
    int shapeID = atoi(ui->EShapeID->text().toStdString().c_str());
    int x = atoi(ui->ExData->text().toStdString().c_str());
    int y = atoi(ui->EyData->text().toStdString().c_str());
    int length = atoi(ui->ELengthInput ->text().toStdString().c_str());
    int width = atoi(ui->EWidthInput->text().toStdString().c_str());

    Shape * shape = NULL;

    shape = new Ellipse(shapeID,x,y,length,width,convertColor(penColor), convertColor(brushColor), convertPenStyle(penStyle), convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), convertBrushStyle(brushStyle), penWidth);
    vecPointer->push_back(shape);
    hide();
    *var = false;
    emit update_Window();
}

void AddShape::on_GAddPolygon_clicked()
{
    std::string penColor = getColor(ui->GPenColors->currentIndex());
    std::string penStyle = getPenStyle(ui->GPenStyles->currentIndex());
    std::string penCapStyle = getPenCapStyle(ui->GPenCapStyles->currentIndex());
    std::string penJoinStyle = getPenJoinStyle(ui->GPenJoinStyles->currentIndex());
    std::string brushColor = getColor(ui->GBrushColors->currentIndex());
    std::string brushStyle = getBrushStyle(ui->GBrushStyles->currentIndex());
    int penWidth = atoi(ui->GPenWidth->text().toStdString().c_str());
    int shapeID = atoi(ui->GShapeID->text().toStdString().c_str());
    std::string skip = ui->GPoints->text().toStdString();
    stringstream ss;
    ss.str(skip);
    int i = 0,vari;
    QPoint qPoint;
    myStd::vector<QPoint> dimensions;
    while(getline(ss, skip, ','))
    {
        vari = stoi(skip);
        if(i % 2 == 0)
        {
            qPoint.setX(vari);
        }
        else
        {
            qPoint.setY(vari);
            dimensions.push_back(qPoint);
        }
        ++i;
    }

    Shape * shape = NULL;
    shape = new Polygon(shapeID,dimensions,convertColor(penColor), convertColor(brushColor), convertPenStyle(penStyle), convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), convertBrushStyle(brushStyle), penWidth);
    vecPointer->push_back(shape);
    hide();
    *var = false;
    emit update_Window();
}


void AddShape::on_PAddPolyline_clicked()
{
    std::string penColor = getColor(ui->PPenColors->currentIndex());
    std::string penStyle = getPenStyle(ui->PPenStyles->currentIndex());
    std::string penCapStyle = getPenCapStyle(ui->PPenCapStyles->currentIndex());
    std::string penJoinStyle = getPenJoinStyle(ui->PPenJoinStyles->currentIndex());
    int penWidth = atoi(ui->PPenWidth->text().toStdString().c_str());
    int shapeID = atoi(ui->PShapeID->text().toStdString().c_str());
    std::string skip = ui->PPoints->text().toStdString();
    stringstream ss;
    ss.str(skip);
    int i = 0,vari;
    QPoint qPoint;
    myStd::vector<QPoint> dimensions;
    while(getline(ss, skip, ','))
    {
        vari = stoi(skip);
        if(i % 2 == 0)
        {
            qPoint.setX(vari);
        }
        else
        {
            qPoint.setY(vari);
            dimensions.push_back(qPoint);
        }
        ++i;
    }

    Shape * shape = NULL;
    shape = new Polyline(shapeID,dimensions,convertColor(penColor), convertPenStyle(penStyle), convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), penWidth);
    vecPointer->push_back(shape);
    hide();
    *var = false;
    emit update_Window();
}

void AddShape::on_LAddLine_clicked()
{
    std::string penColor = getColor(ui->LPenColors->currentIndex());
    std::string penStyle = getPenStyle(ui->LPenStyles->currentIndex());
    std::string penCapStyle = getPenCapStyle(ui->LPenCapStyles->currentIndex());
    std::string penJoinStyle = getPenJoinStyle(ui->LPenJoinStyles->currentIndex());
    int penWidth = atoi(ui->LPenWidth->text().toStdString().c_str());
    int shapeID = atoi(ui->LShapeID->text().toStdString().c_str());
    int p1x = atoi(ui->LPoint1x->text().toStdString().c_str());
    int p1y = atoi(ui->LPoint1y->text().toStdString().c_str());
    int p2x = atoi(ui->LPoint2x->text().toStdString().c_str());
    int p2y = atoi(ui->LPoint2y->text().toStdString().c_str());
    Shape * shape = NULL;
    shape = new Line(shapeID,p1x,p1y,p2x,p2y,convertColor(penColor), convertPenStyle(penStyle), convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), penWidth);
    vecPointer->push_back(shape);
    hide();
    *var = false;
    emit update_Window();
}

void AddShape::on_TAddText_clicked()
{
    std::string textFontStyle;
    try
    {
        textFontStyle = getFontStyle(ui->TFontStyle->currentIndex());
    }
    catch(...)
    {
        textFontStyle = "StyleNormal";
    }
    std::string textFontWeight;
    try
    {
        textFontWeight = getFontWeight(ui->TFontWeight->currentIndex());
    }
    catch(...)
    {
        textFontWeight = "Thin";
    }
    std::string textAlignment;
    try{
        textAlignment = getTextAlignment(ui->TTextAlignment->currentIndex());
    }
    catch(...)
    {
        textAlignment = "AlignLeft";
    }
    QString textFontFamily = ui->TFontFamily->text();
    int textPointSize = atoi(ui->TPointSize->text().toStdString().c_str());
    std::string penColor = getColor(ui->TTextColor->currentIndex());
    QString textString = ui->TString->text();
    int shapeID = atoi(ui->TShapeID->text().toStdString().c_str());
    int shape1 = atoi(ui->TShapeDimensionOne->text().toStdString().c_str());
    int shape2 = atoi(ui->TShapeDimensionTwo->text().toStdString().c_str());
    int shape3 = atoi(ui->TShapeDimensionThree->text().toStdString().c_str());
    int shape4 = atoi(ui->TShapeDimensionFour->text().toStdString().c_str());
    Shape * shape = NULL;
    shape = new Text(shapeID, shape1, shape2, shape3, shape4, textString, convertColor(penColor), convertAlignment(textAlignment), textPointSize, textFontFamily, convertStyle(textFontStyle), convertWeight(textFontWeight));
    vecPointer->push_back(shape);
    hide();
    *var = false;
    emit update_Window();
}
