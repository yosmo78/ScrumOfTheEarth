#ifndef ADDSHAPE_H
#define ADDSHAPE_H
#include "vector.h"
#include "shape.h"
#include <QMainWindow>

class MainWindow;
namespace Ui {
class AddShape;
}

class AddShape : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddShape(QWidget *parent,myStd::vector<Shape *> &, bool &);
    ~AddShape();

private slots:
    void on_AddSquare_clicked();
signals:
    void update_Window();

private:
    Ui::AddShape *ui;
    myStd::vector<Shape *> * vecPointer;
    bool* var;
};

#endif // ADDSHAPE_H
