/*! \file */
#ifndef SEARCHANDCOMPARE_H
#define SEARCHANDCOMPARE_H

#include "vector.h"
#include "shape.h"

/*!
 * \brief cmpId compares the id of two shapes and returns true if the id of the first shape is greater. Otherwise, false
 * \param s1 Shape 1
 * \param s2 Shape 2
 * \return bool Shape 1's id is greater or not
 */
bool cmpId(Shape* s1, Shape* s2); //checks to see if first shape is greater than second shape
/*!
 * \brief cmpArea compares the area of two shapes and returns true if the area of the first shape is greater. Otherwise, false
 * \param s1 Shape 1
 * \param s2 Shape 2
 * \return bool Shape 1's perimeter is greater or not
 */
bool cmpArea(Shape* s1, Shape* s2);

/*!
 * \brief cmpPeri compares the perimeter of two shapes and returns true if the perimeter of the first shape is greater. Otherwise, false
 * \param s1 Shape 1
 * \param s2 Shape 2
 * \return bool Shape 1's perimeter is greater or not
 */
bool cmpPeri(Shape* s1, Shape* s2);

/*!
 * \brief findShape finds a shape with the given id in the given vector of shape pointers
 * \return
 */
int findShape(myStd::vector<Shape*>, unsigned int);

/*!
 * \brief sorts a given vector of type T with any comparison function
 */
template <typename T> void selection_sort(myStd::vector<T> &vec, bool(*cmp)(T, T))//cmp returns true if object one is greater/smaller than object 2. Pass in vector and cmp function name to use
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

template <typename BidirectionalIterator, typename StrictWeakOrdering> void selection_sort(BidirectionalIterator begin, BidirectionalIterator end, StrictWeakOrdering cmp)
{
    BidirectionalIterator swap;
    BidirectionalIterator small;
    for(BidirectionalIterator i = begin; i != end; ++i)
    {
        small = i;
        for(BidirectionalIterator j = ++i; j != end; ++j)
        {
            if(cmp(*small, *j))
            {
                small = j;
            }
        }
        *swap = *i;
        *i = *small;
        *small = *swap;
    }
};

#endif // SEARCHANDCOMPARE_H
