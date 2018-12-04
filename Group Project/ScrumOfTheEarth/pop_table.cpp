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
    tble->setColumnCount(4);
    tble->setHorizontalHeaderItem(0, new QTableWidgetItem(QString("Shape Type")));
    tble->setHorizontalHeaderItem(1, new QTableWidgetItem(QString("Shape Id")));
    tble->setHorizontalHeaderItem(2, new QTableWidgetItem(QString("Dimensions")));
    tble->setHorizontalHeaderItem(3, new QTableWidgetItem(QString("Pen Color")));
    tble->showGrid();
    QTableWidgetItem* nitem;
    int size = vec.size();
    Square * sptr;
    for(int i = 0; i < size; ++i)
    {
        switch(vec[i]->getType())
        {
            case (1):   nitem = new QTableWidgetItem(QString("Square"));//square
                        tble->setItem(i,0,nitem);
                        nitem = new QTableWidgetItem(QString(std::to_string(vec[i]->getShapeId()).c_str()));//id
                        tble->setItem(i,1,nitem);
                        sptr = dynamic_cast<Square *>(vec[i]);
                        nitem = new QTableWidgetItem(QString((std::to_string(sptr->getLength()).c_str())));
                        tble->setItem(i,2,nitem);
                        break;
            case (2):   nitem = new QTableWidgetItem(QString("Rectangle"));//rect
                        tble->setItem(i,0,nitem);
                        nitem = new QTableWidgetItem(QString(std::to_string(vec[i]->getShapeId()).c_str()));//id
                        tble->setItem(i,1,nitem);
                        break;
            case (3):  nitem = new QTableWidgetItem(QString("Polygon"));//polygon
                       tble->setItem(i,0,nitem);
                       nitem = new QTableWidgetItem(QString(std::to_string(vec[i]->getShapeId()).c_str()));//id
                       tble->setItem(i,1,nitem);
                        break;
            case (4):   nitem = new QTableWidgetItem(QString("Circle"));//circle
                        tble->setItem(i,0,nitem);
                        nitem = new QTableWidgetItem(QString(std::to_string(vec[i]->getShapeId()).c_str()));//id
                        tble->setItem(i,1,nitem);
                        break;
            case (5):   nitem = new QTableWidgetItem(QString("Ellipse"));//ellipse
                        tble->setItem(i,0,nitem);
                        nitem = new QTableWidgetItem(QString(std::to_string(vec[i]->getShapeId()).c_str()));//id
                        tble->setItem(i,1,nitem);
                        break;
            case (6):   nitem = new QTableWidgetItem(QString("Line"));//Line
                        tble->setItem(i,0,nitem);
                        nitem = new QTableWidgetItem(QString(std::to_string(vec[i]->getShapeId()).c_str()));
                        tble->setItem(i,1,nitem);
                        break;
            case (7):   nitem = new QTableWidgetItem(QString("Polyline"));//polyline
                        tble->setItem(i,0,nitem);
                        nitem = new QTableWidgetItem(QString(std::to_string(vec[i]->getShapeId()).c_str()));
                        tble->setItem(i,1,nitem);
                        break;
            case (8):   nitem = new QTableWidgetItem(QString("text"));//text
                        tble->setItem(i,0,nitem);
                        nitem = new QTableWidgetItem(QString(std::to_string(vec[i]->getShapeId()).c_str()));
                        tble->setItem(i,1,nitem);
                        break;
        }
    }

}
