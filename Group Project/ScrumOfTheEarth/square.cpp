#include "square.h"
#include <QRect>

Square::Square(QPaintDevice* pptr, unsigned int i, int x, int y, int l, Qt::GlobalColor pc, Qt::GlobalColor bc, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs, Qt::BrushStyle bs, int pw):
    Shape(pptr,i), CornerPoint(x,y), length(l),penColor(pc), brushColor(bc),penStyle(ps),penCapStyle(pcs),penJoinStyle(pjs),brushStyle(bs),penWidth(pw){}

 void Square::draw()
{
  QBrush b(brushColor,brushStyle);
  QPen pen(b,qreal(penWidth),penStyle,penCapStyle,penJoinStyle);
  getPainter().setPen(pen);
  getPainter().drawRect(QRect(CornerPoint, QSize(length, length) ));
}
