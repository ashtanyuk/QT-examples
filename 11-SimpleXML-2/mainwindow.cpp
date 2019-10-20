#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile * file=new QFile("/Users/iMac/Projects/XML/students-2.xml");
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox mess;
        mess.setText("File error!");
        mess.exec();
        return;
    }
    QXmlStreamReader xml(file);
    QXmlStreamReader::TokenType token;
    QString id,name,group;
    while(!xml.atEnd() && !xml.hasError())
    {
        token=xml.readNext();
 //       ui->listStudents->addItem(xml.name().toString());

        if (token == QXmlStreamReader::StartDocument)
           continue;
        if (token == QXmlStreamReader::StartElement)
        {
              if (xml.name() == "students")
                  continue;
              if (xml.name() == "stud")
              {
                  QXmlStreamAttributes attrs=xml.attributes();
                  if(attrs.hasAttribute("id"))
                      id=attrs.value("id").toString();
                  continue;
              }
              if(xml.name()=="name")
              {
                  xml.readNext();
                  name=xml.text().toString();
              }
              if(xml.name()=="group")
              {
                  xml.readNext();
                  group=xml.text().toString();
              }
        }


        if (token == QXmlStreamReader::EndElement)
        {
            if(xml.name()=="stud")
            {
               ui->listStudents->addItem(id+" "+name+  " "+group);

            }
         }
      }

}

MainWindow::~MainWindow()
{
    delete ui;
}
