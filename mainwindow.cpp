#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(MainWindowController *controller) :
    QMainWindow(0),
    ui(new Ui::MainWindow)
{
    this->controller = controller;
    ui->setupUi(this);

    setupCanvas();
}

void MainWindow::setupCanvas()
{
    QGraphicsView *view = ui->graphicsView;
    QGraphicsScene *scene = &this->controller->scene;
    view->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
