#pragma once
#include<QTcpServer>
#include<QTcpSocket>
#include<QDataStream>
#include<QByteArray>
#include<QApplication>
#include"database.h"

const quint16 Port = 5365;

class Server : public QObject
{
    Q_OBJECT
private:
    QTcpServer*_server;
    struct send{
        int id;
        QString name;
        int price;
        int count;
        QString img;
        QString desc;
        send(int id,QString name,int price,int count,QString img,QString desc)
            :id(id),name(name),price(price),count(count),img(img),desc(desc){}
    };

    QList<QTcpSocket*>_sockets;
    QList<send>_data;
    DataBase *_dataBase;
    void readFromDB();
public:
    Server(QObject*pwgt = nullptr , DataBase* dataBase = nullptr);
    ~Server();
public slots:
    //void getFromClient();
    void sendUpdateData()
    {
        for(auto i:_sockets)
        {
            sendToClient(i);
        }
    }
    void updateCount();
    void slotNewConnection();
    void slotReadDataBase(){ readFromDB();}
    void sendToClient(QTcpSocket*);
signals:
    void countUpdate(const int id,const int value);
};

