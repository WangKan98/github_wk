#ifndef UDPSEVER_H
#define UDPSEVER_H

#include <QObject>
#include <QUdpSocket>

#define BYTE unsigned char
#pragma pack(1)
struct Original_data{
    char user_id[3];
    char operation[3];
    long long  time;
    double  longitude;
    double  latitude;
};
#pragma pack()

class UdpSever : public QObject
{
    Q_OBJECT
public:

    UdpSever(QObject *parent = 0);
    ~UdpSever();


public slots:
    void dataReceived();

private:
    QUdpSocket *udpSocket;
    void processDatagram(QByteArray  recvMsg);

};

#endif // UDPSEVER_H



