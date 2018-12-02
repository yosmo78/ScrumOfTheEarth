#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "vector.h"
#include "shape.h"
#include "square.h"
#include "rectangle.h"
#include "circle.h"
#include "ellipse.h"
#include "polygon.h"
#include "polyline.h"
#include "line.h"
#include "text.h"

#include <QColor>
#include <QString>

using namespace std;

enum GC
{
    color0,
    color1,
    black,
    white,
    darkGray,
    gray,
    lightGray,
    red,
    green,
    blue,
    cyan,
    magenta,
    yellow,
    darkRed,
    darkGreen,
    darkBlue,
    darkCyan,
    darkMagenta,
    darkYellow,
    transparent
};

enum PS
{
    NoPen,
    SolidLine,
    DashLine,
    DotLine,
    DashDotLine,
    DashDotDotLine,
    CustomDashLine
};

enum PCS
{
    FlatCap,
    SquareCap,
    RoundCap
};

enum PJS
{
    MiterJoin,
    BevelJoin,
    RoundJoin,
    SvgMiterJoin
};

enum BS
{
    NoBrush,
    SolidPattern,
    Dense1Pattern,
    Dense2Pattern,
    Dense3Pattern,
    Dense4Pattern,
    Dense5Pattern,
    Dense6Pattern,
    Dense7Pattern,
    HorPattern,
    VerPattern,
    CrossPattern,
    BDiagPattern,
    FDiagPattern,
    DiagCrossPattern,
    LinearGradientPattern,
    ConicalGradientPattern,
    RadicalGradientPattern,
    TexturePattern
};

enum TA
{
    AlignLeft = 1,
    AlignRight = 2,
    AlignHCenter = 4,
    AlignHustify = 8,
    AlignAbsolute = 10,

    AlignTop = 20,
    AlignBotom = 40,
    AlignVCenter = 80,
    AlignBaseline = 100
};

enum FS
{
    StyleNormal,
    StyleItalic,
    StyleOblique
};

enum FW
{
    Thin = 0,
    ExtraLight = 12,
    Light = 25,
    Normal = 50,
    Medium = 57,
    DemiBold = 63,
    Bold = 75,
    ExtraBold = 81,
    Black = 87
};



void shape_parser(myStd::vector<Shape*>& vec, const char* filename, bool &ok)//the paint device will be the renderarea
{

  Shape * shape = nullptr;



  GC pc = color0;
  GC bc = color0;
  PS ps = NoPen;
  PCS pcs = FlatCap;
  PJS pjs = MiterJoin;
  BS bs = NoBrush;
  TA ta = AlignLeft;
  FS fs = StyleNormal;
  FW fw = Normal;

  unsigned int shapeID = 99999;
  string shapeType = "nullptr";
  int shapeDemensions[10];
  string penColor = "nullptr";
  int penWidth = 0;
  string penStyle = "nullptr";
  string penCapStyle = "nullptr";
  string penJoinStyle = "nullptr";
  string brushColor = "nullptr";
  string brushStyle = "nullptr";
  QString textString = "nullptr";
  string textStdString;
  string textColor = "nullptr";
  string textAlignment = "nullptr";
  int textPointSize = 0;
  string textFontFamilyStr = "nullptr";
  QString textFontFamily;
  string textFontStyle = "nullptr";
  string textFontWeight = "nullptr";
  QPoint qPoint;
  myStd::vector<QPoint> dimensions;

  stringstream ss;
  int i = 0;

  string skip = "nullptr";

  ifstream fin;

  fin.open(filename);
  if(!fin.fail())
  {
    ok = true;
    vec.deleteList(); //clear out vector
  while(getline(fin, skip, ':') && fin >> shapeID)
  {

      getline(fin, skip, ' ');
      getline(fin, shapeType);

      if(shapeType == "Line")
      {
          getline(fin, skip, ' ');
          getline(fin, skip);
          ss.str(skip);

          while(getline(ss, skip, ','))
          {
              shapeDemensions[i] = stoi(skip);
              ++i;
          }

          getline(fin, skip, ' ');
          getline(fin, penColor);

          getline(fin, skip, ':');
          fin >> penWidth;
  //			fin.ignore(1000, '\n');

          getline(fin, skip, ' ');
          getline(fin, penStyle);

          getline(fin, skip, ' ');
          getline(fin, penCapStyle);

          getline(fin, skip, ' ');
          getline(fin, penJoinStyle);

          shape = new Line(shapeID, shapeDemensions[0], shapeDemensions[1], shapeDemensions[2], shapeDemensions[3], Qt::GlobalColor(pc), Qt::PenStyle(ps), Qt::PenCapStyle(pcs), Qt::PenJoinStyle(pjs), penWidth);

//          ui->widget->shapesList.push_back(shape);
          vec.push_back(shape);

          cout << "Line" << endl; // Init. Line OBJ
      }
      else if( shapeType == "Polyline")
      {
          getline(fin, skip, ' ');
          getline(fin, skip);
          ss.str(skip);

          while(getline(ss, skip, ','))
          {
              shapeDemensions[i] = stoi(skip);
              if(i % 2 == 0)
              {
                  qPoint.setX(shapeDemensions[i]);
              }
              else
              {
                  qPoint.setY(shapeDemensions[i]);
              }
              ++i;
              dimensions.push_back(qPoint);
          }



          getline(fin, skip, ' ');
          getline(fin, penColor);

          getline(fin, skip, ':');
          fin >> penWidth;
  //			fin.ignore(1000, '\n');

          getline(fin, skip, ' ');
          getline(fin, penStyle);

          getline(fin, skip, ' ');
          getline(fin, penCapStyle);

          getline(fin, skip, ' ');
          getline(fin, penJoinStyle);

          shape = new Polyline(shapeID, dimensions, Qt::GlobalColor(pc), Qt::PenStyle(ps), Qt::PenCapStyle(pcs), Qt::PenJoinStyle(pjs), penWidth);

//          ui->widget->shapesList.push_back(shape);
          vec.push_back(shape);

          cout << "Polyline" << endl; // Init. Polyine OBJ
      }
      else if(shapeType == "Polygon")
      {
          getline(fin, skip, ' ');
          getline(fin, skip);
          ss.str(skip);

          while(getline(ss, skip, ','))
          {
              shapeDemensions[i] = stoi(skip);
              if(i % 2 == 0)
              {
                  qPoint.setX(shapeDemensions[i]);
              }
              else
              {
                  qPoint.setY(shapeDemensions[i]);
              }
              ++i;
              dimensions.push_back(qPoint);
          }

          getline(fin, skip, ' ');
          getline(fin, penColor);

          getline(fin, skip, ':');
          fin >> penWidth;
  //			fin.ignore(1000, '\n');

          getline(fin, skip, ' ');
          getline(fin, penStyle);

          getline(fin, skip, ' ');
          getline(fin, penCapStyle);

          getline(fin, skip, ' ');
          getline(fin, penJoinStyle);

          getline(fin, skip, ' ');
          getline(fin, brushColor);

          getline(fin, skip, ' ');
          getline(fin, brushStyle);

          shape = new Polygon(shapeID, dimensions, Qt::GlobalColor(pc), Qt::GlobalColor(bc), Qt::PenStyle(ps), Qt::PenCapStyle(pcs), Qt::PenJoinStyle(pjs), Qt::BrushStyle(bs), penWidth);

//          ui->widget->shapesList.push_back(shape);
          vec.push_back(shape);

          cout << "Polygon" << endl; // Init. Polygon OBJ
      }
      else if(shapeType == "Rectangle")
      {
          getline(fin, skip, ' ');
          getline(fin, skip);
          ss.str(skip);

          while(getline(ss, skip, ','))
          {
              shapeDemensions[i] = stoi(skip);
              ++i;
          }

          getline(fin, skip, ' ');
          getline(fin, penColor);

          getline(fin, skip, ':');
          fin >> penWidth;
  //			fin.ignore(1000, '\n');

          getline(fin, skip, ' ');
          getline(fin, penStyle);

          getline(fin, skip, ' ');
          getline(fin, penCapStyle);

          getline(fin, skip, ' ');
          getline(fin, penJoinStyle);

          getline(fin, skip, ' ');
          getline(fin, brushColor);

          getline(fin, skip, ' ');
          getline(fin, brushStyle);

          shape = new Rectangle(shapeID, shapeDemensions[0], shapeDemensions[1], shapeDemensions[2], shapeDemensions[3] ,Qt::GlobalColor(pc), Qt::GlobalColor(bc), Qt::PenStyle(ps), Qt::PenCapStyle(pcs), Qt::PenJoinStyle(pjs), Qt::BrushStyle(bs), penWidth);

//          ui->widget->shapesList.push_back(shape);
          vec.push_back(shape);

          cout << "Rectangle" << endl; // Init. Rectangle OBJ
      }
      else if(shapeType == "Square")
      {
          getline(fin, skip, ' ');
          getline(fin, skip);
          ss.str(skip);

          while(getline(ss, skip, ','))
          {
              shapeDemensions[i] = stoi(skip);
              ++i;
          }

          getline(fin, skip, ' ');
          getline(fin, penColor);

          getline(fin, skip, ':');
          fin >> penWidth;
  //			fin.ignore(1000, '\n');

          getline(fin, skip, ' ');
          getline(fin, penStyle);

          getline(fin, skip, ' ');
          getline(fin, penCapStyle);

          getline(fin, skip, ' ');
          getline(fin, penJoinStyle);

          getline(fin, skip, ' ');
          getline(fin, brushColor);

          getline(fin, skip, ' ');
          getline(fin, brushStyle);

          shape = new Square(shapeID,shapeDemensions[0],shapeDemensions[1],shapeDemensions[2], Qt::GlobalColor(pc), Qt::GlobalColor(bc), Qt::PenStyle(ps), Qt::PenCapStyle(pcs), Qt::PenJoinStyle(pjs), Qt::BrushStyle(bs), penWidth);

//          ui->widget->shapesList.push_back(shape);
          vec.push_back(shape);

          cout << "Square" << endl; // Init. Square OBJ
      }
      else if(shapeType == "Ellipse")
      {
          getline(fin, skip, ' ');
          getline(fin, skip);
          ss.str(skip);

          while(getline(ss, skip, ','))
          {
              shapeDemensions[i] = stoi(skip);
              ++i;
          }

          getline(fin, skip, ' ');
          getline(fin, penColor);

          getline(fin, skip, ':');
          fin >> penWidth;
  //			fin.ignore(1000, '\n');

          getline(fin, skip, ' ');
          getline(fin, penStyle);

          getline(fin, skip, ' ');
          getline(fin, penCapStyle);

          getline(fin, skip, ' ');
          getline(fin, penJoinStyle);

          getline(fin, skip, ' ');
          getline(fin, brushColor);

          getline(fin, skip, ' ');
          getline(fin, brushStyle);

          shape = new Ellipse(shapeID,shapeDemensions[0],shapeDemensions[1],shapeDemensions[2], shapeDemensions[3], Qt::GlobalColor(pc), Qt::GlobalColor(bc), Qt::PenStyle(ps), Qt::PenCapStyle(pcs), Qt::PenJoinStyle(pjs), Qt::BrushStyle(bs), penWidth);

//          ui->widget->shapesList.push_back(shape);
          vec.push_back(shape);

          cout << "Ellipse" << endl; // Init. Ellipse OBJ
      }
      else if(shapeType == "Circle")
      {
          getline(fin, skip, ' ');
          getline(fin, skip);
          ss.str(skip);

          while(getline(ss, skip, ','))
          {
              shapeDemensions[i] = stoi(skip);
              ++i;
          }

          getline(fin, skip, ' ');
          getline(fin, penColor);

          getline(fin, skip, ':');
          fin >> penWidth;
  //			fin.ignore(1000, '\n');

          getline(fin, skip, ' ');
          getline(fin, penStyle);

          getline(fin, skip, ' ');
          getline(fin, penCapStyle);

          getline(fin, skip, ' ');
          getline(fin, penJoinStyle);

          getline(fin, skip, ' ');
          getline(fin, brushColor);

          getline(fin, skip, ' ');
          getline(fin, brushStyle);

          shape = new Circle(shapeID,shapeDemensions[0],shapeDemensions[1],shapeDemensions[2], Qt::GlobalColor(pc), Qt::GlobalColor(bc), Qt::PenStyle(ps), Qt::PenCapStyle(pcs), Qt::PenJoinStyle(pjs), Qt::BrushStyle(bs), penWidth);

//          ui->widget->shapesList.push_back(shape);
          vec.push_back(shape);

          cout << "Circle" << endl; // Init. Circle OBJ
      }
      else if(shapeType == "Text")
      {

          getline(fin, skip, ' ');
          getline(fin, skip);
          ss.str(skip);

          while(getline(ss, skip, ','))
          {
              shapeDemensions[i] = stoi(skip);
              ++i;
          }

          getline(fin, skip, ' ');
          getline(fin, textStdString);
          textString = QString::fromStdString(textStdString);

          getline(fin, skip, ' ');
          getline(fin, textColor);

          getline(fin, skip, ' ');
          getline(fin, textAlignment);

          getline(fin, skip, ' ');
  //			getline(fin, textPointSize);
          fin >> textPointSize;

          getline(fin, skip, ' ');
          getline(fin, textFontFamilyStr);
          textFontFamily = QString::fromStdString(textFontFamilyStr);

          getline(fin, skip, ' ');
          getline(fin, textFontStyle);

          getline(fin, skip, ' ');
          getline(fin, textFontWeight);

          shape = new Text(shapeID, shapeDemensions[0], shapeDemensions[1], shapeDemensions[2], shapeDemensions[3], textString, Qt::GlobalColor(pc), Qt::AlignmentFlag(ta), textPointSize, textFontFamily, QFont::Style(fs), QFont::Weight(fw));

//          ui->widget->shapesList.push_back(shape);
          vec.push_back(shape);

          cout << "Text" << endl; // Init. Text OBJ
      }


      cout << "ShapeID: " << shapeID << endl;
      cout << "ShapeType: " << shapeType << endl;
      cout << "ShapeDimensions: ";
      for(int a = 0; a < i; a++)
      {
          if(a < i)
          {
              cout << shapeDemensions[a] << ", ";
          }
          else
          {
              cout << shapeDemensions[a];
          }

      }
      cout << endl;
      cout << "PenColor: " << penColor << endl;
      cout << "PenWidth: " << penWidth << endl;
      cout << "PenStyle: " << penStyle << endl;
      cout << "PenCapStyle: " << penCapStyle << endl;
      cout << "penJoinStyle: " << penJoinStyle << endl;
      cout << "BrushColor: " << brushColor << endl;
      cout << "BrushStyle: " << brushStyle << endl;
      cout << endl << endl;


      ss.str();
      ss.clear();

      i = 0;
    }
  }
  else
  {
      ok = false;//file did not open
  }
  fin.close();

}
