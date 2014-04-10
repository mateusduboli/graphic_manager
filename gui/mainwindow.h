#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "controller/applicationcontroller.h"
#include "gui/additemdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(ApplicationController *controller, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ApplicationController *controller;
    AddItemDialog *dialog;
    QPushButton *addItemButton;
};

#endif // MAINWINDOW_H
