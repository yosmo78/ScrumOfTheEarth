#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"
#include <cmath>

/*!
 * \brief Ellipse class that QPainter can draw
 */
class Ellipse : public Shape
{
    Q_OBJECT

    public:
        /*!
         * \brief All element contructor
         */
        Ellipse(unsigned int, int, int, int, int, Qt::GlobalColor, Qt::GlobalColor, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle, Qt::BrushStyle, int);

        /*!
         * \brief Gets the point to the top left corner
         * \return QPoint of the top left corner of the drawing rectangle
         */
        QPoint getTopLeft(){return point;}
        /*!
         * \brief Gets the length of the semimajor axis
         * \return length of semimajor axis
         */
        int getMajorAxis(){return semimajor;}

        /*!
         * \brief Gets the length of the semiminor axis
         * \return length of semiminor axis
         */
        int getMinorAxis(){return semiminor;}

        /*!
         * \brief Sets the coordinates of the top left corner of the drawing rectangle
         * \param QPoint of top left corner
         */
        void setTopLeft(QPoint p){point = p;}
        /*!
         * \brief Sets the length of the semimajor axis
         * \param length of semimajor axis
         */
        void setMajorAxis(int j){semimajor = j;}
        /*!
         * \brief Sets the length of the semiminor axis
         * \param length of semiminor axis
         */
        void setMinorAxis(int n){semiminor = n;}
        /*!
         * \brief Gets the pen color stored in this shape
         * \return Color of the pen
         */
        Qt::GlobalColor getPenColor() {return penColor;}

        /*!
         * \brief Gets the Brush color stored in the Shape
         * \return Color of the Brush
         */
        Qt::GlobalColor getBrushColor(){return brushColor;}

        /*!
         * \brief Sets the color of the pen to the given color
         * \param penColor
         */
        void setPenColor(Qt::GlobalColor pc){penColor = pc;}

        /*!
         * \brief Sets the color of the Brush to the given color
         * \param brushColor
         */
        void setBrushColor(Qt::GlobalColor bc){brushColor = bc;}

        /*!
         * \brief Gets the style of the pen stored in the shape
         * \return Style of the pen
         */
        Qt::PenStyle getPenStyle(){return penStyle;}

        /*!
         * \brief Sets the style of the pen to the given style
         * \param penStyle
         */
        void setPenStyle(Qt::PenStyle ps){penStyle = ps;}

        /*!
         * \brief Gets the pen cap style that is stored in this Shape
         * \return PenCapStyle
         */
        Qt::PenCapStyle getPenCapStyle() {return penCapStyle;}

        /*!
         * \brief Sets the Pen Cap Style to the given Pen Cap Style
         * \param penCapStyle
         */
        void setPenCapStyle(Qt::PenCapStyle pcs){ penCapStyle = pcs;}

        /*!
         * \brief Gets the Pen Join Style
         * \return PenJoinStyle
         */
        Qt::PenJoinStyle getPenJoinStyle(){return penJoinStyle;}

        /*!
         * \brief Sets the pen join style to the given style
         * \param penJoinStyle
         */
        void setPenJoinStyle(Qt::PenJoinStyle pjs){penJoinStyle = pjs;}

        /*!
         * \brief Gets the Brush Style
         * \return BrushStyle
         */
        Qt::BrushStyle getBrushStyle(){return brushStyle;}

        /*!
         * \brief Sets the Brush Style to the given Brush Style
         * \param brushStyle
         */
        void setBrushStyle(Qt::BrushStyle bs){brushStyle = bs;}

        /*!
         * \brief Gets the width of the pen
         * \return penWidth
         */
        int getPenWidth(){return penWidth;}

        /*!
         * \brief Sets the width of the pen to the given width
         * \param penWidth
         */
        void setPenWidth(int pw){penWidth = pw;}
        virtual void draw(QPainter & paint,bool);
        virtual int getType(){return 5;}
        /*!
         * \brief gets the Type of object
         * \return Type as int
         */
        static int getStaticType(){return 5;}
        virtual double getArea(){return 3.14159265359*semimajor*semiminor;}
        virtual double getPerimeter(){return 3.14159265359*(3*(2*semimajor+2*semiminor)-(std::sqrt((3*(2*semimajor)+(2*semiminor))*((2*semimajor)+3*(2*semiminor)))));}
    private:
        QPoint point;
        int semimajor;//a
        int semiminor;//b
        Qt::GlobalColor penColor;
        Qt::GlobalColor brushColor;
        Qt::PenStyle penStyle;
        Qt::PenCapStyle penCapStyle;
        Qt::PenJoinStyle penJoinStyle;
        Qt::BrushStyle brushStyle;
        int penWidth;
};

#endif // ELLIPSE_H
