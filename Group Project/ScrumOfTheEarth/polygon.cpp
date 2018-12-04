#include "polygon.h"
#include <iostream>
Polygon::Polygon(unsigned int i, myStd::vector<QPoint> vec, Qt::GlobalColor pc, Qt::GlobalColor bc, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs, Qt::BrushStyle bs, int pw):
    Shape(i), polyPoint(vec),penColor(pc), brushColor(bc),penStyle(ps),penCapStyle(pcs),penJoinStyle(pjs),brushStyle(bs),penWidth(pw){}
void Polygon::draw(QPainter& paint)
{
 QBrush b(brushColor,brushStyle);
 QBrush p(penColor);
 QPen pen(p,qreal(penWidth),penStyle,penCapStyle,penJoinStyle);
 paint.setPen(pen);
 paint.setBrush(b);
 paint.drawPolygon(polyPoint.begin(),polyPoint.size());

 int minX = 1000000,maxX = 0,minY = 100000,maxY = 0;
 myStd::vector<QPoint>::const_iterator tmp = polyPoint.begin();
 for(int index = 0;index < polyPoint.size() ;++index)
 {
     if(tmp[index].x() < minX) minX = tmp[index].x();
     if(tmp[index].x() > maxX) maxX = tmp[index].x();
     if(tmp[index].y() > maxY) maxY = tmp[index].y();
     if(tmp[index].y() < minY) minY = tmp[index].y();
 }
 //std::cerr << minY << maxY;
 //paint.drawText((((minX+ maxX)/2) - 3 * std::to_string(getShapeId()).length()), minY - penWidth,QString::fromStdString(std::to_string(getShapeId())));
 paint.drawText(((minX+maxX)/2)-(3*std::to_string(getShapeId()).length()), maxY -(maxY-minY) ,QString::fromStdString(std::to_string(getShapeId())));
}
