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

/*!
 * \brief convertColor converts a string to a Global color
 * \return Qt::GlobalColor color
 */
Qt::GlobalColor convertColor(const string&);

/*!
 * \brief convertPenStyle converts a string to a Qt::PenStyle
 * \return PenStyle
 */
Qt::PenStyle convertPenStyle(const string&);

/*!
 * \brief convertPenCapStyle converts a string to a Qt::PenCapStyle
 * \return PenCapStyle
 */
Qt::PenCapStyle convertPenCapStyle(const string&);

/*!
 * \brief convertPenJoinStyle converts a string to a Qt::PenJoinStyle
 * \returnPenJoinStyle
 */
Qt::PenJoinStyle convertPenJoinStyle(const string&);

/*!
 * \brief convertBrushStyle converts a string to a Qt::BrushStyle
 * \return BrushStyle
 */
Qt::BrushStyle convertBrushStyle(const string &);

/*!
 * \brief convertAlignment converts a string to a Qt::AlignmentFlag
 * \return AlignmentFlag
 */
Qt::AlignmentFlag convertAlignment(const string &);
/*!
 * \brief convertStyle converts a string to a QFont::Style
 * \return FontStyle
 */
QFont::Style convertStyle(const string &);
/*!
 * \brief convertWeight converts a string to a QFont::Weight
 * \param str
 * \return FontWeight
 */
QFont::Weight convertWeight(const string &str);

/*!
 * \brief Populates a vector from a given file sets a bool whether it was successful or not
 * \param vector of shape pointers
 * \param filename of shape to read from
 * \param bool for ok status
 */
void shape_parser(myStd::vector<Shape*>& vec, const char* filename, bool &ok);

#endif // SHAPE_PARSER_H
