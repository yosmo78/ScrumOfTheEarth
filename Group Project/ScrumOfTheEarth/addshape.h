#ifndef ADDSHAPE_H
#define ADDSHAPE_H
#include "vector.h"
#include "shape.h"
#include <QMainWindow>

namespace Ui {
class AddShape;
}

class AddShape : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddShape(QWidget *parent,myStd::vector<Shape *> &);
    ~AddShape();

private:
    Ui::AddShape *ui;
};

#endif // ADDSHAPE_H
