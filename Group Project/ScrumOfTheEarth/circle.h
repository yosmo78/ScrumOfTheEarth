#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"


//! \class Circle
/*!
    Derived Class Circle holds all properties for a QPainter to draw it
*/
class Circle : public Shape
{
    Q_OBJECT
   public:
    /*!
        All properties Constructor
    */
    Circle(unsigned int i, int x, int y, int r, Qt::GlobalColor pc, Qt::GlobalColor bc, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs, Qt::BrushStyle bs, int pw);//line specific

    /*!
        Returns the center of the circle
    */
    QPoint getPoint1(){return point;} //circle specific

    /*!
        Returns the radius of the circle
    */
    int getRadius(){return radius;}//circle specific

    /*!
        Sets the center of the circle to the given point
    */
    void setPoint1(QPoint p1){point = p1;} //circle specific

    /*!
        Sets the radius to the given value
    */
    void setPoint2(int r){radius = r;} //circle specific

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
    virtual void draw(QPainter & paint, bool);
    virtual int getType(){return 4;}

    /*!
        Returns the type as an int
    */
    static int getStaticType(){return 4;}
    virtual double getArea(){return 3.14159265359*radius*radius;}
    virtual double getPerimeter(){return 3.14159265359*2*radius;}
   private:
    QPoint point;
    int radius;
    Qt::GlobalColor penColor;
    Qt::GlobalColor brushColor;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle penCapStyle;
    Qt::PenJoinStyle penJoinStyle;
    Qt::BrushStyle brushStyle;
    int penWidth;

};

#endif // CIRCLE_H
