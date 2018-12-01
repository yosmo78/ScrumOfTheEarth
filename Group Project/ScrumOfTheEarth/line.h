#ifndef LINE_H
#define LINE_H
#include "shape.h"

class Line : public Shape
{
    Q_OBJECT
   public:
    Line(unsigned int, int, int, int, int, Qt::GlobalColor, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle, int);//line specific
    QPoint getPoint1(){return point1;} //line specific
    QPoint getPoint2(){return point2;} //line specific
    void setPoint1(QPoint p1){point1 = p1;} //line specific
    void setPoint2(QPoint p2){point2 = p2;} //line specific
    Qt::GlobalColor getPenColor() {return penColor;}
    void setPenColor(Qt::GlobalColor pc){penColor = pc;}
    Qt::PenStyle getPenStyle(){return penStyle;}
    void setPenStyle(Qt::PenStyle ps){penStyle = ps;}
    Qt::PenCapStyle getPenCapStyle() {return penCapStyle;}
    void setPenCapStyle(Qt::PenCapStyle pcs){ penCapStyle = pcs;}
    Qt::PenJoinStyle getPenJoinStyle(){return penJoinStyle;}
    void setPenJoinStyle(Qt::PenJoinStyle pjs){penJoinStyle = pjs;}
    int getPenWidth(){return penWidth;}
    void setPenWidth(int pw){penWidth = pw;}
    virtual void draw(QPainter & paint);
    virtual int getType(){return 6;}
    static int getStaticType(){return 6;}
   private:
    QPoint point1; //line specific
    QPoint point2; //line specific
    Qt::GlobalColor penColor;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle penCapStyle;
    Qt::PenJoinStyle penJoinStyle;
    int penWidth;
};


#endif // LINE_H
