#include "rectangle.h"

Rectangle::Rectangle(unsigned int i, int x, int y, int l, int w, Qt::GlobalColor pc, Qt::GlobalColor bc, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs, Qt::BrushStyle bs, int pw):
    Shape(i), CornerPoint(x,y), length(l),width(w),penColor(pc), brushColor(bc),penStyle(ps),penCapStyle(pcs),penJoinStyle(pjs),brushStyle(bs),penWidth(pw){}

void Rectangle::draw(QPainter & paint)
{
  QBrush b(brushColor,brushStyle);
  QBrush p(penColor);
  QPen pen(p,qreal(penWidth),penStyle,penCapStyle,penJoinStyle);
  paint.setPen(pen);
  paint.setBrush(b);
  paint.drawRect(QRect(CornerPoint, QSize(width, length) ));
}
