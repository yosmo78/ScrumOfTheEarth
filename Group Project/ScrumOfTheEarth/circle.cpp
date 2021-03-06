#include "circle.h"
#include <string>
Circle::Circle(unsigned int i, int x, int y, int r, Qt::GlobalColor pc, Qt::GlobalColor bc, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs, Qt::BrushStyle bs, int pw):
    Shape(i), point(x,y), radius(r),penColor(pc), brushColor(bc),penStyle(ps),penCapStyle(pcs),penJoinStyle(pjs),brushStyle(bs),penWidth(pw){}

void Circle::draw(QPainter & paint, bool Id)
{
    QBrush b(brushColor,brushStyle);
    QBrush p(penColor);
    QPen pen(p,qreal(penWidth),penStyle,penCapStyle,penJoinStyle);
    paint.setPen(pen);
    paint.setBrush(b);
    paint.drawEllipse(point,radius,radius);
    if(Id)
    {
    paint.drawText(point.x() + (radius/4 - 3 * (std::to_string(getShapeId()).size())), point.y()-(radius)-penWidth,QString::fromStdString(std::to_string(getShapeId())));
    }
}
