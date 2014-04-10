#ifndef ADDITEMDIALOG_H
#define ADDITEMDIALOG_H

#include <QDialog>
#include <QListView>
#include "controller/applicationcontroller.h"

namespace Ui {
class AddItemDialog;
}

class AddItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddItemDialog(ApplicationController * controller, QWidget *parent = 0);
    ~AddItemDialog();

private:
    Ui::AddItemDialog *ui;
    QPushButton *addPointPushButton;
    QListView *pointList;
    ApplicationController *controller;
    QLineEdit *nameLineEdit;
public slots:
    void onAddPointClick(bool);
    void onButtonBoxAccept();
};

#endif // ADDITEMDIALOG_H
