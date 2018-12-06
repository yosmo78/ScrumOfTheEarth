/*! \file */
#ifndef SEARCHANDCOMPARE_H
#define SEARCHANDCOMPARE_H

#include "vector.h"
#include "shape.h"
bool cmpId(Shape* s1, Shape* s2); //checks to see if first shape is greater than second shape
bool cmpArea(Shape* s1, Shape* s2);
bool cmpPeri(Shape* s1, Shape* s2);

int findShape(myStd::vector<Shape*>, unsigned int);

template <typename T>
void selection_sort(myStd::vector<T> &vec, bool(*cmp)(T, T))//cmp returns true if object one is greater/smaller than object 2. Pass in vector and cmp function name to use
{
  myStd::vector<T> temp;
  int size = vec.size();
  T smallest;
  int smallIndex;
  T swap;
  for(int i = 0; i < size; ++i)
  {
      smallest = vec[i];
      smallIndex = i;
      for(int j = i+1;j < size; ++j)
      {
          if(cmp(smallest, vec[j]))//search for smallest value
          {
            smallest = vec[j];
            smallIndex = j;
          }
      }
      swap = vec[i];//swaps contents of two values
      vec[i] = vec[smallIndex];
      vec[smallIndex] = swap;
  }

};

#endif // SEARCHANDCOMPARE_H
