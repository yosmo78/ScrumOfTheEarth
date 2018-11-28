#include "ellipse.h"
Ellipse::Ellipse(unsigned int i, int x, int y, int a, int b, Qt::GlobalColor pc, Qt::GlobalColor bc, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs, Qt::BrushStyle bs, int pw):
    Shape(i), point(x,y), penColor(pc), brushColor(bc),penStyle(ps),penCapStyle(pcs),penJoinStyle(pjs),brushStyle(bs),penWidth(pw){major = a; minor = b;}

void Ellipse::draw(QPainter & paint)
{
 QBrush b(brushColor,brushStyle);
 QPen pen(b,qreal(penWidth),penStyle,penCapStyle,penJoinStyle);
 paint.setPen(pen);
 paint.drawEllipse(QRect(point, QSize(major*2, minor*2) ));
}
