#include "pop_table.h"
#include "square.h"
#include "rectangle.h"
#include "circle.h"
#include "ellipse.h"
#include "text.h"
#include "line.h"
#include "polyline.h"
#include "polygon.h"
#include <QString>
#include <iostream>
#include <string>

void pop_table(QTableWidget* tble, myStd::vector<Shape*> vec)
{

}//fills table with all parameters and area and perimeter
void fill_table(QTableWidget* tble, myStd::vector<Shape*> vec)//fills table up with all parameters
{
    std::string qtColors[]         = {"color0","color1","black","white","darkGray","gray","lightGray","red","green","blue","cyan","magenta","yellow","darkRed","darkGreen","darkBlue","darkCyan","darkMagenta","darkYellow","transparent"};
    std::string penStyles[]        = {"NoPen","SolidLine","DashLine","DotLine","DashDotLine","DashDotDotLine","CustomDashLine"};
    std::string penCapStyles[0x21] = {"FlatCap"};
    penCapStyles[0x10] = "SqaureCap";
    penCapStyles[0x20] = "RoundCap";
    std::string penJoinStyles[0x81]= {"MiterJoin"};
    penJoinStyles[0x40] = "BevelJoin";
    penJoinStyles[0x80] = "RoundJoin";
    std::string brushStyles[]      = {"NoBrush","SolidPattern","Dense1Pattern","Dense2Pattern","Dense3Pattern","Dense4Pattern","Dense5Pattern","Dense6Pattern","Dense7Pattern","HorPattern","VerPattern","CrossPattern","BDiagPattern","FDiagPattern","DiagCrossPattern","LinearGradientPattern","RadialGradientPattern","ConicalGradientPattern","","","","","","","TexturePattern"};
    std::string textAlignments[0x0085]; //check these later,
    textAlignments[0x0001] = "AlignLeft";
    textAlignments[0x0002] = "AlignRight";
    textAlignments[0x0004] = "AlignHCenter";
    textAlignments[0x0008] = "AlignJustify";
    textAlignments[0x0020] = "AlignTop";
    textAlignments[0x0040] = "AlignBottom";
    textAlignments[0x0080] = "AlignVCenter";
    textAlignments[0x0004|0x0080] = "AlignCenter";
    std::string textFontStyles[]   = {"StyleNormal","StyleItalic","StyleOblique"};
    std::string textFontWeights[99];
    textFontWeights[25] = "Light";
    textFontWeights[50] = "Normal";
    textFontWeights[63] = "DemiBold";
    textFontWeights[75] = "Bold";
    textFontWeights[87] = "Black";

    tble->setRowCount(0);//clears all rows
    tble->setRowCount(vec.size());
    tble->setColumnCount(0);//clears all columns
    tble->setColumnCount(6);
    tble->setHorizontalHeaderItem(0, new QTableWidgetItem(QString("Shape Type")));
    tble->setHorizontalHeaderItem(1, new QTableWidgetItem(QString("Shape Id")));
    tble->setHorizontalHeaderItem(2, new QTableWidgetItem(QString("Dimensions")));
    tble->setHorizontalHeaderItem(3, new QTableWidgetItem(QString("Pen/Text Color")));
    tble->setHorizontalHeaderItem(4, new QTableWidgetItem(QString("Pen/Font Style")));
    tble->setHorizontalHeaderItem(5, new QTableWidgetItem(QString("Pen Cap Style")));
    tble->showGrid();
    QTableWidgetItem* nitem;
    int size = vec.size();
    Square * sptr;
    Rectangle * rptr;
    Line * lptr;
    Circle * cptr;
    Ellipse * eptr;
    Polygon * pptr;
    Polyline * Pptr;
    Text * tptr;
    std::string polypoints;
    for(int i = 0; i < size; ++i)
    {
        switch(vec[i]->getType())
        {
            case (1):   nitem = new QTableWidgetItem(QString("Square"));//square
                        tble->setItem(i,0,nitem);
                        nitem = new QTableWidgetItem(QString(std::to_string(vec[i]->getShapeId()).c_str()));//id
                        tble->setItem(i,1,nitem);
                        sptr = dynamic_cast<Square *>(vec[i]);
                        nitem = new QTableWidgetItem(QString(((std::string("X: ") +std::to_string(sptr->getCornerPoint().x()) + std::string(" Y: ") +std::to_string(sptr->getCornerPoint().y())+ std::string(" Length: ") +std::to_string(sptr->getLength())).c_str())));
                        tble->setItem(i,2,nitem);
                        nitem = new QTableWidgetItem(QString(qtColors[sptr->getPenColor()].c_str()));//Pen Color
                        tble->setItem(i,3,nitem);
                        nitem = new QTableWidgetItem(QString(penStyles[sptr->getPenStyle()].c_str()));//Pen Style
                        tble->setItem(i,4,nitem);
                        nitem = new QTableWidgetItem(QString(penCapStyles[sptr->getPenCapStyle()].c_str()));//Pen Cap Style
                        tble->setItem(i,5,nitem);
                        break;
            case (2):   nitem = new QTableWidgetItem(QString("Rectangle"));//rect
                        tble->setItem(i,0,nitem);
                        nitem = new QTableWidgetItem(QString(std::to_string(vec[i]->getShapeId()).c_str()));//id
                        tble->setItem(i,1,nitem);
                        rptr = dynamic_cast<Rectangle *> (vec[i]);
                        nitem = new QTableWidgetItem(QString((std::string("X: ") +std::to_string(rptr->getCornerPoint().x()) + std::string(" Y: ") +std::to_string(rptr->getCornerPoint().y())+std::string("Width: ") + std::to_string(rptr->getWidth())+ std::string(" Length: ") +std::to_string(rptr->getLength())).c_str()));
                        tble->setItem(i,2,nitem);
                        nitem = new QTableWidgetItem(QString(qtColors[rptr->getPenColor()].c_str()));//Pen Color
                        tble->setItem(i,3,nitem);
                        nitem = new QTableWidgetItem(QString(penStyles[rptr->getPenStyle()].c_str()));//Pen Style
                        tble->setItem(i,4,nitem);
                        nitem = new QTableWidgetItem(QString(penCapStyles[rptr->getPenCapStyle()].c_str()));//Pen Cap Style
                        tble->setItem(i,5,nitem);
                        break;
            case (3):   nitem = new QTableWidgetItem(QString("Polygon"));//polygon
                        tble->setItem(i,0,nitem);
                        nitem = new QTableWidgetItem(QString(std::to_string(vec[i]->getShapeId()).c_str()));//id
                        tble->setItem(i,1,nitem);
                        pptr = dynamic_cast<Polygon *> (vec[i]);
                        for(int i = 0; i < pptr->getNumOfPoints(); ++i)
                        {
                            polypoints += (std::string("Point ") + std::to_string(i + 1) + std::string(". ") + std::to_string(pptr->getPolyPoints()[i].x()) + std::string(" ") + std::to_string(pptr->getPolyPoints()[i].y())+ std::string(" "));
                        }
                        nitem = new QTableWidgetItem(QString(polypoints.c_str()));
                        tble->setItem(i, 2, nitem);
                        nitem = new QTableWidgetItem(QString(qtColors[pptr->getPenColor()].c_str()));//Pen Color
                        tble->setItem(i,3,nitem);
                        nitem = new QTableWidgetItem(QString(penStyles[pptr->getPenStyle()].c_str()));//Pen Style
                        tble->setItem(i,4,nitem);
                        nitem = new QTableWidgetItem(QString(penCapStyles[pptr->getPenCapStyle()].c_str()));//Pen Cap Style
                        tble->setItem(i,5,nitem);
                        break;
            case (4):   nitem = new QTableWidgetItem(QString("Circle"));//circle
                        tble->setItem(i,0,nitem);
                        nitem = new QTableWidgetItem(QString(std::to_string(vec[i]->getShapeId()).c_str()));//id
                        tble->setItem(i,1,nitem);
                        cptr = dynamic_cast<Circle *> (vec[i]);
                        nitem = new QTableWidgetItem(QString(((std::string("X: ") +std::to_string(cptr->getPoint1().x()) + std::string(" Y: ") +std::to_string(cptr->getPoint1().y())+std::string("Radius: ") +std::to_string(cptr->getRadius())).c_str())));
                        tble->setItem(i,2,nitem);
                        nitem = new QTableWidgetItem(QString(qtColors[cptr->getPenColor()].c_str()));//Pen Color
                        tble->setItem(i,3,nitem);
                        nitem = new QTableWidgetItem(QString(penStyles[cptr->getPenStyle()].c_str()));//Pen Style
                        tble->setItem(i,4,nitem);
                        nitem = new QTableWidgetItem(QString(penCapStyles[cptr->getPenCapStyle()].c_str()));//Pen Cap Style
                        tble->setItem(i,5,nitem);
                        break;
            case (5):   nitem = new QTableWidgetItem(QString("Ellipse"));//ellipse
                        tble->setItem(i,0,nitem);
                        nitem = new QTableWidgetItem(QString(std::to_string(vec[i]->getShapeId()).c_str()));//id
                        tble->setItem(i,1,nitem);
                        eptr = dynamic_cast<Ellipse *> (vec[i]);
                        nitem = new QTableWidgetItem(QString((std::string("X: ") +std::to_string(eptr->getTopLeft().x()) + std::string(" Y: ") +std::to_string(eptr->getTopLeft().y())+std::string("Semimajor: ") + std::to_string(eptr->getMajorAxis())+ std::string(" Semiminor: ") +std::to_string(eptr->getMinorAxis())).c_str()));
                        tble->setItem(i,2,nitem);
                        nitem = new QTableWidgetItem(QString(qtColors[eptr->getPenColor()].c_str()));//Pen Color
                        tble->setItem(i,3,nitem);
                        nitem = new QTableWidgetItem(QString(penStyles[eptr->getPenStyle()].c_str()));//Pen Style
                        tble->setItem(i,4,nitem);
                        nitem = new QTableWidgetItem(QString(penCapStyles[eptr->getPenCapStyle()].c_str()));//Pen Cap Style
                        tble->setItem(i,5,nitem);
                        break;
            case (6):   nitem = new QTableWidgetItem(QString("Line"));//Line
                        tble->setItem(i,0,nitem);
                        nitem = new QTableWidgetItem(QString(std::to_string(vec[i]->getShapeId()).c_str()));//id
                        tble->setItem(i,1,nitem);
                        lptr = dynamic_cast<Line *> (vec[i]);
                        nitem = new QTableWidgetItem(QString((std::string("Point 1: ") + std::to_string(lptr->getPoint1().x())+ std::string(" ")+ std::to_string(lptr->getPoint1().y())+ std::string(" Point 2: ") +std::to_string(lptr->getPoint2().x())+ std::string(" ")+ std::to_string(lptr->getPoint2().y())).c_str()));
                        tble->setItem(i,2,nitem);
                        nitem = new QTableWidgetItem(QString(qtColors[lptr->getPenColor()].c_str()));//Pen Color
                        tble->setItem(i,3,nitem);
                        nitem = new QTableWidgetItem(QString(penStyles[lptr->getPenStyle()].c_str()));//Pen Style
                        tble->setItem(i,4,nitem);
                        nitem = new QTableWidgetItem(QString(penCapStyles[lptr->getPenCapStyle()].c_str()));//Pen Cap Style
                        tble->setItem(i,5,nitem);
                        break;
            case (7):   nitem = new QTableWidgetItem(QString("Polyline"));//polyline
                        tble->setItem(i,0,nitem);
                        nitem = new QTableWidgetItem(QString(std::to_string(vec[i]->getShapeId()).c_str()));//id
                        tble->setItem(i,1,nitem);
                        Pptr = dynamic_cast<Polyline *> (vec[i]);
                        for(int i = 0; i < Pptr->getNumOfPoints(); ++i)
                        {
                            polypoints += (std::string("Point ") + std::to_string(i + 1) + std::string(". ") + std::to_string(Pptr->getPoints()[i].x()) + std::string(" ") + std::to_string(Pptr->getPoints()[i].y())+ std::string(" "));
                        }
                        nitem = new QTableWidgetItem(QString(polypoints.c_str()));
                        tble->setItem(i, 2, nitem);
                        nitem = new QTableWidgetItem(QString(qtColors[Pptr->getPenColor()].c_str()));//Pen Color
                        tble->setItem(i,3,nitem);
                        nitem = new QTableWidgetItem(QString(penStyles[Pptr->getPenStyle()].c_str()));//Pen Style
                        tble->setItem(i,4,nitem);
                        nitem = new QTableWidgetItem(QString(penCapStyles[Pptr->getPenCapStyle()].c_str()));//Pen Cap Style
                        tble->setItem(i,5,nitem);
                        break;
            case (8):   nitem = new QTableWidgetItem(QString("text"));//text
                        tble->setItem(i,0,nitem);
                        nitem = new QTableWidgetItem(QString(std::to_string(vec[i]->getShapeId()).c_str()));//id
                        tble->setItem(i,1,nitem);
                        tptr = dynamic_cast<Text *> (vec[i]);
                        nitem = new QTableWidgetItem(QString((std::string("X: ") +std::to_string(tptr->getCornerPoint().x()) + std::string(" Y: ") +std::to_string(tptr->getCornerPoint().y())+std::string("Width: ") + std::to_string(tptr->getWidth())+ std::string(" Length: ") +std::to_string(tptr->getLength())).c_str()));
                        tble->setItem(i,2,nitem);
                        nitem = new QTableWidgetItem(QString(qtColors[tptr->getGlobalColor()].c_str()));//Pen Color
                        tble->setItem(i,3,nitem);
                        nitem = new QTableWidgetItem(QString(textFontStyles[tptr->getTextFontStyle()].c_str()));//Pen/text Style
                        tble->setItem(i,4,nitem);
                        nitem = new QTableWidgetItem(QString(""));//Pen Cap Style
                        tble->setItem(i,5,nitem);
                        break;
        }
    }

}
