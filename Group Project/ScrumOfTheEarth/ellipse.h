#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"
#include <cmath>
class Ellipse : public Shape
{
    Q_OBJECT

    public:
        Ellipse(unsigned int, int, int, int, int, Qt::GlobalColor, Qt::GlobalColor, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle, Qt::BrushStyle, int);
        QPoint getTopLeft(){return point;}
        int getMajorAxis(){return semimajor;}
        int getMinorAxis(){return semiminor;}
        void setTopLeft(QPoint p){point = p;}
        void setMajorAxis(int j){semimajor = j;}
        void setMinorAxis(int n){semiminor = n;}
        /*!
            Returns the color of the pen
        */
        Qt::GlobalColor getPenColor() {return penColor;}

        /*!
            Returns the color of the brush
        */
        Qt::GlobalColor getBrushColor(){return brushColor;}

        /*!
            Sets the pen color to the given color
        */
        void setPenColor(Qt::GlobalColor pc){penColor = pc;}

        /*!
            Sets the color of the brush to the given brush
        */
        void setBrushColor(Qt::GlobalColor bc){brushColor = bc;}

        /*!
            Returns the style of the pen
        */
        Qt::PenStyle getPenStyle(){return penStyle;}

        /*!
            Sets the pen style to the given style
        */
        void setPenStyle(Qt::PenStyle ps){penStyle = ps;}

        /*!
             Returns the cap style of the pen
        */
        Qt::PenCapStyle getPenCapStyle() {return penCapStyle;}

        /*!
            Sets the pen cap style to the given pen cap style
        */
        void setPenCapStyle(Qt::PenCapStyle pcs){ penCapStyle = pcs;}

        /*!
            Returns the join style of the pen
        */
        Qt::PenJoinStyle getPenJoinStyle(){return penJoinStyle;}

        /*!
            Sets the pen join style to the given pen join style
        */
        void setPenJoinStyle(Qt::PenJoinStyle pjs){penJoinStyle = pjs;}

        /*!
            Returns the brush style
        */
        Qt::BrushStyle getBrushStyle(){return brushStyle;}

        /*!
            Sets the brush style to the given style
        */
        void setBrushStyle(Qt::BrushStyle bs){brushStyle = bs;}

        /*!
            Returns the width of the pen
        */
        int getPenWidth(){return penWidth;}

        /*!
            Sets the pen width to the given width
        */
        void setPenWidth(int pw){penWidth = pw;}
        virtual void draw(QPainter & paint,bool);
        virtual int getType(){return 5;}
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
