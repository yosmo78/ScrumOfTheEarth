#include "text.h"

Text::Text(unsigned int i, int x, int y, int l, int w, QString txt, Qt::GlobalColor tc, Qt::AlignmentFlag ta, int tps, QString tff, QFont::Style tfs, QFont::Weight tfw) :
    Shape(i), CornerPoint(x,y), length(l), width(w), textString(txt), textColor(tc), textAlignment(ta), textPointSize(tps), textFontFamily(tff), textFontStyle(tfs), textFontWeight(tfw){}



void Text::draw(QPainter & paint)
{

 QPen pen(textColor);
 paint.setPen(pen);

 QFont newfont(textFontFamily,textPointSize,textFontWeight);
 QFont oldfont = paint.font();
 paint.setFont(newfont);
 paint.drawText(CornerPoint.x(),CornerPoint.y(), width, length, textAlignment, textString);
 paint.setFont(oldfont);
 paint.drawText(CornerPoint.x() + (length/2 - 3 * std::to_string(getShapeId()).length()), CornerPoint.y() - 5,QString::fromStdString(std::to_string(getShapeId())));

}
