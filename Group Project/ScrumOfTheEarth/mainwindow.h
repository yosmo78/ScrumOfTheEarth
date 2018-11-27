#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private:
    Ui::MainWindow *ui;
    bool isAdmin;
    QString file;
};

#endif // MAINWINDOW_H
