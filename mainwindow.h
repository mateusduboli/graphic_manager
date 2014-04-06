#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mainwindowcontroller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    MainWindow(MainWindowController *controller);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MainWindowController *controller;
    void setupCanvas();
};

#endif // MAINWINDOW_H
