#include "polyline.h"
#include <iostream>
Polyline::Polyline(unsigned int i,myStd::vector<QPoint>& vec , Qt::GlobalColor pc, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs,  int pw):
    Shape(i),points(vec), penColor(pc),penStyle(ps),penCapStyle(pcs),penJoinStyle(pjs),penWidth(pw){}
void Polyline::draw(QPainter & paint, bool Id)
{
  QBrush b(penColor);
  QPen pen(b,qreal(penWidth),penStyle,penCapStyle,penJoinStyle);
  pen.setColor(penColor);
  int minX = 1000000,maxX = 0,minY = 100000,maxY = 0;
  myStd::vector<QPoint>::const_iterator tmp = points.begin();
  for(int index = 0;index < points.size() ;++index)
  {
      if(tmp[index].x() < minX) minX = tmp[index].x();
      if(tmp[index].x() > maxX) maxX = tmp[index].x();
      if(tmp[index].y() > maxY) maxY = tmp[index].y();
      if(tmp[index].y() < minY) minY = tmp[index].y();
      if(index != (points.size()-1))
      {
          paint.drawLine(tmp[index], tmp[index+1]);
      }
  }
  if(Id)
  {
    paint.drawText((((minX+ maxX)/2) - 3 * std::to_string(getShapeId()).length()), minY - penWidth,QString::fromStdString(std::to_string(getShapeId())));
  }
}
