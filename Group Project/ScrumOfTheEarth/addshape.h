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

private slots:
    void on_AddSquare_clicked();

private:
    Ui::AddShape *ui;
    myStd::vector<Shape *> * vecPointer;
};

#endif // ADDSHAPE_H
