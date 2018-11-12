#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>

class Shape: public QObject
{
    Q_OBJECT

    public:
        virtual ~Shape(){}
    private:
        unsigned int id;

};

#endif // SHAPE_H
