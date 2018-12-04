#include "delete_zeros.h"

void delete_Azeros(myStd::vector<Shape*>& vec)
{
    for(int i = 0; i < vec.size(); ++i)
    {
        if(vec[i]->getArea() == 0.0)
        {
            vec.erase(vec.begin() + i);
            --i;
        }
    }
}
void delete_Pzeros(myStd::vector<Shape*>& vec)
{
    for(int i = 0; i < vec.size(); ++i)
    {
        if(vec[i]->getPerimeter() == 0.0)
        {
            vec.erase(vec.begin() + i);
            --i;
        }
    }
}
