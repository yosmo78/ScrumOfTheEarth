#include "shape.h"
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



void shape_saver(myStd::vector<Shape*>& vec, const char* filename)
{
    std::string qtColors[]         = {"color0","color1","black","white","darkGray","gray","lightGray","red","green","blue","cyan","magenta","yellow","darkRed","darkGreen","darkBlue","darkCyan","darkMagenta","darkYellow","transparent"};
    std::string penStyles[]        = {"NoPen","SolidLine","DashLine","DotLine","DashDotLine","DashDotDotLine","CustomDashLine"};
    std::string penCapStyles[0x21] = {"FlatCap"};
    penCapStyles[0x10] = "SqaureCap";
    penCapStyles[0x20] = "RoundCap";
    std::string penJoinStyles[0x81]= {"MiterJoin"};
    penJoinStyles[0x40] = "BevelJoin";
    penJoinStyles[0x80] = "RoundJoin";
    std::string brushStyles[]      = {"NoBrush","SolidPattern","Dense1Pattern","Dense2Pattern","Dense3Pattern","Dense4Pattern","Dense5Pattern","Dense6Pattern","Dense7Pattern","HorPattern","VerPattern","CrossPattern","BDiagPattern","FDiagPattern","DiagCrossPattern","LinearGradientPattern","RadialGradientPattern","ConicalGradientPattern","","","","","","","TexturePattern"};
    std::string textAlignments[0x0085]; //check these later,
    textAlignments[0x0001] = "AlignLeft";
    textAlignments[0x0002] = "AlignRight";
    textAlignments[0x0004] = "AlignHCenter";
    textAlignments[0x0008] = "AlignJustify";
    textAlignments[0x0020] = "AlignTop";
    textAlignments[0x0040] = "AlignBottom";
    textAlignments[0x0080] = "AlignVCenter";
    textAlignments[0x0004|0x0080] = "AlignCenter";
    std::string textFontStyles[]   = {"StyleNormal","StyleItalic","StyleOblique"};
    std::string textFontWeights[99];
    textFontWeights[25] = "Light";
    textFontWeights[50] = "Normal";
    textFontWeights[63] = "DemiBold";
    textFontWeights[75] = "Bold";
    textFontWeights[87] = "Black";



    std::map<int, std::string> typeMap;
    typeMap[Square::getStaticType()]    = "Square";
    typeMap[Rectangle::getStaticType()] = "Rectangle";
    typeMap[Line::getStaticType()]      = "Line";
    typeMap[Circle::getStaticType()]    = "Circle";
    typeMap[Ellipse::getStaticType()]   = "Ellipse";
    typeMap[Polygon::getStaticType()]   = "Polygon";
    typeMap[Polyline::getStaticType()]  = "Polyline";
    typeMap[Text::getStaticType()]      = "Text";


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
            fout << "ShapeId: "<<(*tmp)->getShapeId() << '\n';
            fout << "ShapeType: " << typeMap[(**tmp).getType()]<< '\n';
            fout << "ShapeDimensions: ";
            if((**tmp).getType() == Square::getStaticType())
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
            else if((**tmp).getType() == Rectangle::getStaticType())
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
            else if((**tmp).getType() == Line::getStaticType())
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
            else if((**tmp).getType() == Circle::getStaticType())
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
            else if((**tmp).getType() == Ellipse::getStaticType())
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
            else if((**tmp).getType() == Polygon::getStaticType())
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
            else if((**tmp).getType() == Polyline::getStaticType())
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
            else if((**tmp).getType() == Text::getStaticType())
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
            ++tmp;
        }
    }
    fout.close();
}
