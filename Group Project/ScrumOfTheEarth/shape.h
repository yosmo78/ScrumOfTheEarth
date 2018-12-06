/*! \file */
#ifndef SHAPE_H
#define SHAPE_H
#include <QPainter>
#include <QObject>
#include "vector.h"

//virtual function is in here, two overloaded operators are here
//all other shapes inherit from here, so inheritance, and most other shapes compose QStrings

/*!
 * \brief Abstract Base Class for shapes that get rendered by the QPainter
 */
class Shape: public QObject
{
    Q_OBJECT

    public:

        /*!
         * \brief Sets the shape id to the given id
         * \param id
         */
        void setShapeId(unsigned int i){id =i;}

        /*!
         * \brief Gets the shape id of the Shape
         * \return id
         */
        unsigned int getShapeId(){return id;}

        /*!
         * \brief Virtual function to draw shapes
         */
        virtual void draw(QPainter &, bool) = 0;

        /*!
         * \brief Shape constructor with id
         * \param id
         */
        Shape(unsigned int id): id(id){}

        /*!
         * \brief Shape copy constructor (Disabled)
         */
        Shape(const Shape&) = delete;
        /*!
         * \brief operator =  copy assignment (disabled)
         * \return This Shape
         */
        Shape& operator=(const Shape&) = delete;

        /*!
         * \brief Checks to see if two Shape ids are equal
         * \param Shape 2
         * \return result of comparison
         */
        bool operator==(const Shape& s2){return id == s2.id;}

        /*!
         * \brief Checks to see if Shape 1's id is less than Shape 2's id
         * \param Shape 2
         * \return result of comparison
         */
        bool operator<(const Shape& s2){return id<s2.id;}

        /*!
         * \brief Gets the area of the given shape
         * \return Area as a double
         */
        virtual double getArea(){return 0.0;}

        /*!
         * \brief Gets the perimeter of the given shape
         * \return Perimeter as a double
         */
        virtual double getPerimeter(){return 0.0;}

        /*!
         * \brief Gets the type of the shape
         * \return type as an int
         */
        virtual int getType() = 0;

        /*!
         * \brief ~Shape
         */
        virtual ~Shape(){}
    private:

        /*!
         * \brief id of shape
         */
        unsigned int id;
};

/*!
 * \brief Saves a vector of shape pointers to a file
 * \param vector of shapes
 * \param filename as c-string
 */
void shape_saver(myStd::vector<Shape*>& vec, const char* filename);
#endif // SHAPE_H
