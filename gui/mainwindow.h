#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "controller/applicationcontroller.h"
#include "gui/additemdialog.h"
#include "gui/edititemdialog.h"

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
    AddItemDialog *addItem;
    EditItemDialog *editItem;
    QPushButton *addItemButton;
};

#endif // MAINWINDOW_H
