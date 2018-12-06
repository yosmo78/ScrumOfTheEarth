/*! \file */
#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"
#include "vector.h"
#include <cmath>
/*!
 * \brief Polygon class that QPainter can draw
 */
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
    /*!
     * \brief Gets the pen color stored in this shape
     * \return Color of the pen
     */
    Qt::GlobalColor getPenColor() {return penColor;}

    /*!
     * \brief Gets the Brush color stored in the Shape
     * \return Color of the Brush
     */
    Qt::GlobalColor getBrushColor(){return brushColor;}

    /*!
     * \brief Sets the color of the pen to the given color
     * \param penColor
     */
    void setPenColor(Qt::GlobalColor pc){penColor = pc;}

    /*!
     * \brief Sets the color of the Brush to the given color
     * \param brushColor
     */
    void setBrushColor(Qt::GlobalColor bc){brushColor = bc;}

    /*!
     * \brief Gets the style of the pen stored in the shape
     * \return Style of the pen
     */
    Qt::PenStyle getPenStyle(){return penStyle;}

    /*!
     * \brief Sets the style of the pen to the given style
     * \param penStyle
     */
    void setPenStyle(Qt::PenStyle ps){penStyle = ps;}

    /*!
     * \brief Gets the pen cap style that is stored in this Shape
     * \return PenCapStyle
     */
    Qt::PenCapStyle getPenCapStyle() {return penCapStyle;}

    /*!
     * \brief Sets the Pen Cap Style to the given Pen Cap Style
     * \param penCapStyle
     */
    void setPenCapStyle(Qt::PenCapStyle pcs){ penCapStyle = pcs;}

    /*!
     * \brief Gets the Pen Join Style
     * \return PenJoinStyle
     */
    Qt::PenJoinStyle getPenJoinStyle(){return penJoinStyle;}

    /*!
     * \brief Sets the pen join style to the given style
     * \param penJoinStyle
     */
    void setPenJoinStyle(Qt::PenJoinStyle pjs){penJoinStyle = pjs;}

    /*!
     * \brief Gets the Brush Style
     * \return BrushStyle
     */
    Qt::BrushStyle getBrushStyle(){return brushStyle;}

    /*!
     * \brief Sets the Brush Style to the given Brush Style
     * \param brushStyle
     */
    void setBrushStyle(Qt::BrushStyle bs){brushStyle = bs;}

    /*!
     * \brief Gets the width of the pen
     * \return penWidth
     */
    int getPenWidth(){return penWidth;}

    /*!
     * \brief Sets the width of the pen to the given width
     * \param penWidth
     */
    void setPenWidth(int pw){penWidth = pw;}
    virtual void draw(QPainter&,bool);
    virtual int getType(){return 3;}
    /*!
     * \brief gets the Type of object
     * \return Type as int
     */
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
