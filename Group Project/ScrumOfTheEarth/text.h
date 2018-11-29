#ifndef TEXT_H
#define TEXT_H
#include "shape.h"

class Text : public Shape
{
    Q_OBJECT
   public:
    Text(unsigned int, int, int, int, int, QString, Qt::GlobalColor, Qt::AlignmentFlag, int, QString, QFont::Style, QFont::Weight);
    QPoint getCornerPoint(){return CornerPoint;} //Text specific
    void setCornerPoint(QPoint p1){CornerPoint = p1;} //Text specific
    int getLength(){return length;} //Text specific
    void setLength(int l){length = l;} //Text specific
    int getWidth(){return width;} //Text specific
    void setWidth(int w){width = w;} //Text specific
    QString getTextString(){return textString;} //Text specific
    void setTextString(QString ts){textString = ts;} //Text specific
    Qt::GlobalColor getGlobalColor(){return textColor;} //Text specific
    void setGlobalColor(Qt::GlobalColor gc){textColor = gc;} //Text specific
    Qt::AlignmentFlag getAlignmentFlag(){return textAlignment;} //Text specific
    void setAlignmentFlag(Qt::AlignmentFlag af){textAlignment = af;} //Text specific
    int getTextPointSize(){return textPointSize;} //Text specific
    void setTextPointSize(int ts){textPointSize = ts;} //Text specific
    QString getTextFontFamily(){return textFontFamily;} //Text specific
    void setTextFontFamily(QString tff){textFontFamily = tff;} //Text specific
    QFont::Style getTextFontStyle(){return textFontStyle;} //Text specific
    void setTextFontStyle(QFont::Style tfs){textFontStyle = tfs;} //Text specific
    QFont::Weight getTextFontWeight(){return textFontWeight;} //Text specific
    void setTextFontWeight(QFont::Weight tfw){textFontWeight = tfw;} //Text specific
    virtual void draw(QPainter&);
    virtual int getType(){return 8;}
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
