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

void pop_table(QTableWidget* tble, myStd::vector<Shape*> vec)
{

}//fills table with all parameters and area and perimeter
void fill_table(QTableWidget* tble, myStd::vector<Shape*> vec)//fills table up with all parameters
{
    tble->setRowCount(0);//clears all rows
    tble->setRowCount(vec.size());
    tble->setColumnCount(0);//clears all columns
    tble->setColumnCount(2);
    tble->setHorizontalHeaderItem(0, new QTableWidgetItem(QString("Shape Type")));
    tble->showGrid();

    QTableWidgetItem* nitem;
    int size = vec.size();
    for(int i = 0; i < size; ++i)
    {
        switch(vec[i]->getShapeId())
        {
            case (1):   nitem = new QTableWidgetItem(QString("Square"));//square
                        tble->setItem(i,1,nitem);
                        nitem = new QTableWidgetItem(QString(vec[i]->getShapeId()));//id
                        tble->setItem(i,2,nitem);
                        break;
            case (2):   nitem = new QTableWidgetItem(QString("Rectangle"));//rect
                        tble->setItem(i,1,nitem);
                        nitem = new QTableWidgetItem(QString(vec[i]->getShapeId()));//id
                        tble->setItem(i,2,nitem);
                        break;
            case (3):  nitem = new QTableWidgetItem(QString("Polygon"));//polygon
                       tble->setItem(i,1,nitem);
                       nitem = new QTableWidgetItem(QString(vec[i]->getShapeId()));//id
                       tble->setItem(i,2,nitem);
                        break;
            case (4):   nitem = new QTableWidgetItem(QString("Circle"));//circle
                        tble->setItem(i,1,nitem);
                        nitem = new QTableWidgetItem(QString(vec[i]->getShapeId()));//id
                        tble->setItem(i,2,nitem);
                        break;
            case (5):   nitem = new QTableWidgetItem(QString("Ellipse"));//ellipse
                        tble->setItem(i,1,nitem);
                        nitem = new QTableWidgetItem(QString(vec[i]->getShapeId()));//id
                        tble->setItem(i,2,nitem);
                        break;
            case (6):   nitem = new QTableWidgetItem(QString("Line"));//Line
                        tble->setItem(i,1,nitem);
                        nitem = new QTableWidgetItem(QString(vec[i]->getShapeId()));
                        tble->setItem(i,2,nitem);
                        break;
            case (7):   nitem = new QTableWidgetItem(QString("Polyline"));//polyline
                        tble->setItem(i,1,nitem);
                        nitem = new QTableWidgetItem(QString(vec[i]->getShapeId()));
                        tble->setItem(i,2,nitem);
                        break;
            case (8):   nitem = new QTableWidgetItem(QString("text"));//text
                        tble->setItem(i,1,nitem);
                        nitem = new QTableWidgetItem(QString(vec[i]->getShapeId()));
                        tble->setItem(i,2,nitem);
                        break;
        }
    }

}
