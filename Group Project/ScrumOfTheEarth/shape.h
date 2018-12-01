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
        Shape(const Shape&) = delete;//disable copy constructor
        Shape& operator=(const Shape&) = delete ;//disable copy assignment
        bool operator==(const Shape& s2){return id == s2.id;}
        bool operator<(const Shape& s2){return id<s2.id;}
        virtual int getArea(){return 0;}//Shapes default to having 0 area. Shapes that have >0 have to overload
        virtual int getPerimeter(){return 0;}
        virtual int getType() = 0;
        virtual ~Shape(){}
    private:
        unsigned int id;
};

void shape_parser(myStd::vector<Shape*>& vec, const char* filename, bool &ok);
void shape_saver(myStd::vector<Shape*>& vec, const char* filename);
#endif // SHAPE_H
