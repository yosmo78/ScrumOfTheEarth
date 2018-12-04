//#include <fstream>
//#include <sstream>
//#include <iostream>
//#include <string>
//#include "vector.h"
//#include "shape.h"
//#include "square.h"
//#include "rectangle.h"
//#include "circle.h"
//#include "ellipse.h"
//#include "polygon.h"
//#include "polyline.h"
//#include "line.h"
//#include "text.h"

//#include <QColor>
//#include <QString>

#include "shape_parser.h"

using namespace std;

//enum GC
//{
//    color0,
//    color1,
//    black,
//    white,
//    darkGray,
//    gray,
//    lightGray,
//    red,
//    green,
//    blue,
//    cyan,
//    magenta,
//    yellow,
//    darkRed,
//    darkGreen,
//    darkBlue,
//    darkCyan,
//    darkMagenta,
//    darkYellow,
//    transparent
//};

//enum PS
//{
//    NoPen,
//    SolidLine,
//    DashLine,
//    DotLine,
//    DashDotLine,
//    DashDotDotLine,
//    CustomDashLine
//};

//enum PCS
//{
//    FlatCap,
//    SquareCap,
//    RoundCap
//};

//enum PJS
//{
//    MiterJoin,
//    BevelJoin,
//    RoundJoin,
//    SvgMiterJoin
//};

//enum BS
//{
//    NoBrush,
//    SolidPattern,
//    Dense1Pattern,
//    Dense2Pattern,
//    Dense3Pattern,
//    Dense4Pattern,
//    Dense5Pattern,
//    Dense6Pattern,
//    Dense7Pattern,
//    HorPattern,
//    VerPattern,
//    CrossPattern,
//    BDiagPattern,
//    FDiagPattern,
//    DiagCrossPattern,
//    LinearGradientPattern,
//    ConicalGradientPattern,
//    RadicalGradientPattern,
//    TexturePattern
//};

//enum TA
//{
//    AlignLeft = 1,
//    AlignRight = 2,
//    AlignHCenter = 4,
//    AlignHustify = 8,
//    AlignAbsolute = 10,

//    AlignTop = 20,
//    AlignBotom = 40,
//    AlignVCenter = 80,
//    AlignBaseline = 100
//};

//enum FS
//{
//    StyleNormal,
//    StyleItalic,
//    StyleOblique
//};

//enum FW
//{
//    Thin = 0,
//    ExtraLight = 12,
//    Light = 25,
//    Normal = 50,
//    Medium = 57,
//    DemiBold = 63,
//    Bold = 75,
//    ExtraBold = 81,
//    Black = 87
//};



void shape_parser(myStd::vector<Shape*>& vec, const char* filename, bool &ok)//the paint device will be the renderarea
{

  Shape * shape = nullptr;

//  GC pc = color0;
//  GC bc = color0;
//  PS ps = NoPen;
//  PCS pcs = FlatCap;
//  PJS pjs = MiterJoin;
//  BS bs = NoBrush;
//  TA ta = AlignLeft;
//  FS fs = StyleNormal;
//  FW fw = Normal;

  unsigned int shapeID = 99999;
  string shapeType = "nullptr";
  int shapeDemensions[20];
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
//    ok = true;
    vec.deleteList(); //clear out vector
  while(getline(fin, skip, ':') && fin >> shapeID)
  {

      getline(fin, skip, ' ');
      getline(fin, shapeType);
      if(shapeType[shapeType.size()-1] == '\r') shapeType = shapeType.substr(0,shapeType.size()-1);

      if(shapeType == "Line")
      {
          getline(fin, skip, ' ');
          getline(fin, skip);
          if(skip[skip.size()-1] == '\r') skip = skip.substr(0,skip.size()-1);
          ss.str(skip);

          while(getline(ss, skip, ','))
          {
              shapeDemensions[i] = stoi(skip);
              ++i;
          }

          getline(fin, skip, ' ');
          getline(fin, penColor);
          if(penColor[penColor.size()-1] == '\r') penColor = penColor.substr(0,penColor.size()-1);

          getline(fin, skip, ':');
          fin >> penWidth;
            fin.ignore(1000, '\n');

          getline(fin, skip, ' ');
          getline(fin, penStyle);
          if(penStyle[penStyle.size()-1] == '\r') penStyle = penStyle.substr(0,penStyle.size()-1);

          getline(fin, skip, ' ');
          getline(fin, penCapStyle);
          if(penCapStyle[penCapStyle.size()-1] == '\r') penCapStyle = penCapStyle.substr(0,penCapStyle.size()-1);

          getline(fin, skip, ' ');
          getline(fin, penJoinStyle);
          if(penJoinStyle[penJoinStyle.size()-1] == '\r') penJoinStyle = penJoinStyle.substr(0,penJoinStyle.size()-1);

          shape = new Line(shapeID, shapeDemensions[0], shapeDemensions[1], shapeDemensions[2], shapeDemensions[3], convertColor(penColor), convertPenStyle(penStyle), convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), penWidth);

//          ShapesList.push_back(shape);
          vec.push_back(shape);

//          cout << "Line" << endl; // Init. Line OBJ
      }
      else if( shapeType == "Polyline")
      {
          getline(fin, skip, ' ');
          getline(fin, skip);
          if(skip[skip.size()-1] == '\r') skip = skip.substr(0,skip.size()-1);
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
                  dimensions.push_back(qPoint);
              }
              ++i;
          }
          i =0;

          getline(fin, skip, ' ');
          getline(fin, penColor);
          if(penColor[penColor.size()-1] == '\r') penColor = penColor.substr(0,penColor.size()-1);

          getline(fin, skip, ':');
          fin >> penWidth;
  //			fin.ignore(1000, '\n');

          getline(fin, skip, ' ');
          getline(fin, penStyle);
          if(penStyle[penStyle.size()-1] == '\r') penStyle = penStyle.substr(0,penStyle.size()-1);

          getline(fin, skip, ' ');
          getline(fin, penCapStyle);
          if(penCapStyle[penCapStyle.size()-1] == '\r') penCapStyle = penCapStyle.substr(0,penCapStyle.size()-1);

          getline(fin, skip, ' ');
          getline(fin, penJoinStyle);
          if(penJoinStyle[penJoinStyle.size()-1] == '\r') penJoinStyle = penJoinStyle.substr(0,penJoinStyle.size()-1);

          shape = new Polyline(shapeID, dimensions, convertColor(penColor), convertPenStyle(penStyle), convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), penWidth);
          while(dimensions.size() != 0)
          {
              dimensions.erase(dimensions.end()-1);
          }
          dimensions.erase(0);
//          ui->widget->shapesList.push_back(shape);
          vec.push_back(shape);

//          cout << "Polyline" << endl; // Init. Polyine OBJ
      }
      else if(shapeType == "Polygon")
      {
          getline(fin, skip, ' ');
          getline(fin, skip);
          if(skip[skip.size()-1] == '\r') skip = skip.substr(0,skip.size()-1);
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
                  dimensions.push_back(qPoint);
              }
              ++i;
          }
          i = 0;

          getline(fin, skip, ' ');
          getline(fin, penColor);
          if(penColor[penColor.size()-1] == '\r') penColor = penColor.substr(0,penColor.size()-1);

          getline(fin, skip, ':');
          fin >> penWidth;
  //			fin.ignore(1000, '\n');

          getline(fin, skip, ' ');
          getline(fin, penStyle);
          if(penStyle[penStyle.size()-1] == '\r') penStyle = penStyle.substr(0,penStyle.size()-1);

          getline(fin, skip, ' ');
          getline(fin, penCapStyle);
          if(penCapStyle[penCapStyle.size()-1] == '\r') penCapStyle = penCapStyle.substr(0,penCapStyle.size()-1);

          getline(fin, skip, ' ');
          getline(fin, penJoinStyle);
          if(penJoinStyle[penJoinStyle.size()-1] == '\r') penJoinStyle = penJoinStyle.substr(0,penJoinStyle.size()-1);

          getline(fin, skip, ' ');
          getline(fin, brushColor);
          if(brushColor[brushColor.size()-1] == '\r') brushColor = brushColor.substr(0,brushColor.size()-1);

          getline(fin, skip, ' ');
          getline(fin, brushStyle);
          if(brushStyle[brushStyle.size()-1] == '\r') brushStyle = brushStyle.substr(0,brushStyle.size()-1);

          shape = new Polygon(shapeID, dimensions, convertColor(penColor), convertColor(brushColor), convertPenStyle(penStyle),convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), convertBrushStyle(brushStyle), penWidth);
          while(dimensions.size() != 0)
          {
              dimensions.erase(dimensions.end()-1);
          }
           dimensions.erase(0);
//          ui->widget->shapesList.push_back(shape);
          vec.push_back(shape);

//          cout << "Polygon" << endl; // Init. Polygon OBJ
      }
      else if(shapeType == "Rectangle")
      {
          getline(fin, skip, ' ');
          getline(fin, skip);
          if(skip[skip.size()-1] == '\r') skip = skip.substr(0,skip.size()-1);
          ss.str(skip);

          while(getline(ss, skip, ','))
          {
              shapeDemensions[i] = stoi(skip);
              ++i;
          }

          getline(fin, skip, ' ');
          getline(fin, penColor);
          if(penColor[penColor.size()-1] == '\r') penColor = penColor.substr(0,penColor.size()-1);

          getline(fin, skip, ':');
          fin >> penWidth;
  //			fin.ignore(1000, '\n');

          getline(fin, skip, ' ');
          getline(fin, penStyle);
          if(penStyle[penStyle.size()-1] == '\r') penStyle = penStyle.substr(0,penStyle.size()-1);

          getline(fin, skip, ' ');
          getline(fin, penCapStyle);
          if(penCapStyle[penCapStyle.size()-1] == '\r') penCapStyle = penCapStyle.substr(0,penCapStyle.size()-1);

          getline(fin, skip, ' ');
          getline(fin, penJoinStyle);
          if(penJoinStyle[penJoinStyle.size()-1] == '\r') penJoinStyle = penJoinStyle.substr(0,penJoinStyle.size()-1);

          getline(fin, skip, ' ');
          getline(fin, brushColor);
          if(brushColor[brushColor.size()-1] == '\r') brushColor = brushColor.substr(0,brushColor.size()-1);

          getline(fin, skip, ' ');
          getline(fin, brushStyle);
          if(brushStyle[brushStyle.size()-1] == '\r') brushStyle = brushStyle.substr(0,brushStyle.size()-1);

          shape = new Rectangle(shapeID, shapeDemensions[0], shapeDemensions[1], shapeDemensions[2], shapeDemensions[3] ,convertColor(penColor), convertColor(brushColor), convertPenStyle(penStyle), convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), convertBrushStyle(brushStyle), penWidth);

//          ui->widget->shapesList.push_back(shape);
          vec.push_back(shape);

//          cout << "Rectangle" << endl; // Init. Rectangle OBJ
      }
      else if(shapeType == "Square")
      {
          getline(fin, skip, ' ');
          getline(fin, skip);
          if(skip[skip.size()-1] == '\r') skip = skip.substr(0,skip.size()-1);
          ss.str(skip);

          while(getline(ss, skip, ','))
          {
              shapeDemensions[i] = stoi(skip);
              ++i;
          }

          getline(fin, skip, ' ');
          getline(fin, penColor);
          if(penColor[penColor.size()-1] == '\r') penColor = penColor.substr(0,penColor.size()-1);

          getline(fin, skip, ':');
          fin >> penWidth;
  //			fin.ignore(1000, '\n');

          getline(fin, skip, ' ');
          getline(fin, penStyle);
          if(penStyle[penStyle.size()-1] == '\r') penStyle = penStyle.substr(0,penStyle.size()-1);

          getline(fin, skip, ' ');
          getline(fin, penCapStyle);
          if(penCapStyle[penCapStyle.size()-1] == '\r') penCapStyle = penCapStyle.substr(0,penCapStyle.size()-1);

          getline(fin, skip, ' ');
          getline(fin, penJoinStyle);
          if(penJoinStyle[penJoinStyle.size()-1] == '\r') penJoinStyle = penJoinStyle.substr(0,penJoinStyle.size()-1);

          getline(fin, skip, ' ');
          getline(fin, brushColor);
          if(brushColor[brushColor.size()-1] == '\r') brushColor = brushColor.substr(0,brushColor.size()-1);

          getline(fin, skip, ' ');
          getline(fin, brushStyle);
          if(brushStyle[brushStyle.size()-1] == '\r') brushStyle = brushStyle.substr(0,brushStyle.size()-1);

          shape = new Square(shapeID,shapeDemensions[0],shapeDemensions[1],shapeDemensions[2], convertColor(penColor), convertColor(brushColor), convertPenStyle(penStyle), convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), convertBrushStyle(brushStyle), penWidth);

//          ui->widget->shapesList.push_back(shape);
          vec.push_back(shape);

//          cout << "Square" << endl; // Init. Square OBJ
      }
      else if(shapeType == "Ellipse")
      {
          getline(fin, skip, ' ');
          getline(fin, skip);
          if(skip[skip.size()-1] == '\r') skip = skip.substr(0,skip.size()-1);
          ss.str(skip);

          while(getline(ss, skip, ','))
          {
              shapeDemensions[i] = stoi(skip);
              ++i;
          }

          getline(fin, skip, ' ');
          getline(fin, penColor);
          if(penColor[penColor.size()-1] == '\r') penColor = penColor.substr(0,penColor.size()-1);

          getline(fin, skip, ':');
          fin >> penWidth;
  //			fin.ignore(1000, '\n');

          getline(fin, skip, ' ');
          getline(fin, penStyle);
          if(penStyle[penStyle.size()-1] == '\r') penStyle = penStyle.substr(0,penStyle.size()-1);

          getline(fin, skip, ' ');
          getline(fin, penCapStyle);
          if(penCapStyle[penCapStyle.size()-1] == '\r') penCapStyle = penCapStyle.substr(0,penCapStyle.size()-1);

          getline(fin, skip, ' ');
          getline(fin, penJoinStyle);
          if(penJoinStyle[penJoinStyle.size()-1] == '\r') penJoinStyle = penJoinStyle.substr(0,penJoinStyle.size()-1);

          getline(fin, skip, ' ');
          getline(fin, brushColor);
          if(brushColor[brushColor.size()-1] == '\r') brushColor = brushColor.substr(0,brushColor.size()-1);

          getline(fin, skip, ' ');
          getline(fin, brushStyle);
          if(brushStyle[brushStyle.size()-1] == '\r') brushStyle = brushStyle.substr(0,brushStyle.size()-1);

          shape = new Ellipse(shapeID,shapeDemensions[0],shapeDemensions[1],shapeDemensions[2], shapeDemensions[3], convertColor(penColor), convertColor(brushColor), convertPenStyle(penStyle), convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), convertBrushStyle(brushStyle), penWidth);

//          ui->widget->shapesList.push_back(shape);
          vec.push_back(shape);

//          cout << "Ellipse" << endl; // Init. Ellipse OBJ
      }
      else if(shapeType == "Circle")
      {
          getline(fin, skip, ' ');
          getline(fin, skip);
          if(skip[skip.size()-1] == '\r') skip = skip.substr(0,skip.size()-1);
          ss.str(skip);

          while(getline(ss, skip, ','))
          {
              shapeDemensions[i] = stoi(skip);
              ++i;
          }

          getline(fin, skip, ' ');
          getline(fin, penColor);
          if(penColor[penColor.size()-1] == '\r') penColor = penColor.substr(0,penColor.size()-1);

          getline(fin, skip, ':');
          fin >> penWidth;
  //			fin.ignore(1000, '\n');

          getline(fin, skip, ' ');
          getline(fin, penStyle);
          if(penStyle[penStyle.size()-1] == '\r') penStyle = penStyle.substr(0,penStyle.size()-1);

          getline(fin, skip, ' ');
          getline(fin, penCapStyle);
          if(penCapStyle[penCapStyle.size()-1] == '\r') penCapStyle = penCapStyle.substr(0,penCapStyle.size()-1);

          getline(fin, skip, ' ');
          getline(fin, penJoinStyle);
          if(penJoinStyle[penJoinStyle.size()-1] == '\r') penJoinStyle = penJoinStyle.substr(0,penJoinStyle.size()-1);

          getline(fin, skip, ' ');
          getline(fin, brushColor);
          if(brushColor[brushColor.size()-1] == '\r') brushColor = brushColor.substr(0,brushColor.size()-1);

          getline(fin, skip, ' ');
          getline(fin, brushStyle);
          if(brushStyle[brushStyle.size()-1] == '\r') brushStyle = brushStyle.substr(0,brushStyle.size()-1);

          shape = new Circle(shapeID,shapeDemensions[0],shapeDemensions[1],shapeDemensions[2], convertColor(penColor), convertColor(brushColor), convertPenStyle(penStyle), convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), convertBrushStyle(brushStyle), penWidth);

//          ui->widget->shapesList.push_back(shape);
          vec.push_back(shape);

//          cout << "Circle" << endl; // Init. Circle OBJ
      }
      else if(shapeType == "Text")
      {

          getline(fin, skip, ' ');
          getline(fin, skip);
          if(skip[skip.size()-1] == '\r') skip = skip.substr(0,skip.size()-1);
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

          shape = new Text(shapeID, shapeDemensions[0], shapeDemensions[1], shapeDemensions[2], shapeDemensions[3], textString, convertColor(penColor), convertAlignment(textAlignment), textPointSize, textFontFamily, convertStyle(textFontStyle), convertWeight(textFontWeight));

//          ui->widget->shapesList.push_back(shape);
          vec.push_back(shape);

//          cout << "Text" << endl; // Init. Text OBJ
      }

//      cout << "ShapeID: " << shapeID << endl;
//      cout << "ShapeType: " << shapeType << endl;
//      cout << "ShapeDimensions: ";
//      for(int a = 0; a < i; a++)
//      {
//          if(a < i)
//          {
//              cout << shapeDemensions[a] << ", ";
//          }
//          else
//          {
//              cout << shapeDemensions[a];
//          }

//      }
//      cout << endl;
//      cout << "PenColor: " << penColor << endl;
//      cout << "PenWidth: " << penWidth << endl;
//      cout << "PenStyle: " << penStyle << endl;
//      cout << "PenCapStyle: " << penCapStyle << endl;
//      cout << "penJoinStyle: " << penJoinStyle << endl;
//      cout << "BrushColor: " << brushColor << endl;
//      cout << "BrushStyle: " << brushStyle << endl;
//      cout << endl << endl;

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

Qt::GlobalColor convertColor(const string &str)
{
    if (str == "white")
    {
        return Qt::white;
    }
    else if (str == "black")
    {
        return Qt::black;
    }
    else if (str == "red")
    {
        return Qt::red;
    }
    else if (str == "green")
    {
        return Qt::green;
    }
    else if (str == "blue")
    {
        return Qt::blue;
    }
    else if (str == "cyan")
    {
        return Qt::cyan;
    }
    else if (str == "magenta")
    {
        return Qt::magenta;
    }
    else if (str == "yellow")
    {
        return Qt::yellow;
    }
    else if (str == "gray")
    {
        return Qt::gray;
    }
    else
    {
        return Qt::black;
    }
}


Qt::PenStyle convertPenStyle(const string &str)
{
    if (str == "NoPen")
        return Qt::NoPen;
    else if (str == "SolidLine")
        return Qt::SolidLine;
    else if (str == "DashLine")
        return Qt::DashLine;
    else if (str == "DotLine")
        return Qt::DotLine;
    else if (str == "DashDotLine")
        return Qt::DashDotLine;
    else if (str == "DashDotDotLine")
        return Qt::DashDotDotLine;
    else
        return Qt::NoPen;
}


Qt::PenCapStyle convertPenCapStyle(const string &str)
{
    if (str == "FlatCap")
        return Qt::FlatCap;
    else if (str == "SquareCap")
        return Qt::SquareCap;
    else if (str == "RoundCap")
        return Qt::RoundCap;
    else
        return Qt::FlatCap;
}


Qt::PenJoinStyle convertPenJoinStyle(const string &str)
{
    if (str == "MiterJoin")
        return Qt::MiterJoin;
    else if (str == "BevelJoin")
        return Qt::BevelJoin;
    else if (str == "RoundJoin")
        return Qt::RoundJoin;
    else
        return Qt::MiterJoin;
}


Qt::BrushStyle convertBrushStyle(const string &str)
{
    if (str == "SolidPattern")
        return Qt::SolidPattern;
    else if (str == "HorPattern")
        return Qt::HorPattern;
    else if (str == "VerPattern")
        return Qt::VerPattern;
    else if (str == "NoBrush")
        return Qt::NoBrush;
    else
        return Qt::SolidPattern;
}


Qt::AlignmentFlag convertAlignment(const string &str)
{
    if (str == "AlignLeft")
        return Qt::AlignLeft;
    else if (str == "AlignRight")
        return Qt::AlignRight;
    else if (str == "AlignTop")
        return Qt::AlignTop;
    else if (str == "AlignBottom")
        return Qt::AlignBottom;
    else if (str == "AlignCenter")
        return Qt::AlignCenter;
}


QFont::Style convertStyle(const string &str)
{
    if (str == "StyleNormal")
        return QFont::StyleNormal;
    else if (str == "StyleItalic")
        return QFont::StyleItalic;
    else if (str == "StyleOblique")
        return QFont::StyleOblique;
    else
        return QFont::StyleNormal;
}


QFont::Weight convertWeight(const string &str)
{
    if (str == "Thin")
        return QFont::Thin;
    else if (str == "Light")
        return QFont::Light;
    else if (str == "Normal")
        return QFont::Normal;
    else if (str == "Bold")
        return QFont::Bold;
}

//ShapeId: 2
//ShapeType: Polyline
//ShapeDimensions: 460, 90, 470, 20, 530, 40, 540, 80
//PenColor: green
//PenWidth: 6
//PenStyle: SolidLine
//PenCapStyle: FlatCap
//PenJoinStyle: MiterJoin

//ShapeId: 3
//ShapeType: Polygon
//ShapeDimensions: 900, 90, 910, 20, 970, 40, 980, 80
//PenColor: cyan
//PenWidth: 6
//PenStyle: DashDotDotLine
//PenCapStyle: FlatCap
//PenJoinStyle: MiterJoin
//BrushColor: yellow
//BrushStyle: SolidPattern

//ShapeId: 4
//ShapeType: Rectangle
//ShapeDimensions: 20, 200, 170, 100
//PenColor: blue
//PenWidth: 0
//PenStyle: DashLine
//PenCapStyle: RoundCap
//PenJoinStyle: RoundJoin
//BrushColor: red
//BrushStyle: VerPattern

//ShapeId: 5
//ShapeType: Square
//ShapeDimensions: 250, 150, 200
//PenColor: red
//PenWidth: 0
//PenStyle: SolidLine
//PenCapStyle: RoundCap
//PenJoinStyle: RoundJoin
//BrushColor: blue
//BrushStyle: HorPattern

//ShapeId: 6
//ShapeType: Ellipse
//ShapeDimensions: 520, 200, 170, 100
//PenColor: black
//PenWidth: 12
//PenStyle: SolidLine
//PenCapStyle: FlatCap
//PenJoinStyle: MiterJoin
//BrushColor: white
//BrushStyle: NoBrush

//ShapeId: 7
//ShapeType: Circle
//ShapeDimensions: 750, 150, 200
//PenColor: black
//PenWidth: 12
//PenStyle: SolidLine
//PenCapStyle: FlatCap
//PenJoinStyle: MiterJoin
//BrushColor: magenta
//BrushStyle: SolidPattern

//ShapeId: 8
//ShapeType: Text
//ShapeDimensions: 250, 425, 500, 50
//TextString: Class Project 2 - 2D Graphics Modeler
//TextColor: blue
//TextAlignment: AlignCenter
//TextPointSize: 10
//TextFontFamily: Comic Sans MS
//TextFontStyle: FlatCap
//TextFontWeight: Normal
