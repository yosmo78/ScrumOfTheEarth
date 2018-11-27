#ifndef SHAPE_H
#define SHAPE_H
#include <QPainter>
#include <QObject>
#include "vector.h"


class Shape: public QObject
{
    Q_OBJECT

    public:
        void setShapeId(unsigned int i){id =i;}
        unsigned int getShapeId(){return id;}
        virtual void draw(QPainter &) = 0;
        Shape(unsigned int i): id(i){}
        virtual ~Shape(){}
    private:
        unsigned int id;
};

void shape_parser(myStd::vector<Shape*>& vec, const char* filename);
#endif // SHAPE_H
