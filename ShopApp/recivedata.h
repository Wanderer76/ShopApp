#pragma once
#include<QList>
#include<QTcpSocket>
#include"product.h"

class ReciveData : public QObject
{
    Q_OBJECT
private:
    QTcpSocket* _socket;
    QList<Product*>_products;
public:
    ReciveData(QObject*pwgt=nullptr);
    QList<Product*> getProducts();
    int size()const{return _products.size();}
public slots:
    void readData();
    void load( Product*data);
    void sendCount(const int index,const int count)
    {
        qDebug()<<"Send to Server";
        QByteArray arr;
        QDataStream stream(&arr,QIODevice::WriteOnly);
        stream<<index<<count;
        _socket->write(arr);
    }
    void connected();
signals:
    void allDownload();
    void sendSocket(QTcpSocket*socket);
};

