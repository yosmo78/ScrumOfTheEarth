#ifndef SEARCHANDCOMPARE_H
#define SEARCHANDCOMPARE_H

#include "vector.h"
#include "shape.h"
bool cmpId(Shape* s1, Shape* s2){return s1->getShapeId()>s2->getShapeId();}//checks to see if first shape is greater than second shape

int findShape(myStd::vector<Shape*> vec, int);
void selection_sort(myStd::vector<Shape*> vec, bool(*cmp)(Shape*, Shape*));

#endif // SEARCHANDCOMPARE_H
