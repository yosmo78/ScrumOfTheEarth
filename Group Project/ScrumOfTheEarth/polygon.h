#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"
#include "vector.h"

class Polygon : public Shape
{
    Q_OBJECT
   public:
    Polygon();
    QPoint getPoint(int i){return polyPoint[i];} //Polygon specific
    void setVector(myStd::vector<QPoint> v){polyPoint = v;} //Polygon specific
    void setPoint(QPoint p, int i){polyPoint[i] = p;} //Polygon specific
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
    myStd::vector<QPoint> polyPoint; //Polygon specific
    Qt::GlobalColor penColor;
    Qt::GlobalColor brushColor;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle penCapStyle;
    Qt::PenJoinStyle penJoinStyle;
    Qt::BrushStyle brushStyle;
    int penWidth;
    QPainter painter;
};

#endif // POLYGON_H
