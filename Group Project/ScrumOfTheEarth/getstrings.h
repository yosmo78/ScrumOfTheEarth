/*! \file */
#ifndef GETSTRINGS_H
#define GETSTRINGS_H
#include <string>
/*!
 * \brief Converts an index to a string for a penstyle
 * \param index for penstyle
 * \return string of penstyle
 */
std::string getPenStyle(int ps);
/*!
 * \brief Converts an index to a string for a color
 * \param index for color
 * \return string for color
 */
std::string getColor(int color);
/*!
 * \brief Converts an index to a string for a pen cap style
 * \param index for pen cap style
 * \return string for pen cap style
 */
std::string getPenCapStyle(int pcs);
/*!
 * \brief Converts an index to a string for a pen join style
 * \param index for pen join style
 * \return string for pen join style
 */
std::string getPenJoinStyle(int pjs);
/*!
 * \brief Converts an index to a string for a brush style
 * \param index for brush style
 * \return string for brush style
 */
std::string getBrushStyle(int bs);
/*!
 * \brief Converts an index to a string for a text alignment
 * \param index for text alignment
 * \return string for text alignment
 */
std::string getTextAlignment(int ta);
/*!
 * \brief Converts an index to a string for a font style
 * \param index for font style
 * \return string for font style
 */
std::string getFontStyle(int fs);
/*!
 * \brief Converts an index to a string for font weight
 * \param index for font weight
 * \return string for font weight
 */
std::string getFontWeight(int fw);

#endif // GETSTRINGS_H
