#include "square.h"
#include "rectangle.h"
#include "line.h"
#include "circle.h"
#include "ellipse.h"
#include "polygon.h"
#include "polyline.h"
#include "text.h"
#include <string>
#include <fstream>
#include <typeinfo>
#include <map>

void shape_saver(myStd::vector<Shape*>& vec, const char* filename)
{
    std::map<const std::type_info*, std::string> typeMap;
    typeMap[&typeid(Square)] = "Square";
    typeMap[&typeid(Rectangle)] = "Rectangle";
    typeMap[&typeid(Line)] = "Line";
    typeMap[&typeid(Circle)] = "Circle";
    typeMap[&typeid(Ellipse)] = "Ellipse";
    typeMap[&typeid(Polygon)] = "Polygon";
    typeMap[&typeid(Polyline)] = "Polyline";
    typeMap[&typeid(Text)] = "Text";


    std::ofstream fout;
    if(vec.size() == 0)
    {
        fout.open("Error.txt",std::ios_base::out|std::ios_base::app);
        fout << "Tried to save an empty vector\n";
        fout.close();
        return;
    }
    fout.open(filename);
    if(!fout.fail())
    {
        myStd::vector<Shape*>::const_iterator tmp = vec.begin();
        for(int i = 0;i < vec.size() ;++i)
        {
            fout << '\n';
            fout << "ShapeId: "<<tmp[i]->getShapeId() << '\n';
            fout << "ShapeType: " << typeMap[&typeid(**tmp)]<< '\n';
            fout << "ShapeDimensions: ";
            if(&typeid(**tmp) == &typeid(Square))
            {
              Square * sptr = dynamic_cast<Square *>(*tmp);
              fout << sptr->getCornerPoint().x() << ", " << sptr->getCornerPoint().y()
                   << ", "<< sptr->getLength() << '\n';
            }
            else if(&typeid(**tmp) == &typeid(Rectangle))
            {
              Rectangle * rptr = dynamic_cast<Rectangle *> (*tmp);
            }
            else if(&typeid(**tmp) == &typeid(Line))
            {
              Line * lptr = dynamic_cast<Line *> (*tmp);
            }
            else if(&typeid(**tmp) == &typeid(Circle))
            {
              Circle * cptr = dynamic_cast<Circle *> (*tmp);
            }
            else if(&typeid(**tmp) == &typeid(Ellipse))
            {
              Ellipse * eptr = dynamic_cast<Ellipse *> (*tmp);
            }
            else if(&typeid(**tmp) == &typeid(Polygon))
            {
              Polygon * pptr = dynamic_cast<Polygon *> (*tmp);
            }
            else if(&typeid(**tmp) == &typeid(Polyline))
            {
              Polyline * pptr = dynamic_cast<Polyline *> (*tmp);
            }
            else if(&typeid(**tmp) == &typeid(Text))
            {
              Text * tptr = dynamic_cast<Text *> (*tmp);
            }
        }
    }
    fout.close();
}
