#ifndef SHAPE_H
#define SHAPE_H
#include <QPainter>
#include <QObject>

class Shape: public QObject
{
    Q_OBJECT

    public:
        void setShapeId(int i){id =i;}
        int getShapeId(){return id;}
        virtual ~Shape(){}
    private:
        unsigned int id;

};

#endif // SHAPE_H
