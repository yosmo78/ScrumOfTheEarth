#include "polygon.h"

Polygon::Polygon(unsigned int i, myStd::vector<QPoint> vec, Qt::GlobalColor pc, Qt::GlobalColor bc, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs, Qt::BrushStyle bs, int pw):
    Shape(i), polyPoint(vec),penColor(pc), brushColor(bc),penStyle(ps),penCapStyle(pcs),penJoinStyle(pjs),brushStyle(bs),penWidth(pw){}
void Polygon::draw(QPainter& paint)
{
 QBrush b(brushColor,brushStyle);
 QPen pen(b,qreal(penWidth),penStyle,penCapStyle,penJoinStyle);
 paint.setPen(pen);
 paint.drawPolygon(polyPoint.begin(),polyPoint.size());
}
