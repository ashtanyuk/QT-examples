#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile * file=new QFile("/Users/iMac/Projects/XML/students.xml");
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox mess;
        mess.setText("File error!");
        mess.exec();
        return;
    }
    QXmlStreamReader xml(file);
    QXmlStreamReader::TokenType token;
    while(!xml.atEnd() && !xml.hasError())
    {
        token=xml.readNext();
        if (token == QXmlStreamReader::StartDocument)
           continue;
        if (token == QXmlStreamReader::StartElement)
          {
              if (xml.name() == "students")
                  continue;
              if (xml.name() == "stud")
              {
                  QString id,name;
                  QXmlStreamAttributes attrs=xml.attributes();
                  if(attrs.hasAttribute("id"))
                      id=attrs.value("id").toString();
                  if(attrs.hasAttribute("name"))
                      name=attrs.value("name").toString();
                  ui->listStudents->addItem(id+" "+name);
              }
          }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
