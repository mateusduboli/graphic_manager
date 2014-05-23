#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(ApplicationController *controller, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    controller(controller),
    addItem(new AddItemDialog(controller)),
    editItem(new EditItemDialog(controller))
{
    qDebug() << "[MainWindow] constructor";
    ui->setupUi(this);

    qDebug() << "[MainWindow] setting models";
    ui->viewport->setWindow(&this->controller->window);
    ui->listView->setModel(&this->controller->displayFile);

    // Button Connections
    qDebug() << "[MainWindow] button connections";
    connect(ui->addGraphicalObjectButton, &QPushButton::clicked, this->addItem, &AddItemDialog::open);

    // Zoom connections
    connect(ui->standartZoomPushButton, &QPushButton::clicked, this->controller, &ApplicationController::resetZoom);
    connect(ui->lessZoomPushButton, &QPushButton::clicked, this->controller, &ApplicationController::lessZoom);
    connect(ui->moreZoomPushButton, &QPushButton::clicked, this->controller, &ApplicationController::moreZoom);
    connect(this->controller, &ApplicationController::zoomChanged, ui->zoomLineEdit, &QLineEdit::setText);

    // Move connections
    connect(ui->centerPushButton, &QPushButton::clicked, this->controller, &ApplicationController::centerPosition);
    connect(ui->moveLeftPushButton, &QPushButton::clicked, this->controller, &ApplicationController::moveLeft);
    connect(ui->moveUpPushButton, &QPushButton::clicked, this->controller, &ApplicationController::moveUp);
    connect(ui->moveDownPushButton, &QPushButton::clicked, this->controller, &ApplicationController::moveDown);
    connect(ui->moveRightPushButton, &QPushButton::clicked, this->controller, &ApplicationController::moveRight);
    connect(this->controller, &ApplicationController::centerChanged, ui->positionLineEdit, &QLineEdit::setText);

    // Edit connections
    connect(ui->listView, &QListView::doubleClicked, this->editItem, &EditItemDialog::openAtIndex);

    qDebug() << "[MainWindow] finished constructor";
}

MainWindow::~MainWindow()
{
    delete ui;
}
