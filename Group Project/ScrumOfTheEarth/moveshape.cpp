#include "moveshape.h"
#include "ui_moveshape.h"
#include <iostream>

MoveShape::MoveShape(QWidget *parent, myStd::vector<Shape *> & shapes):
    QMainWindow(parent),
    ui(new Ui::MoveShape)
{
    ui->setupUi(this);
    vecPointer = &shapes;
}

MoveShape::~MoveShape()
{
    delete ui;
}

void MoveShape::on_pushButton_clicked()
{
    int newX = atoi(ui->x_cord->text().toStdString().c_str());
    int newY = atoi(ui->y_cord->text().toStdString().c_str());

    unsigned int newID = atoi(ui->shape_id->text().toStdString().c_str());



    Shape **ptr = vecPointer->begin();
    Shape *ptr2 = nullptr;
    for(int i = 0; i < vecPointer->size(); ++i)
    {
        if(ptr[i]->getShapeId() == newID)
        {
            ptr2 = ptr[i];
            break;
        }

    }


    if((*ptr2).getType() == Square::getStaticType())
    {
       Square * sptr = dynamic_cast<Square *>(ptr2);
       sptr->setCornerPoint(QPoint(newX, newY));
    }
    else if((*ptr2).getType() == Rectangle::getStaticType())
    {
       Rectangle * sptr = dynamic_cast<Rectangle *>(ptr2);
       sptr->setCornerPoint(QPoint(newX, newY));
    }
    else if((*ptr2).getType() == Line::getStaticType())
    {
       Line * sptr = dynamic_cast<Line *>(ptr2);
       sptr->setPoint1(QPoint(newX, newY));
       int deltaX = (sptr->getPoint1().x()) - newX;
       int deltaY = (sptr->getPoint1().y()) - newY;

       int placeX = sptr->getPoint2().x() - deltaX;
       int placeY = sptr->getPoint2().y() - deltaY;

       sptr->setPoint2(QPoint(placeY, placeX));
    }
    else if((*ptr2).getType() == Circle::getStaticType())
    {
       Circle * sptr = dynamic_cast<Circle *>(ptr2);
       sptr->setPoint1(QPoint(newX, newY));
    }
    else if((*ptr2).getType() == Ellipse::getStaticType())
    {
       Ellipse * sptr = dynamic_cast<Ellipse *>(ptr2);
       sptr->setTopLeft(QPoint(newX, newY));
    }
    else if((*ptr2).getType() == Polygon::getStaticType())
    {
       Polygon * sptr = dynamic_cast<Polygon *>(ptr2);

       QPoint *tmp = sptr->getPolyPoints();

       int deltaX = tmp[0].x() - newX;
       int deltaY = tmp[0].y() - newY;

       tmp[0] = QPoint(newX,newY);

       for(int i = 1;i< sptr->getNumOfPoints(); i++)
       {
           tmp[i] = QPoint(tmp[i].x() - deltaX , tmp[i].y() - deltaY);
       }
    }
    else if((*ptr2).getType() == Polyline::getStaticType())
    {
        Polyline * sptr = dynamic_cast<Polyline *>(ptr2);

        myStd::vector<QPoint> *vecPtr = &(sptr->getPoints());
        QPoint *tmp = vecPtr->begin();

        int deltaX = tmp[0].x() - newX;
        int deltaY = tmp[0].y() - newY;

        tmp[0] = QPoint(newX,newY);

        for(int i = 1;i< sptr->getNumOfPoints(); i++)
        {
            tmp[i] = QPoint(tmp[i].x() - deltaX , tmp[i].y() - deltaY);
        }
    }
    else if((*ptr2).getType() == Text::getStaticType())
    {
       Text * sptr = dynamic_cast<Text *>(ptr2);
       sptr->setCornerPoint(QPoint(newX, newY));
    }
    hide();
    emit update_win();
}
