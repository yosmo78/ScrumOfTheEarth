/*! \file */
#ifndef DELETE_ZEROS_H
#define DELETE_ZEROS_H
#include "vector.h"
#include "shape.h"

/*!
 * \brief delete_Azeros erases any shape with zero area in a vector of Shape Pointers
 */
void delete_Azeros(myStd::vector<Shape*> &);
/*!
 * \brief delete_Pzeros erases any shape with zero perimeter in a vector of Shape Pointers
 */
void delete_Pzeros(myStd::vector<Shape*>&);

#endif // DELETE_ZEROS_H
