#include "server.h"
#include<QtSql>
#include<QIODevice>
#include<QHostInfo>
//#include<QSqlQuery>

Server::Server(QObject*pwgt, DataBase* dataBase)
    :QObject(pwgt),_dataBase{dataBase}
{
    _server = new QTcpServer();
    if(!_server->listen(QHostAddress::Any,Port))
    {
        qDebug()<<"Not Connected";
    }
    connect(_server,&QTcpServer::newConnection,this,&Server::slotNewConnection);
}

Server::~Server()
{
    _server->close();
}

void Server::slotNewConnection()
{
    qDebug()<<"NEW CONNECTION";
    QTcpSocket*socket = _server->nextPendingConnection();
    _sockets.push_back(socket);
    readFromDB();
    for(auto i:_data)
    {
        QByteArray out;
        QDataStream stream(&out,QIODevice::WriteOnly);
        stream<<quint32(0)<<i.id<<i.name<<i.price<<i.count<<i.img<<i.desc;
        stream.device()->seek(0);
        stream<<quint32(out.size()-sizeof (quint32));
        socket->write(out);
    }
    _data.clear();
    connect(socket,&QTcpSocket::readyRead,this,&Server::updateCount);
    connect(socket,&QTcpSocket::disconnected,socket,&QTcpSocket::deleteLater);
}

void Server::readFromDB()
{
    qDebug()<<"READING DATA BASE";
    _dataBase->connectToDB();
       // _data.clear();

        QSqlQuery query(_dataBase->getDataBase());
        query.exec("SELECT * FROM testtable");
        int count = query.record().count();
        qDebug()<<count;
        while (query.next()) {
            auto id = query.record().value(0).toInt();
            auto name= query.record().value(1).toString();
            auto price=query.record().value(2).toInt();
            auto count = query.record().value(3).toInt();
            auto desc = query.record().value(4).toString();
            _data.push_back(send(id,name,price,count,"",desc));

            qDebug()<<"ROWS: "<<query.record().value(0).toInt()<<query.record().value(1).toString()<<query.record().value(2).toInt()
                   <<query.record().value(3).toInt()<<query.record().value(4).toString();

        }
         _dataBase->closeDB();

}

void Server::updateCount()
{
    QTcpSocket*socket = (QTcpSocket*)this->sender();
    QDataStream stream(socket);
    int index,count;
    stream>>index>>count;
    qDebug()<<"WE UPDATE "<<index<<count;
    emit this->countUpdate(index,count);
}

void Server::sendToClient(QTcpSocket*socket)
{

    for(auto i:_data)
    {
        QByteArray out;
        QDataStream stream(&out,QIODevice::WriteOnly);
        stream<<quint32(0)<<i.id<<i.name<<i.price<<i.count<<i.img<<i.desc;
        stream.device()->seek(0);
        stream<<quint32(out.size()-sizeof (quint32));
        socket->write(out);

    }
}
