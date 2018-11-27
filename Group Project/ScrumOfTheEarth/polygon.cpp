#include "polygon.h"

Polygon::Polygon(QPaintDevice* pptr, unsigned int i, myStd::vector<QPoint> vec, Qt::GlobalColor pc, Qt::GlobalColor bc, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs, Qt::BrushStyle bs, int pw):
    Shape(pptr,i), polyPoint(vec),penColor(pc), brushColor(bc),penStyle(ps),penCapStyle(pcs),penJoinStyle(pjs),brushStyle(bs),penWidth(pw){}
