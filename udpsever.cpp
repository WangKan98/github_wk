#include "udpsever.h"
#include <QByteArray>
#include <QDebug>
#include <iostream>
#include "sqlite.h"

const qint16 port = 1234;

UdpSever::UdpSever(QObject *parent):
    QObject(parent)
{
    udpSocket = new QUdpSocket(this);

    bool result = udpSocket->bind(QHostAddress("127.0.0.1"),port);//绑定接收信息的端口号，与发送信息的端口号一致
        if(!result)
        {
            qDebug() << "connect failed";
        }
        else
        {
             qDebug() << "connect success";
        }
        //当有数据报到达时，触发readyRead()信号，执行dataReceived()函数
        connect(udpSocket, SIGNAL(readyRead()), this, SLOT(dataReceived()));
    }
UdpSever::~UdpSever()
{
    delete udpSocket;
}

void UdpSever::dataReceived()
{
    Original_data datagram;
    //QByteArray recvMsg;  //定义字节数组来存储接收的数据
    while(udpSocket->hasPendingDatagrams())//当有数据报等待被读取就返回true
    {
        //recvMsg.resize(udpSocket->pendingDatagramSize());//将数组大小定义成数据报的大小
        QHostAddress sender;
        quint16 senderPort;
        udpSocket->readDatagram((char*)&datagram,sizeof(datagram),&sender,&senderPort);
       // qDebug() << recvMsg.data() <<endl;//将接收到信息输出到控制台
        qDebug()<<datagram.user_id;
        qDebug()<<datagram.operation;
        qDebug()<<datagram.time;
        //processDatagram(recvMsg);
    }

}
/*
void UdpSever::processDatagram(QByteArray  recvMsg)
{
    Original_data datagram;
    udpSocket->readDatagram((char*)&datagram,sizeof(datagram));

    int pos=0;
    memcpy(&datagram->user_id,recvMsg.constData(),sizeof(datagram->user_id));
    pos+=sizeof(datagram->user_id);
    memcpy(&datagram->operation,recvMsg.constData()+pos,sizeof(datagram->operation));
    pos+=sizeof(datagram->operation);
    memcpy(&datagram->otime,recvMsg.constData()+pos,sizeof(datagram->otime));
    pos+=sizeof(datagram->otime);
    qDebug()<<datagram.user_id;
    qDebug()<<datagram.operation;
    qDebug()<<datagram.time;
    QMap<QString, char> datatowirte{
            {"id", datagram.user_id },
            {"lMMSI", datagram.operation},
            {"lIMO", datagram.time},
    };
    QString tablename = "Original Data";
    Sqlite sql;
    sql.add(tablename,datatowirte);
}
*/
