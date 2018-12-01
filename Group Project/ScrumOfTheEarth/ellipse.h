#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"

class Ellipse : public Shape
{
    Q_OBJECT

    public:
        Ellipse();
        QPoint getTopLeft(){return point;}
        int getMajorAxis(){return major;}
        int getMinorAxis(){return minor;}
        void setTopLeft(QPoint p){point = p;}
        void setMajorAxis(int j){major = j;}
        void setMinorAxis(int n){minor = n;}
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
    private:
        QPoint point;
        int major;
        int minor;
        Qt::GlobalColor penColor;
        Qt::GlobalColor brushColor;
        Qt::PenStyle penStyle;
        Qt::PenCapStyle penCapStyle;
        Qt::PenJoinStyle penJoinStyle;
        Qt::BrushStyle brushStyle;
        int penWidth;
};

#endif // ELLIPSE_H
