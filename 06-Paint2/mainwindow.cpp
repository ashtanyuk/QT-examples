#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QPaintEvent>
#include<QTimer>
#include<QThread>
#include<stdlib.h>
#include<time.h>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
    timer.setInterval(100);
    timer.start();
    connect(&timer,SIGNAL(timeout()),this,SLOT(timeout()));
    scene=new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,ui->graphicsView->width(),ui->graphicsView->height());
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
    QBrush brush(Qt::red,Qt::Dense1Pattern);
    QPen pen(Qt::blue);
    QColor color;

    int width=scene->width();
    int height=scene->height();
    int x1=rand()%width/4;
    int y1=rand()%height/4;
    int x2=rand()%width;
    int y2=rand()%height;

    //QRect rect(x1,y1,x2,y2);
    pen.setColor(color.fromRgb(rand()%256,rand()%256,rand()%256));
    brush.setColor(color.fromRgb(rand()%256,rand()%256,rand()%256));
    scene->addRect(x1,y1,x2,y2,pen,brush);

}
