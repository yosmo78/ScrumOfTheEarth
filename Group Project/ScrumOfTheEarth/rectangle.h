#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
#include "vector.h"

class Rectangle : public Shape
{
    Q_OBJECT

   public:
    Rectangle(unsigned int, int, int, int, int, Qt::GlobalColor, Qt::GlobalColor, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle, Qt::BrushStyle, int);
    QPoint getCornerPoint(){return CornerPoint;} //Rectangle specific
    void setCornerPoint(QPoint p1){CornerPoint = p1;} //Rectangle specific
    int getLength(){return length;} //Rectangle specific
    void setLength(int l){length = l;} //Rectangle specific
    int getWidth(){return width;} //Rectangle specific
    void setWidth(int w){width = w;} //Rectangle specific
    Qt::GlobalColor getPenColor() {return penColor;}
    Qt::GlobalColor getBrushColor(){return brushColor;}
    void setPenColor(Qt::GlobalColor pc){penColor = pc;}
    void setBrushColor(Qt::GlobalColor bc){brushColor = bc;}
    Qt::PenStyle getPenStyle(){return penStyle;}
    void setPenStyle(Qt::PenStyle ps){penStyle = ps;}
    Qt::PenCapStyle getPenCapStyle() {return penCapStyle;}
    void setPenCapStyle(Qt::PenCapStyle pcs){ penCapStyle = pcs;}
    Qt::PenJoinStyle getPenJoinStyle(){return penJoinStyle;}
    void setPenJoinStyle(Qt::PenJoinStyle pjs){penJoinStyle = pjs;}
    Qt::BrushStyle getBrushStyle(){return brushStyle;}
    void setBrushStyle(Qt::BrushStyle bs){brushStyle = bs;}
    int getPenWidth(){return penWidth;}
    void setPenWidth(int pw){penWidth = pw;}
    virtual void draw(QPainter &);
   private:
    QPoint CornerPoint; //Rectangle specific
    int length; //Rectangle specific
    int width; //Rectangle specific
    Qt::GlobalColor penColor;
    Qt::GlobalColor brushColor;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle penCapStyle;
    Qt::PenJoinStyle penJoinStyle;
    Qt::BrushStyle brushStyle;
    int penWidth;

};

#endif // RECTANGLE_H
