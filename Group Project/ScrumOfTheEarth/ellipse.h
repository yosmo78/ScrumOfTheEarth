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
        virtual void draw(QPainter & paint);
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
