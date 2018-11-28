#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "vector.h"
#include "shape.h"

using namespace std;

void shape_parser(myStd::vector<Shape*>& vec, const char* filename, bool &ok)//the paint device will be the renderarea
{
  int shapeID = 99999;
  string shapeType = "nullptr";
  int shapeDemensions[10];
  string penColor = "nullptr";
  int penWidth = 0;
  string penStyle = "nullptr";
  string penCapStyle = "nullptr";
  string penJoinStyle = "nullptr";
  string brushColor = "nullptr";
  string brushStyle = "nullptr";
  string textString = "nullptr";
  string textColor = "nullptr";
  string textAlignment = "nullptr";
  string textPointSize = "nullptr";
  string textFontFamily = "nullptr";
  string textFontStyle = "nullptr";
  string textFontWeight = "nullptr";

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

          cout << "Square" << endl; // Init. Square OBJ
      }
      else if(shapeType == "Ellipse")
      {
          getline(fin, skip, ' ');
          getline(fin, skip);
          ss.str(skip);

  //			cout << '\t'<< skip << endl;

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

          cout << "Ellipse" << endl; // Init. Ellipse OBJ
      }
      else if(shapeType == "Circle")
      {
          getline(fin, skip, ' ');
          getline(fin, skip);
          ss.str(skip);


          cout << '\t' << skip << endl;


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
          getline(fin, textString);

          getline(fin, skip, ' ');
          getline(fin, textColor);

          getline(fin, skip, ' ');
          getline(fin, textAlignment);

          getline(fin, skip, ' ');
  //			getline(fin, textPointSize);
          fin >> textPointSize;

          getline(fin, skip, ' ');
          getline(fin, textFontFamily);

          getline(fin, skip, ' ');
          getline(fin, textFontStyle);

          getline(fin, skip, ' ');
          getline(fin, textFontWeight);

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
