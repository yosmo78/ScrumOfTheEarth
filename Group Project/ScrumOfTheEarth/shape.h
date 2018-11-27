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
        virtual void draw() = 0;
        Shape(QPaintDevice* p, unsigned int i): id(i), painter(p){}
        virtual ~Shape(){}
        QPainter& getPainter(){return painter;}
    private:
        unsigned int id;
        QPainter painter;
};

void shape_parser(myStd::vector<Shape*>& vec, QPaintDevice* pptr, const char* filename);
#endif // SHAPE_H
