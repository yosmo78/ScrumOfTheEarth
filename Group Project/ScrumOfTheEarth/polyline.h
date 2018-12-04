#ifndef POLYLINE_H
#define POLYLINE_H
#include "vector.h"
#include "shape.h"
#include <cmath>

class Polyline: public Shape
{
    Q_OBJECT
  public:
    Polyline(unsigned int, myStd::vector<QPoint>&, Qt::GlobalColor, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle, int);
    myStd::vector<QPoint>& getPoints(){return points;} //polyline specific
    void setPoints(const myStd::vector<QPoint>& pts){points = pts;} //polyline specific
    int getNumOfPoints(){return points.size();}
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
    virtual void draw(QPainter&);
    virtual int getType(){return 7;}
    static int getStaticType(){return 7;}
    virtual double getPerimeter()
    {
        myStd::vector<QPoint>::iterator it = points.begin();
        if(points.size() == 0) return 0;
        double perimeter = 0;
        int i = 0;
        for(; i < (points.size()-1); ++i)
        {
//           perimeter += std::sqrt(((it[i].x()-it[i+1].x())*((it[i].x()-it[i+1].x()))+((it[i].y()-it[i+1].y())*(it[i].y()-it[i+1].y()))));
        }
        return perimeter;
    }
  private:
    myStd::vector<QPoint> points;
    Qt::GlobalColor penColor;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle penCapStyle;
    Qt::PenJoinStyle penJoinStyle;
    int penWidth;
};

#endif // POLYLINE_H
