#ifndef SHAPE_H
#define SHAPE_H
#include <QPainter>
#include <QObject>

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

#endif // SHAPE_H
