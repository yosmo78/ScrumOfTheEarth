#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"


/*!
 * \brief Circle class that QPainter can draw
 */
class Circle : public Shape
{
    Q_OBJECT
   public:
    /*!
     * \brief All properties contructor
     * \param id
     * \param x coordinate
     * \param y coordinate
     * \param radius
     * \param penColor
     * \param brushColor
     * \param penStyle
     * \param penCapStyle
     * \param penJoinStyle
     * \param brushStyle
     * \param penWidth
     */
    Circle(unsigned int i, int x, int y, int r, Qt::GlobalColor pc, Qt::GlobalColor bc, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs, Qt::BrushStyle bs, int pw);//line specific

    /*!
     * \brief Gets the center of the circle as a point
     * \return Center of circle as QPoint
     */
    QPoint getPoint1(){return point;} //circle specific

    /*!
     * \brief Gets the radius of the circle
     * \return radius
     */
    int getRadius(){return radius;}//circle specific

    /*!
     * \brief Sets the center of the circle to the given point
     * \param Center Point
     */
    void setPoint1(QPoint p1){point = p1;} //circle specific

    /*!
     * \brief Sets the radius
     * \param radius
     */
    void setPoint2(int r){radius = r;} //circle specific

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
    virtual void draw(QPainter & paint, bool);
    virtual int getType(){return 4;}

    /*!
     * \brief Gets the type of object
     * \return Type as int
     */
    static int getStaticType(){return 4;}
    virtual double getArea(){return 3.14159265359*radius*radius;}
    virtual double getPerimeter(){return 3.14159265359*2*radius;}
   private:
    QPoint point;
    int radius;
    Qt::GlobalColor penColor;
    Qt::GlobalColor brushColor;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle penCapStyle;
    Qt::PenJoinStyle penJoinStyle;
    Qt::BrushStyle brushStyle;
    int penWidth;

};

#endif // CIRCLE_H
