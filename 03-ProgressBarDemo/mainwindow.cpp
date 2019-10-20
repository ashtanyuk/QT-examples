#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qt=new QTimer;ui->progressBar->setValue(0);
    tval=0;

    connect(ui->pbStart,SIGNAL(clicked()),this,SLOT(start()));
    connect(ui->pbStop,SIGNAL(clicked()),this,SLOT(stop()));
    connect(ui->pbReset,SIGNAL(clicked()),this,SLOT(reset()));
    connect(this->qt,SIGNAL(timeout()),this,SLOT(timeout()));
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::timeout()
{
    if(tval<=100)
        ui->progressBar->setValue(tval++);
    else
    {
        qt->stop();
        QMessageBox qmb;
        qmb.setText("Timer stops");
        qmb.exec();

    }
}

void MainWindow::start()
{
  qt->setInterval(500);
  qt->start();
}
void MainWindow::stop()
{
  qt->stop();
}
void MainWindow::reset()
{
  tval=0;
}
