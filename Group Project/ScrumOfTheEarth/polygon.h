#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"
#include "vector.h"
#include <cmath>
class Polygon : public Shape
{
    Q_OBJECT
   public:
    Polygon(unsigned int, myStd::vector<QPoint>, Qt::GlobalColor, Qt::GlobalColor, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle, Qt::BrushStyle, int);
    QPoint getPoint(int i){return polyPoint[i];} //Polygon specific
    QPoint * getPolyPoints(){return polyPoint.begin();}
    int getNumOfPoints() {return polyPoint.size();}
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
    virtual void draw(QPainter&,bool);
    virtual int getType(){return 3;}
    static int getStaticType(){return 3;}
    virtual double getArea()
    {
        myStd::vector<QPoint>::iterator it = polyPoint.begin();
        if(polyPoint.size() == 0) return 0;
        double area = 0;
        int i = 0;
        double avgHeight = 0,width = 0;
        for(; i < (polyPoint.size()-1); ++i)
        {
            avgHeight = 0; width = 0;
            avgHeight = (it[i].y()+it[i+1].y())/2;
            width = it[i+1].x()-it[i].x();
            area += avgHeight * width;
        }
        avgHeight = (it[i].y()+polyPoint.begin()->y())/2;
        width = polyPoint.begin()->x()-it[i].x();
        area += avgHeight * width;

        return fabs(area);
    }
    virtual double getPerimeter()
    {
        myStd::vector<QPoint>::iterator it = polyPoint.begin();
        if(polyPoint.size() == 0) return 0;
        double perimeter = 0;
        int i = 0;
        for(; i < (polyPoint.size()-1); ++i)
        {
           perimeter += std::sqrt(((it[i].x()-it[i+1].x())*((it[i].x()-it[i+1].x()))+((it[i].y()-it[i+1].y())*(it[i].y()-it[i+1].y()))));
        }
        perimeter += std::sqrt(((it[i].x()-polyPoint.begin()->x())*((it[i].x()-polyPoint.begin()->x()))+((it[i].y()-polyPoint.begin()->y())*(it[i].y()-polyPoint.begin()->y()))));
        return perimeter;
    }
   private:
    myStd::vector<QPoint> polyPoint; //Polygon specific
    Qt::GlobalColor penColor;
    Qt::GlobalColor brushColor;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle penCapStyle;
    Qt::PenJoinStyle penJoinStyle;
    Qt::BrushStyle brushStyle;
    int penWidth;
};

#endif // POLYGON_H
