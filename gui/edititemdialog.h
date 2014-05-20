#ifndef EDITITEMDIALOG_H
#define EDITITEMDIALOG_H

#include <QDialog>

#include "controller/applicationcontroller.h"

namespace Ui {
class EditItemDialog;
}

class EditItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditItemDialog(ApplicationController* controller, QWidget *parent = 0);
    ~EditItemDialog();

public slots:
    void onScaleButtonClicked(bool);
    void onTranslateButtonClicked(bool);
    void onRotateButtonClicked(bool);
    void onOkButtonClicked();
    void openAtIndex(const QModelIndex & index);
private:
    void clear();
    Ui::EditItemDialog *ui;
    ApplicationController *controller;
};

#endif // EDITITEMDIALOG_H
