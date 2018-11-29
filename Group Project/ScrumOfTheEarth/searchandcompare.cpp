#include "searchandcompare.h"

int findId(myStd::vector<Shape*> vec, unsigned int id)//sequential search looking for shape id
{
  int size = vec.size();
  bool notfound = true;
  int index = 0;
  while(index < size && notfound)
  {
      if(vec[index]->getShapeId() == id)
      {
          notfound = false;
      }
      else
      {
          ++index;
      }
  }
  return index;
}

