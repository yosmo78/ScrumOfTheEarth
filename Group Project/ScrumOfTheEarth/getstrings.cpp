#include "getstrings.h"

//throw in the text conversion segments

std::string getPenStyle(int ps)
{
    std::string penStyle = "NoPen";
    switch(ps)
    {
      case 0: penStyle = "NoPen";
        break;
      case 1: penStyle = "SolidLine";
        break;
      case 2: penStyle = "DashLine";
        break;
      case 3: penStyle = "DotLine";
        break;
      case 4: penStyle = "DashDotLine";
        break;
      case 5: penStyle = "DashDotDotLine";
        break;
    }
    return penStyle;
}

std::string getColor(int color)
{
    std::string brushColor = "black";
    switch(color)
    {
      case 0: brushColor = "white";
                break;
      case 1: brushColor = "black";
              break;
      case 2: brushColor = "red";
              break;
      case 3: brushColor = "green";
              break;
      case 4: brushColor = "blue";
              break;
      case 5: brushColor = "cyan";
              break;
      case 6: brushColor = "magenta";
              break;
      case 7: brushColor = "yellow";
              break;
      case 8: brushColor = "gray";
              break;
    }
    return brushColor;
}

std::string getPenCapStyle(int pcs)
{
    std::string pc = "FlatCap";
    switch(pcs)
    {
      case 0: pc = "FlatCap";
        break;
      case 1: pc = "SquareCap";
        break;
      case 2: pc = "RoundCap";
        break;
    }

    return pc;
}

std::string getPenJoinStyle(int pjs)
{
    std::string pc = "MiterJoin";
    switch(pjs)
    {
      case 0: pc = "MiterJoin";
        break;
      case 1: pc = "BevelJoin";
        break;
      case 2: pc = "RoundJoin";
        break;
    }

    return pc;
}

std::string getBrushStyle(int bs)
{
    std::string pc = "SolidPattern";
    switch(bs)
    {
      case 0: pc = "SolidPattern";
        break;
      case 1: pc = "HorPattern";
        break;
      case 2: pc = "VerPattern";
        break;
      case 3: pc = "NoBrush";
        break;
    }
    return pc;
}

std::string getTextAlignment(int ta)
{
    std::string pc = "";
    switch(ta)
    {
      case 0: pc = "AlignLeft";
        break;
      case 1: pc = "AlignRight";
        break;
      case 2: pc = "AlignTop";
        break;
      case 3: pc = "AlignBottom";
        break;
      case 4: pc = "AlignCenter";
        break;
    }
    if(pc == "") throw 5;
    return pc;
}

std::string getFontStyle(int fs)
{
    std::string pc = "";
    switch(fs)
    {
      case 0: pc = "StyleNormal";
        break;
      case 1: pc = "StyleItalic";
        break;
      case 2: pc = "StyleOblique";
        break;
    }
    if(pc == "") throw 5;
    return pc;
}

std::string getFontWeight(int fw)
{
    std::string pc = "";
    switch(fw)
    {
      case 0: pc = "Thin";
        break;
      case 1: pc = "Light";
        break;
      case 2: pc = "Normal";
        break;
      case 3: pc = "Bold";
        break;
    }
    if(pc == "") throw 5;
    return pc;
}
