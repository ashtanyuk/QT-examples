#include "mytcpserver.h"

MyTcpServer::MyTcpServer(QObject *parent) :
    QObject(parent)
{
    server=new QTcpServer(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
    if(!server->listen(QHostAddress::Any,9999)) {
        qDebug()<<"Error!";
    }
    else {
        qDebug()<<"Server started!";
    }
}

void MyTcpServer::newConnection()
{
    // need to grab the socket
    QTcpSocket *socket = server->nextPendingConnection();

    socket->write("Hello client\r\n");
    socket->flush();

    socket->waitForBytesWritten(3000);

    socket->close();
}
