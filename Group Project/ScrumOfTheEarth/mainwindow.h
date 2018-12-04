#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "addshape.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, bool admin = false);
    ~MainWindow();

private slots:


    void on_FileButton_clicked();
    void on_Save_clicked();
    void on_AddShape_clicked();
    void on_DeleteShape_clicked();

private:
    Ui::MainWindow *ui;
    AddShape * addshape;
    bool isAdmin;
    QString file;
};

#endif // MAINWINDOW_H
