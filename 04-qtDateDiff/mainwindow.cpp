#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pbCalc,SIGNAL(clicked()),this,SLOT(calc()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calc()
{
    QDateTime first=ui->dteFirst->dateTime();
    QDateTime second=ui->dteSecond->dateTime();
    int diff=second.daysTo(first);
    QString str=QString::number(diff);
    ui->teDiff->setPlainText(str);

}

void MainWindow::on_pushButton_clicked()
{
    ui->dteSecond->setDate(QDate::currentDate());
}
