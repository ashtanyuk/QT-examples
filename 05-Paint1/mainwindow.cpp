#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QPaintEvent>
#include<QTimer>
#include<QThread>
#include<stdlib.h>
#include<time.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
    timer.setInterval(200);
    timer.start();
    connect(&timer,SIGNAL(timeout()),this,SLOT(timeout()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeout()
{
   this->update();
}

void MainWindow::paintEvent(QPaintEvent *pe)
{

    QPainter painter(this);
    QBrush brush(Qt::red,Qt::Dense4Pattern);
    painter.setBrush(Qt::Dense1Pattern);
    QColor color;
    int width=this->width();
    int height=this->height();

    brush.setColor(color.fromRgb(rand()%256,rand()%256,rand()%256));
    painter.fillRect(rand()%width/2,rand()%height/2,rand()%width,rand()%height,brush);
    painter.end();
}
