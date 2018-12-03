#ifndef POP_TABLE_H
#define POP_TABLE_H
#include "vector.h"
#include <QTableWidget>
#include "shape.h"

void pop_table(QTableWidget*, myStd::vector<Shape*>);//fills table with all parameters and area and perimeter
void fill_table(QTableWidget*, myStd::vector<Shape*>);//fills table up with all parameters


#endif // POP_TABLE_H
