#include "rectangle.h"

Rectangle::Rectangle(QPaintDevice* pptr, unsigned int i, int x, int y, int l, int w, Qt::GlobalColor pc, Qt::GlobalColor bc, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs, Qt::BrushStyle bs, int pw):
    Shape(pptr,i), CornerPoint(x,y), length(l),width(w),penColor(pc), brushColor(bc),penStyle(ps),penCapStyle(pcs),penJoinStyle(pjs),brushStyle(bs),penWidth(pw){}

void Rectangle::draw()
{
 QBrush b(brushColor,brushStyle);
 QPen pen(b,qreal(penWidth),penStyle,penCapStyle,penJoinStyle);
 getPainter().setPen(pen);
 getPainter().drawRect(QRect(CornerPoint, QSize(width, length) ));
}
