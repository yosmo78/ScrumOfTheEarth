#include "line.h"

Line::Line(unsigned int i, int x1, int y1, int x2, int y2, Qt::GlobalColor pc, Qt::GlobalColor bc, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs, Qt::BrushStyle bs, int pw):
    Shape(i), point1(x1, y1), point2(x2,y2), penColor(pc), brushColor(bc),penStyle(ps),penCapStyle(pcs),penJoinStyle(pjs),brushStyle(bs),penWidth(pw){}
void Line::draw(QPainter & paint)
{
 QBrush b(brushColor,brushStyle);
 QPen pen(b,qreal(penWidth),penStyle,penCapStyle,penJoinStyle);
 paint.setPen(pen);

 paint.drawLine(point1, point2);
 int lftx;
 int rghtx;
 int highy;

 if (point1.x() < point2.x())
 {
     lftx = point1.x();
     rghtx = point2.x();
 }
 else
 {
     lftx = point2.x();
     rghtx = point2.x();
 }
 if (point1.y() < point2.y())
 {
     highy = point1.y();
 }
 else
 {
     highy = point2.y();
 }

 paint.drawText(lftx+ (rghtx/2 - 3 * std::to_string(getShapeId()).length()), highy - 5,QString::fromStdString(std::to_string(getShapeId())));
}
