#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

class Square : public Shape
{
    Q_OBJECT

   public:
    Square();
    QPoint getCornerPoint(){return CornerPoint;} //Square specific
    void setCornerPoint(QPoint p1){CornerPoint = p1;} //Square specific
    int getLength(){return lenght;} //Square specific
    void setLenght(int l){lenght = l;} //Square specific
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
    QPoint CornerPoint; //Square specific
    int lenght; //Square specific
    Qt::GlobalColor penColor;
    Qt::GlobalColor brushColor;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle penCapStyle;
    Qt::PenJoinStyle penJoinStyle;
    Qt::BrushStyle brushStyle;
    int penWidth;
    QPainter painter;
};

#endif // SQUARE_H
