#include "window.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

/*!
 * \brief main entry point for program
 * \param argc number of arguments
 * \param argv arguments as cstrings
 * \return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Window w;
    w.setFixedSize(400, 290);
    w.show();

    return a.exec();
}
