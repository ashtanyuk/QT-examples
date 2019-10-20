#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    count=0;
    ui->setupUi(this);
    ui->pushButton->setText("Close me!");
    ui->progressBar->setValue(0);
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(ChangeProgressBar()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ChangeProgressBar()
{
     ui->progressBar->setValue(count+=10);
}
