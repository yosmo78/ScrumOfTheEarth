#include "square.h"
#include "rectangle.h"
#include "line.h"
#include "circle.h"
#include "ellipse.h"
#include "polygon.h"
#include "polyline.h"
#include "text.h"
#include <fstream>


void shape_saver(myStd::vector<Shape*>& vec, const char* filename)
{
    std::ofstream fin;
    if(vec.size() == 0)
    {
        fin.open("Error.txt",std::ios_base::out|std::ios_base::app);
        fin << "Tried to save an empty vector\n";
        fin.close();
        return;
    }
    fin.open(filename);
    if(!fin.fail())
    {

    }
    fin.close();
}
