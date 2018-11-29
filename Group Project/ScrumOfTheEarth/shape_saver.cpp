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
#include <iostream>

std::string qtColors[9]         = {"white","black","red","green","blue","cyan","magenta","yellow","gray"};
std::string penStyles[6]        = {"NoPen","SolidLine","DashLine","DotLine","DashDotLine","DashDotDotLine"};
std::string penCapStyles[3]     = {"FlatCap","SquareCap","RoundCap"};
std::string penJoinStyles[3]    = {"MiterJoin","BevelJoin","RoundJoin"};
std::string brushStyles[4]      = {"SolidPattern","HorPattern","VerPattern","NoBrush"};
std::string textAlignments[5]   = {"AlignLeft","AlignRight","AlignTop","AlignBottom","AlignCenter"};
std::string textFontFamilies[4] = {"Comic Sans MS","Courier","Helvetica","Times"};
std::string textFontStyles[3]   = {"StyleNormal","StyleItalic","StyleOblique"};
std::string textFontWeights[4]  = {"Thin","Light","Normal","Bold"};

void shape_saver(myStd::vector<Shape*>& vec, const char* filename)
{
    std::map<const std::string, std::string> typeMap;
    typeMap[typeid(const Square).name()]    = "Square";
    typeMap[typeid(const Rectangle).name()] = "Rectangle";
    typeMap[typeid(const Line).name()]      = "Line";
    typeMap[typeid(const Circle).name()]    = "Circle";
    typeMap[typeid(const Ellipse).name()]   = "Ellipse";
    typeMap[typeid(const Polygon).name()]   = "Polygon";
    typeMap[typeid(const Polyline).name()]  = "Polyline";
    typeMap[typeid(const Text).name()]      = "Text";


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
            fout << "ShapeType: " << typeMap[typeid(**tmp).name()]<< '\n';
            std::cerr << typeid(**tmp).name() << std::endl;
            std::cerr << typeid(Rectangle).name() << std::endl;
            std::cerr << typeid(Square).name() << std::endl;
            fout << "ShapeDimensions: ";
            if(typeid(**tmp).name() == typeid(const Square).name())
            {
              Square * sptr = dynamic_cast<Square *>(*tmp);
              fout << sptr->getCornerPoint().x() << ", " << sptr->getCornerPoint().y()
                   << ", "<< sptr->getLength() << '\n';

              fout << "PenColor: " << qtColors[sptr->getPenColor()] << '\n';
              fout << "PenWidth: " << sptr->getPenWidth() <<'\n';
              fout << "PenStyle: " << penStyles[sptr->getPenStyle()] << '\n';
              fout << "PenCapStyle: " << penCapStyles[sptr->getPenCapStyle()] << '\n';
              fout << "PenJoinStyle: " << penJoinStyles[sptr->getPenJoinStyle()] << '\n';
              fout << "BrushColor: " << qtColors[sptr->getBrushColor()] << '\n';
              fout << "BrushStyle: " << brushStyles[sptr->getBrushStyle()] << '\n';
            }
            else if(typeid(**tmp).name() == typeid(const Rectangle).name())
            {
              Rectangle * rptr = dynamic_cast<Rectangle *> (*tmp);
              fout << rptr->getCornerPoint().x() << ", " << rptr->getCornerPoint().y()
                   << ", "<<rptr->getLength() << ", " << rptr->getWidth() << '\n';
              fout << "PenColor: " << qtColors[rptr->getPenColor()] << '\n';
              fout << "PenWidth: " << rptr->getPenWidth() <<'\n';
              fout << "PenStyle: " << penStyles[rptr->getPenStyle()] << '\n';
              fout << "PenCapStyle: " << penCapStyles[rptr->getPenCapStyle()] << '\n';
              fout << "PenJoinStyle: " << penJoinStyles[rptr->getPenJoinStyle()] << '\n';
              fout << "BrushColor: " << qtColors[rptr->getBrushColor()] << '\n';
              fout << "BrushStyle: " << brushStyles[rptr->getBrushStyle()] << '\n';
            }
            else if(typeid(**tmp).name() == typeid(const Line).name())
            {
              Line * lptr = dynamic_cast<Line *> (*tmp);
              fout << lptr->getPoint1().x() << ", " << lptr->getPoint1().y()
                   << ", "<<lptr->getPoint2().x() << ", " << lptr->getPoint2().y() << '\n';
              fout << "PenColor: " << qtColors[lptr->getPenColor()] << '\n';
              fout << "PenWidth: " << lptr->getPenWidth() <<'\n';
              fout << "PenStyle: " << penStyles[lptr->getPenStyle()] << '\n';
              fout << "PenCapStyle: " << penCapStyles[lptr->getPenCapStyle()] << '\n';
              fout << "PenJoinStyle: " << penJoinStyles[lptr->getPenJoinStyle()] << '\n';
            }
            else if(typeid(**tmp).name() == typeid(const Circle).name())
            {
              Circle * cptr = dynamic_cast<Circle *> (*tmp);
              fout << cptr->getPoint1().x() << ", " << cptr->getPoint1().y()
                   << ", "<< cptr->getRadius() << '\n';

              fout << "PenColor: " << qtColors[cptr->getPenColor()] << '\n';
              fout << "PenWidth: " << cptr->getPenWidth() <<'\n';
              fout << "PenStyle: " << penStyles[cptr->getPenStyle()] << '\n';
              fout << "PenCapStyle: " << penCapStyles[cptr->getPenCapStyle()] << '\n';
              fout << "PenJoinStyle: " << penJoinStyles[cptr->getPenJoinStyle()] << '\n';
              fout << "BrushColor: " << qtColors[cptr->getBrushColor()] << '\n';
              fout << "BrushStyle: " << brushStyles[cptr->getBrushStyle()] << '\n';
            }
            else if(typeid(**tmp).name() == typeid(const Ellipse).name())
            {
              Ellipse * eptr = dynamic_cast<Ellipse *> (*tmp);
              fout << eptr->getTopLeft().x() << ", " << eptr->getTopLeft().y()
                   << ", "<<eptr->getMajorAxis() << ", " << eptr->getMinorAxis() << '\n';
              fout << "PenColor: " << qtColors[eptr->getPenColor()] << '\n';
              fout << "PenWidth: " << eptr->getPenWidth() <<'\n';
              fout << "PenStyle: " << penStyles[eptr->getPenStyle()] << '\n';
              fout << "PenCapStyle: " << penCapStyles[eptr->getPenCapStyle()] << '\n';
              fout << "PenJoinStyle: " << penJoinStyles[eptr->getPenJoinStyle()] << '\n';
              fout << "BrushColor: " << qtColors[eptr->getBrushColor()] << '\n';
              fout << "BrushStyle: " << brushStyles[eptr->getBrushStyle()] << '\n';
            }
            else if(typeid(**tmp).name() == typeid(const Polygon).name())
            {
              Polygon * pptr = dynamic_cast<Polygon *> (*tmp);
              for(int i = 0; i < pptr->getNumOfPoints();++i)
              {
                  fout << ((pptr->getPolyPoints())+i)->x() << ", " <<((pptr->getPolyPoints())+i)->y();
                  fout << (i == (pptr->getNumOfPoints()-1)?"\n": ", ");
              }
              fout << "PenColor: " << qtColors[pptr->getPenColor()] << '\n';
              fout << "PenWidth: " << pptr->getPenWidth() <<'\n';
              fout << "PenStyle: " << penStyles[pptr->getPenStyle()] << '\n';
              fout << "PenCapStyle: " << penCapStyles[pptr->getPenCapStyle()] << '\n';
              fout << "PenJoinStyle: " << penJoinStyles[pptr->getPenJoinStyle()] << '\n';
              fout << "BrushColor: " << qtColors[pptr->getBrushColor()] << '\n';
              fout << "BrushStyle: " << brushStyles[pptr->getBrushStyle()] << '\n';
            }
            else if(typeid(**tmp).name() == typeid(const Polyline).name())
            {
              Polyline * pptr = dynamic_cast<Polyline *> (*tmp);
              for(int i = 0; i < pptr->getNumOfPoints();++i)
              {
                  fout << ((pptr->getPoints().begin())+i)->x() << ", " <<((pptr->getPoints().begin())+i)->y();
                  fout << (i == (pptr->getPoints().size()-1)?"\n": ", ");
              }
              fout << "PenColor: " << qtColors[pptr->getPenColor()] << '\n';
              fout << "PenWidth: " << pptr->getPenWidth() <<'\n';
              fout << "PenStyle: " << penStyles[pptr->getPenStyle()] << '\n';
              fout << "PenCapStyle: " << penCapStyles[pptr->getPenCapStyle()] << '\n';
              fout << "PenJoinStyle: " << penJoinStyles[pptr->getPenJoinStyle()] << '\n';
            }
            else if(typeid(**tmp).name() == typeid(const Text).name())
            {
              Text * tptr = dynamic_cast<Text *> (*tmp);
              fout << tptr->getCornerPoint().x() << ", "<< tptr->getCornerPoint().y()
                   << ", " << tptr->getLength() << ", " << tptr->getWidth() << '\n';
              fout << "TextString: " << tptr->getTextString().toStdString() << '\n';
              fout << "TextColor: " << qtColors[tptr->getGlobalColor()] << '\n';
              fout << "TextAlignment: " << textAlignments[tptr->getAlignmentFlag()] << '\n';
              fout << "TextPointSize: " << tptr->getTextPointSize() << '\n';
              fout << "TextFontFamily: " << tptr->getTextFontFamily().toStdString() << '\n';
              fout << "TextFontStyle: " << textFontStyles[tptr->getTextFontStyle()] << '\n';
              fout << "TextFontWeight: " << textFontWeights[tptr->getTextFontWeight()] << '\n';
            }
            else
            {
                std::ofstream fout2;
                fout2.open("Error.txt",std::ios_base::out|std::ios_base::app);
                fout2 << "Invalid Shape trying to write to file\n";
                fout2.close();
            }
        }
    }
    fout.close();
}
