#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *pe);
private:
    Ui::MainWindow *ui;
    QTimer timer;
    QGraphicsScene* scene;
private slots:
    void timeout();
};

#endif // MAINWINDOW_H
