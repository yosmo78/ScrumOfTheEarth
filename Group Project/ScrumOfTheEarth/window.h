#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "contactus.h"

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();

private slots:
    void on_pushButton_clicked();

    void on_PassText_returnPressed();

    void on_Contact_clicked();

private:
    Ui::Window *ui;
    ContactUs * contactus;
};

#endif // WINDOW_H
