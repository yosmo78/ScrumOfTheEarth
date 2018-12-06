/*! \file */
#ifndef POP_TABLE_H
#define POP_TABLE_H
#include "vector.h"
#include <QTableWidget>
#include "shape.h"

void pop_Atable(QTableWidget*, myStd::vector<Shape*>);//fills table with area
void pop_Ptable(QTableWidget*, myStd::vector<Shape*>);//fills table with perimeter
void fill_table(QTableWidget*, myStd::vector<Shape*>);//fills table up with all parameters


#endif // POP_TABLE_H
