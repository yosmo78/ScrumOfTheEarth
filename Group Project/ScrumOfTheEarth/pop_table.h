/*! \file */
#ifndef POP_TABLE_H
#define POP_TABLE_H
#include "vector.h"
#include <QTableWidget>
#include "shape.h"
/*!
 * \brief pop_Atable populates a given table with shape types, ids, and areas from a vector of Shape pointers
 */
void pop_Atable(QTableWidget*, myStd::vector<Shape*>);//fills table with area
/*!
 * \brief pop_Ptable populates a given table with shape types, ids, and perimeters from a vector of Shape pointers
 */
void pop_Ptable(QTableWidget*, myStd::vector<Shape*>);//fills table with perimeter
/*!
 * \brief fill_table populates a given table with all aspects of the Shapes form a vector of Shape pointers
 */
void fill_table(QTableWidget*, myStd::vector<Shape*>);//fills table up with all parameters


#endif // POP_TABLE_H
