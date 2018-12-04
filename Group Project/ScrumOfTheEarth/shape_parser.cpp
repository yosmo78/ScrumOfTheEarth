#include "shape_parser.h"

using namespace std;

void shape_parser(myStd::vector<Shape*>& vec, const char* filename, bool &ok)//the paint device will be the renderarea
{

  Shape * shape = nullptr;

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

          getline(fin, skip, ':');
          fin >> penWidth;
            fin.ignore(1000, '\n');

          getline(fin, skip, ' ');
          getline(fin, penStyle);

          getline(fin, skip, ' ');
          getline(fin, penCapStyle);

          getline(fin, skip, ' ');
          getline(fin, penJoinStyle);

          shape = new Line(shapeID, shapeDemensions[0], shapeDemensions[1], shapeDemensions[2], shapeDemensions[3], convertColor(penColor), convertPenStyle(penStyle), convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), penWidth);

          vec.push_back(shape);

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

          getline(fin, skip, ' ');
          getline(fin, penStyle);

          getline(fin, skip, ' ');
          getline(fin, penCapStyle);

          getline(fin, skip, ' ');
          getline(fin, penJoinStyle);

          shape = new Polyline(shapeID, dimensions, convertColor(penColor), convertPenStyle(penStyle), convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), penWidth);

          vec.push_back(shape);

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

          shape = new Polygon(shapeID, dimensions, convertColor(penColor), convertColor(brushColor), convertPenStyle(penStyle),convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), convertBrushStyle(brushStyle), penWidth);

          vec.push_back(shape);

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

          shape = new Rectangle(shapeID, shapeDemensions[0], shapeDemensions[1], shapeDemensions[2], shapeDemensions[3] ,convertColor(penColor), convertColor(brushColor), convertPenStyle(penStyle), convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), convertBrushStyle(brushStyle), penWidth);

          vec.push_back(shape);

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

          shape = new Square(shapeID,shapeDemensions[0],shapeDemensions[1],shapeDemensions[2], convertColor(penColor), convertColor(brushColor), convertPenStyle(penStyle), convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), convertBrushStyle(brushStyle), penWidth);

          vec.push_back(shape);

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

          shape = new Ellipse(shapeID,shapeDemensions[0],shapeDemensions[1],shapeDemensions[2], shapeDemensions[3], convertColor(penColor), convertColor(brushColor), convertPenStyle(penStyle), convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), convertBrushStyle(brushStyle), penWidth);

          vec.push_back(shape);

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

          shape = new Circle(shapeID,shapeDemensions[0],shapeDemensions[1],shapeDemensions[2], convertColor(penColor), convertColor(brushColor), convertPenStyle(penStyle), convertPenCapStyle(penCapStyle), convertPenJoinStyle(penJoinStyle), convertBrushStyle(brushStyle), penWidth);

          vec.push_back(shape);

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
          fin >> textPointSize;

          getline(fin, skip, ' ');
          getline(fin, textFontFamilyStr);
          textFontFamily = QString::fromStdString(textFontFamilyStr);

          getline(fin, skip, ' ');
          getline(fin, textFontStyle);

          getline(fin, skip, ' ');
          getline(fin, textFontWeight);

          shape = new Text(shapeID, shapeDemensions[0], shapeDemensions[1], shapeDemensions[2], shapeDemensions[3], textString, convertColor(penColor), convertAlignment(textAlignment), textPointSize, textFontFamily, convertStyle(textFontStyle), convertWeight(textFontWeight));

          vec.push_back(shape);

      }

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
    {
        return Qt::NoPen;
    }
    else if (str == "SolidLine")
    {
        return Qt::SolidLine;
    }
    else if (str == "DashLine")
    {
        return Qt::DashLine;
    }
    else if (str == "DotLine")
    {
        return Qt::DotLine;
    }
    else if (str == "DashDotLine")
    {
        return Qt::DashDotLine;
    }
    else if (str == "DashDotDotLine")
    {
        return Qt::DashDotDotLine;
    }
    else
    {
        return Qt::NoPen;
    }
}


Qt::PenCapStyle convertPenCapStyle(const string &str)
{
    if (str == "FlatCap")
    {
        return Qt::FlatCap;
    }
    else if (str == "SquareCap")
    {
        return Qt::SquareCap;
    }
    else if (str == "RoundCap")
    {
        return Qt::RoundCap;
    }
    else
    {
        return Qt::FlatCap;
    }
}


Qt::PenJoinStyle convertPenJoinStyle(const string &str)
{
    if (str == "MiterJoin")
    {
        return Qt::MiterJoin;
    }
    else if (str == "BevelJoin")
    {
        return Qt::BevelJoin;
    }
    else if (str == "RoundJoin")
    {
        return Qt::RoundJoin;
    }
    else
    {
        return Qt::MiterJoin;
    }
}


Qt::BrushStyle convertBrushStyle(const string &str)
{
    if (str == "SolidPattern")
    {
        return Qt::SolidPattern;
    }
    else if (str == "HorPattern")
    {
        return Qt::HorPattern;
    }
    else if (str == "VerPattern")
    {
        return Qt::VerPattern;
    }
    else if (str == "NoBrush")
    {
        return Qt::NoBrush;
    }
    else
    {
        return Qt::SolidPattern;
    }
}


Qt::AlignmentFlag convertAlignment(const string &str)
{
    if (str == "AlignLeft")
    {
        return Qt::AlignLeft;
    }
    else if (str == "AlignRight")
    {
        return Qt::AlignRight;
    }
    else if (str == "AlignTop")
    {
        return Qt::AlignTop;
    }
    else if (str == "AlignBottom")
    {
        return Qt::AlignBottom;
    }
    else if (str == "AlignCenter")
    {
        return Qt::AlignCenter;
    }
}


QFont::Style convertStyle(const string &str)
{
    if (str == "StyleNormal")
    {
        return QFont::StyleNormal;
    }
    else if (str == "StyleItalic")
    {
        return QFont::StyleItalic;
    }
    else if (str == "StyleOblique")
    {
        return QFont::StyleOblique;
    }
    else
    {
        return QFont::StyleNormal;
    }
}


QFont::Weight convertWeight(const string &str)
{
    if (str == "Thin")
    {
        return QFont::Thin;
    }
    else if (str == "Light")
    {
        return QFont::Light;
    }
    else if (str == "Normal")
    {
        return QFont::Normal;
    }
    else if (str == "Bold")
    {
        return QFont::Bold;
    }
}

