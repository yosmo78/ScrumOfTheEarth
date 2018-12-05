#ifndef MOVESHAPE_H
#define MOVESHAPE_H
#include "vector.h"
#include "shape.h"
#include "square.h"
#include "rectangle.h"
#include "line.h"
#include "circle.h"
#include "ellipse.h"
#include "polygon.h"
#include "polyline.h"
#include "text.h"
#include <string>

#include <QMainWindow>

namespace Ui {
class MoveShape;
}

class MoveShape : public QMainWindow
{
    Q_OBJECT


signals:
    void update_win();
public:
    explicit MoveShape(QWidget *parent, myStd::vector<Shape *> & shapes);
    ~MoveShape();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MoveShape *ui;
    myStd::vector<Shape *> * vecPointer;
};

#endif // MOVESHAPE_H
