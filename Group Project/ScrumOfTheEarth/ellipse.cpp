#include "ellipse.h"
Ellipse::Ellipse(unsigned int i, int x, int y, int a, int b, Qt::GlobalColor pc, Qt::GlobalColor bc, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs, Qt::BrushStyle bs, int pw):
    Shape(i), point(x,y), penColor(pc), brushColor(bc),penStyle(ps),penCapStyle(pcs),penJoinStyle(pjs),brushStyle(bs),penWidth(pw){semimajor = a; semiminor = b;}

void Ellipse::draw(QPainter & paint)
{
    QBrush b(brushColor,brushStyle);
    QBrush p(penColor);
    QPen pen(p,qreal(penWidth),penStyle,penCapStyle,penJoinStyle);
    paint.setPen(pen);
    paint.setBrush(b);
    paint.drawEllipse(QRect(point, QSize(semimajor*2, semiminor*2) ));
    paint.drawText(point.x() + (semimajor - 3 * std::to_string(getShapeId()).length()), point.y()-penWidth ,QString::fromStdString(std::to_string(getShapeId())));
}
