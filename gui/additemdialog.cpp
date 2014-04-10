#include "additemdialog.h"
#include "ui_additemdialog.h"

AddItemDialog::AddItemDialog(ApplicationController * controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItemDialog)
{
    ui->setupUi(this);
    this->controller = controller;
    this->addPointPushButton = ui->addPointPushButton;
    this->pointList = ui->pointListView;
    this->pointList->setModel(&this->controller->gPointList);
    this->nameLineEdit = ui->nameLineEdit;
    connect(addPointPushButton, &QPushButton::clicked, this, &AddItemDialog::onAddPointClick);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &AddItemDialog::onButtonBoxAccept);
}

AddItemDialog::~AddItemDialog()
{
    delete ui;
}

void AddItemDialog::onAddPointClick(bool)
{
    double xValue = ui->xLineEdit->text().toDouble();
    double yValue = ui->yLineEdit->text().toDouble();
    this->controller->createPoint(xValue, yValue);
}

void AddItemDialog::onButtonBoxAccept()
{
    QString name = this->nameLineEdit->text();
    this->controller->buildObject(name);
}
