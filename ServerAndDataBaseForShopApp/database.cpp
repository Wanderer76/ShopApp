#include "database.h"
#include<QDebug>


DataBase::DataBase(QObject*pwgt):QObject(pwgt)
{
}

DataBase::~DataBase(){closeDB();}

void DataBase::connectToDB()
{
    if(!QFile("C:\\Users\\Artyom\\Documents\\ServerAndDataBaseForShopApp\\DataBase\\Products.sqlite").exists())
    {
        restoreDB();
    }
    else
        openDB();
}

bool DataBase::restoreDB()
{
    if(this->openDB())
        return (this->createDB())?true:false;
    else{
        qDebug()<<"Error restoreDB";
        return false;
    }
    return false;
}

bool DataBase::openDB()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    //_db.setHostName(DataBaseHostName);
    _db.setDatabaseName("C:\\Users\\Artyom\\Documents\\ServerAndDataBaseForShopApp\\DataBase\\Products.sqlite");

    if(_db.open())
        return true;
    else{
        return false;
    }
}

void DataBase::closeDB()
{
    _db.close();
}

bool DataBase::createDB()
{
    QSqlQuery query;

    if(!query.exec("CREATE TABLE testtable ("
                   "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "name TEXT,"
                   "price TEXT,"
                   "count TEXT,"
                   "desc TEXT);"))
    {
        qDebug()<<"DATABASE NOT CREATED"<<"testtable";
        return false;
    }
    else {
        qDebug()<<"CREATED";
        return true;
    }
    return false;
}

bool DataBase::insertIntoTable(const QVariantList&data)
{
    QSqlQuery query;

    query.prepare("INSERT INTO testtable ("
                  "name,"
                  "price,"
                  "count,"
                  "desc)"
                  "VALUES(?,?,?,?);");


    for(auto i:data)
    {
        query.addBindValue(i.toString());
    }
    qDebug()<<data;

    if(!query.exec())
    {
        qDebug()<<"BAD INSERT"<<TableName;
        return false;
    }
    else{
        return true;
}
    return false;
}

bool DataBase::insertIntoTable(const QString &name, const QString &price, const QString &count, const QString &description)
{
    QVariantList list;
    list.append(name);
    list.append(price);
    list.append(count);
    list.append(description);

    if(!insertIntoTable(list))
        return true;
    else
        return false;
}


bool DataBase::removeRecord(const int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM testtable WHERE id= :ID ;");
    query.bindValue(":ID",id);

    if(!query.exec())
    {
        return false;
    }
    else
        return true;
    return false;
}


bool DataBase::updateRow(const int id,const int count)
{

    QSqlQuery query;
    query.prepare("UPDATE testtable SET count = :COUNT WHERE id = :ID");
    query.bindValue(":COUNT",count);
    query.bindValue(":ID",id);
    if(!query.exec())
    {
        return false;
    }
    else
    {
        qDebug()<<"UPDATE";
        return true;
    }

 return false;
}
