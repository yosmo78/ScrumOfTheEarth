/*! \file */

#ifndef SHAPE_PARSER_H
#define SHAPE_PARSER_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <QColor>
#include <QString>

#include "vector.h"
#include "shape.h"
#include "line.h"
#include "polyline.h"
#include "polygon.h"
#include "rectangle.h"
#include "square.h"
#include "ellipse.h"
#include "circle.h"
#include "text.h"

using namespace std;

Qt::GlobalColor convertColor(const string&);

Qt::PenStyle convertPenStyle(const string&);

Qt::PenCapStyle convertPenCapStyle(const string&);

Qt::PenJoinStyle convertPenJoinStyle(const string&);

Qt::BrushStyle convertBrushStyle(const string &);

Qt::AlignmentFlag convertAlignment(const string &);

QFont::Style convertStyle(const string &);

QFont::Weight convertWeight(const string &str);

/*!
 *  \fn Populates a vector of shape pointers from a given file
 */
void shape_parser(myStd::vector<Shape*>& vec, const char* filename, bool &ok);

#endif // SHAPE_PARSER_H
