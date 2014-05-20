#include "edititemdialog.h"
#include "ui_edititemdialog.h"

EditItemDialog::EditItemDialog(ApplicationController *controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditItemDialog)
{
    qDebug() << "[EditItemDialog] constructor";
    ui->setupUi(this);
    this->controller = controller;
    ui->operationsListView->setModel(&this->controller->operationList);

    qDebug() << "[EditItemDialog] connecting";
    connect(ui->scalePushButton, &QPushButton::clicked, this, &EditItemDialog::onScaleButtonClicked);
    connect(ui->rotatePushButton, &QPushButton::clicked, this, &EditItemDialog::onRotateButtonClicked);
    connect(ui->translatePushButton, &QPushButton::clicked, this, &EditItemDialog::onTranslateButtonClicked);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &EditItemDialog::onOkButtonClicked);
    connect(controller, &ApplicationController::selectedObjectChanged, ui->objectLabel, &QLabel::setText);

    qDebug() << "[EditItemDialog] constructor finished";
}

EditItemDialog::~EditItemDialog()
{
    delete ui;
}

void EditItemDialog::onScaleButtonClicked(bool)
{
    const double factor = ui->factorLineEdit->text().toDouble();
    qDebug() << "[EditItemDialog] scale : " << factor;
    this->controller->createOperationScale(factor);
}

void EditItemDialog::onTranslateButtonClicked(bool)
{
    const double xValue = ui->xLineEdit->text().toDouble();
    const double yValue = ui->yLineEdit->text().toDouble();
    qDebug() << "[EditItemDialog] translate :{ x: " << xValue << ", y: " << yValue << " }";
    this->controller->createOperationTranslate(xValue, yValue);
}

void EditItemDialog::onRotateButtonClicked(bool)
{
    const double degrees = ui->degreesLineEdit->text().toDouble();
    qDebug() << "[EditItemDialog] rotate : " << degrees << QString::fromUtf8("\u00B0");
    this->controller->createOperationRotate(degrees);
}

void EditItemDialog::openAtIndex(const QModelIndex &index)
{
    qDebug() << "[EditItemDialog] Editing object at index : " << index;
    this->controller->editObject(index);
    QDialog::open();
}

void EditItemDialog::onOkButtonClicked()
{
    qDebug() << "[EditItemDialog] build operation";
    this->controller->buildOperation();
    this->clear();
}

void EditItemDialog::clear()
{
    this->controller->operationList.clear();
    ui->degreesLineEdit->clear();
    ui->factorLineEdit->clear();
    ui->xLineEdit->clear();
    ui->yLineEdit->clear();
}