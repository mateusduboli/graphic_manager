#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(ApplicationController *controller, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    controller(controller),
    dialog(new AddItemDialog(controller))
{
    ui->setupUi(this);

    // Models
    ui->graphicsView->setScene(&this->controller->scene);
    QGraphicsView *view = ui->graphicsView;
    this->controller->scene.setSceneRect(0,0, view->width(), view->height());
    ui->listView->setModel(&this->controller->displayFile);

    // Connections
    connect(ui->addGraphicalObjectButton, &QPushButton::clicked, this->dialog, &AddItemDialog::open);

    //Zoom connections
    connect(ui->standartZoomPushButton, &QPushButton::clicked, this->controller, &ApplicationController::resetZoom);
    connect(ui->lessZoomPushButton, &QPushButton::clicked, this->controller, &ApplicationController::lessZoom);
    connect(ui->moreZoomPushButton, &QPushButton::clicked, this->controller, &ApplicationController::moreZoom);
    connect(this->controller, &ApplicationController::zoomChanged, ui->zoomLineEdit, &QLineEdit::setText);

    //Move connections
    connect(ui->centerPushButton, &QPushButton::clicked, this->controller, &ApplicationController::centerPosition);
    connect(ui->moveLeftPushButton, &QPushButton::clicked, this->controller, &ApplicationController::moveLeft);
    connect(ui->moveUpPushButton, &QPushButton::clicked, this->controller, &ApplicationController::moveUp);
    connect(ui->moveDownPushButton, &QPushButton::clicked, this->controller, &ApplicationController::moveDown);
    connect(ui->moveRightPushButton, &QPushButton::clicked, this->controller, &ApplicationController::moveRight);
    connect(this->controller, &ApplicationController::centerChanged, ui->positionLineEdit, &QLineEdit::setText);


    // Lazy objects
    this->controller->setWindowSize(GPoint(0,0), QSize(100, 100));
}

MainWindow::~MainWindow()
{
    delete ui;
}
