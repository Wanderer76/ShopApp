#include "recivedata.h"
//#include<QtSql>
//#include<QSqlQuery>
#include<QByteArray>
#include<QHostAddress>
ReciveData::ReciveData(QObject*pwgt)
    :QObject(pwgt)
{
    _socket = new QTcpSocket;
    _socket->connectToHost("192.168.1.40",5365);
    qDebug()<<"CONNECTED";
    connect(_socket,&QTcpSocket::readyRead,this,&ReciveData::readData);
}

QList<Product *> ReciveData::getProducts()
{

    for(auto i:_products)
    {
        int random = qrand()%5;
        if(random==0)
            i->setImage("qrc:/res/pizza.svg");
        else if(random==1)
            i->setImage("qrc:/res/pizza1.svg");
        else if(random==2)
            i->setImage("qrc:/res/pizza2.svg");
        else if(random==3)
            i->setImage("qrc:/res/pizza3.svg");
        else
            i->setImage("qrc:/res/pizza4.svg");
    }

    return _products;
}

void ReciveData::readData()
{
    qDebug()<<"READING";
    int blockSize=0;
    QDataStream stream(_socket);

    while (true) {
        if(!blockSize)
        {
            if(_socket->bytesAvailable()<sizeof(quint32))
                break;
            stream>>blockSize;
        }

        if(_socket->bytesAvailable()<blockSize)
            break;

        int id;
        QString name;
        int price;
        int count;
        QString img;
        QString desc;
        stream>>id>>name>>price>>count>>img>>desc;
        //   qDebug()<<id<<name<<price<<count<<desc;
        _products.push_back(new Product(id,name,price,count,img,desc));
        blockSize=0;
    }
    emit allDownload();

    for(auto i:_products)
    {
        qDebug()<<i->getId()<<i->getName()<<i->getCount();
    }

}

void ReciveData::load(Product*i)
{
    QByteArray arr;
    QDataStream stream(&arr,QIODevice::WriteOnly);
    stream<<i->getId()<<i->getName()<<i->getPrice()<<i->getCount()<<i->getDesc();
    _socket->write(arr);
    qDebug()<<_socket<<arr;

}

void ReciveData::connected()
{
    _socket->connectToHost("localhost",8965);
    qDebug()<<"CONNECTED";
    connect(_socket,&QTcpSocket::readyRead,this,&ReciveData::readData);
}
