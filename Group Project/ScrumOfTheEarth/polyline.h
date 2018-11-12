#ifndef POLYLINE_H
#define POLYLINE_H
#include "vector.h"
#include "shape.h"

class Polyline: public Shape
{
    Q_OBJECT
  public:
    Polyline();
    vector<QPoint> getPoints(){return points;} //polyline specific
    void setPoint1(vector<QPoint> pts){points = pts;} //polyline specific
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
    myStd::vector<QPoint> points;
    Qt::GlobalColor penColor;
    Qt::GlobalColor brushColor;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle penCapStyle;
    Qt::PenJoinStyle penJoinStyle;
    Qt::BrushStyle brushStyle;
    int penWidth;
    QPainter painter;
};

#endif // POLYLINE_H
