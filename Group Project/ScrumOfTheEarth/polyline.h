/*! \file */
#ifndef POLYLINE_H
#define POLYLINE_H
#include "vector.h"
#include "shape.h"
#include <cmath>
/*!
 * \brief Polyline class that QPainter can draw
 */
class Polyline: public Shape
{
    Q_OBJECT
  public:
    /*!
     * \brief All parameter constructor
     */
    Polyline(unsigned int, myStd::vector<QPoint>&, Qt::GlobalColor, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle, int);
    /*!
     * \brief Gets the vector of QPoints that make up the polyline
     * \return vector of QPoints
     */
    myStd::vector<QPoint>& getPoints(){return points;} //polyline specific
    /*!
     * \brief Sets the vector of QPoints that make up the polyline to the given vector of QPoints
     * \param pts vector of QPoints
     */
    void setPoints(const myStd::vector<QPoint>& pts){points = pts;} //polyline specific
    /*!
     * \brief Gets the number of points that make up the polyline
     * \return int number of QPoints
     */
    int getNumOfPoints(){return points.size();}
    /*!
     * \brief Gets the pen color stored in this shape
     * \return Color of the pen
     */
    Qt::GlobalColor getPenColor() {return penColor;}


    /*!
     * \brief Sets the color of the pen to the given color
     * \param penColor
     */
    void setPenColor(Qt::GlobalColor pc){penColor = pc;}

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
    virtual int getType(){return 7;}
    /*!
     * \brief gets the Type of object
     * \return Type as int
     */
    static int getStaticType(){return 7;}
    virtual double getPerimeter()
    {
        myStd::vector<QPoint>::iterator it = points.begin();
        if(points.size() == 0) return 0;
        double perimeter = 0;
        int i = 0;
        for(; i < (points.size()-1); ++i)
        {
           perimeter += std::sqrt(((it[i].x()-it[i+1].x())*((it[i].x()-it[i+1].x()))+((it[i].y()-it[i+1].y())*(it[i].y()-it[i+1].y()))));
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
