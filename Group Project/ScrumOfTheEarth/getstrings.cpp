#include "getstrings.h"
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
