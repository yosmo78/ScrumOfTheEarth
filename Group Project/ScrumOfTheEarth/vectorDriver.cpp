#include "vector.h"
#include <iostream>

using namespace std;

int main()
{
  myStd::vector<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  for(int i = 0; i < list.size(); ++i)
  {
    cout << list[i];
  }

  list.erase(list.end()-1);

  myStd::vector<int> list2(list);

  for(int i = 0; i < list2.size(); ++i)
  {
    cout << list2[i];
  }
  return 0;
}
