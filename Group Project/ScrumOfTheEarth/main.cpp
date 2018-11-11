#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Window w;
    w.setFixedSize(400, 300);
    w.show();

    return a.exec();
}
