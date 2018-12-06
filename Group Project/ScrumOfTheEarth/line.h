/*! \file */
#ifndef LINE_H
#define LINE_H
#include "shape.h"
#include <cmath>
/*!
 * \brief Line class that QPainter can draw
 */
class Line : public Shape
{
    Q_OBJECT
   public:
    /*!
     * \brief All parameter constructor for Line
     */
    Line(unsigned int, int, int, int, int, Qt::GlobalColor, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle, int);//line specific
    /*!
     * \brief Gets the first point of the line
     * \return QPoint of the first point
     */
    QPoint getPoint1(){return point1;} //line specific
    /*!
     * \brief Gets the second point of the line
     * \return QPoint of the second point
     */
    QPoint getPoint2(){return point2;} //line specific
    /*!
     * \brief Sets the first point to the given point
     * \param QPoint for the first point
     */
    void setPoint1(QPoint p1){point1 = p1;} //line specific
    /*!
     * \brief Sets the second point to the given point
     * \param QPoint of the second point
     */
    void setPoint2(QPoint p2){point2 = p2;} //line specific
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
    virtual void draw(QPainter & paint,bool);
    virtual int getType(){return 6;}
    /*!
     * \brief gets the Type of object
     * \return Type as int
     */
    static int getStaticType(){return 6;}
    virtual double getPerimeter(){return std::sqrt(((point1.x()-point2.x())*(point1.x()-point2.x()))+((point1.y()-point2.y())*(point1.y()-point2.y())));}
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
