#include "window.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "vector.h"
#include "shape.h"

static myStd::vector<Shape*> shapes;//global vector to draw shapes from

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Window w;
    w.setFixedSize(400, 290);
    w.show();

    return a.exec();
}
