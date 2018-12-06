/*! \file */
#ifndef TEXT_H
#define TEXT_H
#include "shape.h"
/*!
 * \brief Text class that QPainter can draw
 */
class Text : public Shape
{
    Q_OBJECT
   public:
    /*!
     * \brief Text all parameter constructor
     */
    Text(unsigned int, int, int, int, int, QString, Qt::GlobalColor, Qt::AlignmentFlag, int, QString, QFont::Style, QFont::Weight);
    /*!
     * \brief Gets the top left corner of the text drawing rectangle
     * \return QPoint top left corner
     */
    QPoint getCornerPoint(){return CornerPoint;} //Text specific
    /*!
     * \brief Sets the top left corner of the text drawing rectangle to the given QPoint
     * \param p1 QPoint
     */
    void setCornerPoint(QPoint p1){CornerPoint = p1;} //Text specific
    /*!
     * \brief Gets the length of the text drawing rectangle
     * \return int length
     */
    int getLength(){return length;} //Text specific
    /*!
     * \brief Sets the length of the drawing rectangle
     * \param l length of drawing rectangle
     */
    void setLength(int l){length = l;} //Text specific
    /*!
     * \brief Gets the width of the drawing rectangle
     * \return int width of rectangle
     */
    int getWidth(){return width;} //Text specific
    /*!
     * \brief Sets the width of the drawing rectangle to the given width
     * \param w width of drawing rectangle
     */
    void setWidth(int w){width = w;} //Text specific
    /*!
     * \brief Gets the string of text that is to be drawn
     * \return QString textString
     */
    QString getTextString(){return textString;} //Text specific
    /*!
     * \brief Sets the string of text to be drawn
     * \param ts QString of the text
     */
    void setTextString(QString ts){textString = ts;} //Text specific
    /*!
     * \brief Gets the color of the text
     * \return Qt::GlobalColor text color
     */
    Qt::GlobalColor getGlobalColor(){return textColor;} //Text specific
    /*!
     * \brief Sets the color of the text
     * \param gc Qt::GlobalColor for the text color
     */
    void setGlobalColor(Qt::GlobalColor gc){textColor = gc;} //Text specific
    /*!
     * \brief Gets the alignment flag of the text
     * \return Qt::AlignmentFlag alignment of text
     */
    Qt::AlignmentFlag getAlignmentFlag(){return textAlignment;} //Text specific
    /*!
     * \brief Sets the Alignment of the text
     * \param af Qt::ALignmentFlag
     */
    void setAlignmentFlag(Qt::AlignmentFlag af){textAlignment = af;} //Text specific
    /*!
     * \brief Gets the point size of the text
     * \return int pointSize
     */
    int getTextPointSize(){return textPointSize;} //Text specific
    /*!
     * \brief Sets the point size to the given point size
     * \param ts int Point size
     */
    void setTextPointSize(int ts){textPointSize = ts;} //Text specific
    /*!
     * \brief Gets the font family of the text
     * \return QString text font family
     */
    QString getTextFontFamily(){return textFontFamily;} //Text specific
    /*!
     * \brief Sets the font family of the text to the given font family
     * \param tff QString of the font family
     */
    void setTextFontFamily(QString tff){textFontFamily = tff;} //Text specific
    /*!
     * \brief Gets the Font Style of the text
     * \return QFont::Style
     */
    QFont::Style getTextFontStyle(){return textFontStyle;} //Text specific

    /*!
     * \brief Sets the font style of the text to the given font style
     * \param tfs QFont::Style
     */
    void setTextFontStyle(QFont::Style tfs){textFontStyle = tfs;} //Text specific
    /*!
     * \brief Gets the Font Weight of the text
     * \return QFont::Weight
     */
    QFont::Weight getTextFontWeight(){return textFontWeight;} //Text specific
    /*!
     * \brief Sets the Font Weight of the text to the given Font Weight
     * \param tfw QFont::Weight
     */
    void setTextFontWeight(QFont::Weight tfw){textFontWeight = tfw;} //Text specific
    virtual void draw(QPainter&,bool);
    virtual int getType(){return 8;}
    /*!
     * \brief gets the Type of object
     * \return Type as int
     */
    static int getStaticType(){return 8;}
   private:
    QPoint CornerPoint; //Text specific
    int length; //Text specific
    int width; //Text specific
    QString textString;//Text specific
    Qt::GlobalColor textColor;//Text specific
    Qt::AlignmentFlag textAlignment;//Text specific
    int textPointSize;//Text specific
    QString textFontFamily;//Text specific
    QFont::Style textFontStyle;//Text specific
    QFont::Weight textFontWeight; //Text specific
};

#endif // TEXT_H
