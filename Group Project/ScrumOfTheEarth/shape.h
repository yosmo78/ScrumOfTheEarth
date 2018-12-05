#ifndef SHAPE_H
#define SHAPE_H
#include <QPainter>
#include <QObject>
#include "vector.h"

//! \class Shape
/*!
    Base Class Shape outlines the structure of shapes that can be drawn on a QPaintDevice
*/
class Shape: public QObject
{
    Q_OBJECT

    public:

        /*!
         * Sets the shape id to i
         *
         */
        void setShapeId(unsigned int i){id =i;}

        /*!
         *  Returns the shape id
         */
        unsigned int getShapeId(){return id;}

        /*!
         *  Virtual function called to draw shapes
         */
        virtual void draw(QPainter &, bool) = 0;

        /*!
         *  Constructor with id
         */
        Shape(unsigned int id): id(id){}

        /*!
         *  Copy Constructor (Disabled)
         */
        Shape(const Shape&) = delete;
        /*!
         *  Copy Assignment (Disabled)
         */
        Shape& operator=(const Shape&) = delete;

        /*!
         *  Checks to see if ids are equal
         */
        bool operator==(const Shape& s2){return id == s2.id;}

        /*!
         *  Operator< checks to see if id is less than Shape 2's id
         */
        bool operator<(const Shape& s2){return id<s2.id;}

        /*!
         *  Virtual function to return area of shape
         */
        virtual double getArea(){return 0.0;}

        /*!
         *  Virtual function to return perimeter of shape
         */
        virtual double getPerimeter(){return 0.0;}

        /*!
         *  Virtual function that is used to demarcate the type of the derived class
         */
        virtual int getType() = 0;

        /*!
         *  Shape Destructor
         */
        virtual ~Shape(){}
    private:

        /*!
         *  Shape's id
         */
        unsigned int id;
};

void shape_parser(myStd::vector<Shape*>& vec, const char* filename, bool &ok);
void shape_saver(myStd::vector<Shape*>& vec, const char* filename);
#endif // SHAPE_H
