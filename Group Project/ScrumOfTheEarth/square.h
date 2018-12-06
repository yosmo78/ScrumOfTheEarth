/*! \file */
#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"
#include "vector.h"
/*!
 * \brief Square class that QPainter can draw
 */
class Square : public Shape
{
    Q_OBJECT

   public:
    /*!
     * \brief Square all parameter constructor
     */
    Square(unsigned int, int, int, int, Qt::GlobalColor, Qt::GlobalColor, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle, Qt::BrushStyle, int);
    /*!
     * \brief Gets the corner point of the square
     * \return QPoint of the top left corner
     */
    QPoint getCornerPoint(){return CornerPoint;} //Square specific
    /*!
     * \brief Sets the corner point of the square to the given point
     * \param p1 QPoint of top left corner
     */
    void setCornerPoint(QPoint p1){CornerPoint = p1;} //Square specific
    /*!
     * \brief Gets the length of the square
     * \return int length of square
     */
    int getLength(){return length;} //Square specific
    /*!
     * \brief Sets the length of the square
     * \param l length of square
     */
    void setLength(int l){length = l;} //Square specific
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
    virtual int getType(){return 1;}
    /*!
     * \brief gets the Type of object
     * \return Type as int
     */
    static int getStaticType(){return 1;}
    virtual double getArea(){return (double)length*length;}
    virtual double getPerimeter(){return (double)(4*length);}
   private:
    QPoint CornerPoint; //Square specific
    int length; //Square specific
    Qt::GlobalColor penColor;
    Qt::GlobalColor brushColor;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle penCapStyle;
    Qt::PenJoinStyle penJoinStyle;
    Qt::BrushStyle brushStyle;
    int penWidth;
};

#endif // SQUARE_H
