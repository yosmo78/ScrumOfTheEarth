#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape
{
    Q_OBJECT
   public:
    Rectangle();

    QPoint getCornerPoint(){return CornerPoint;} //Rectangle specific
    void setPoint1(QPoint p1){CornerPoint = p1;} //Rectangle specific
    int getLength(){return lenght;} // Rectangle specific
    void setLenght(int l){lenght = l;} // Rectangle specific
    int getWidth(){return width;} // Rectangle specific
    void setWidth(int w){width = w;} // Rectangle specific
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
    QPainter& getPainter(){return painter;}
   private:
    QPoint CornerPoint; //Rectangle specific
    int lenght;
    int width;
    Qt::GlobalColor penColor;
    Qt::GlobalColor brushColor;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle penCapStyle;
    Qt::PenJoinStyle penJoinStyle;
    Qt::BrushStyle brushStyle;
     int penWidth;
    QPainter painter;
};

#endif // RECTANGLE_H
