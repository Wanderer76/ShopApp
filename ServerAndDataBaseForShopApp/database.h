#pragma once
#include<QObject>
#include<QSql>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QFile>

const QString DataBaseName ="Products.sqlite";
//const QString DataBaseHostName ="ProductsDB";
const QString TableName =  "pizza";


const QString FirstCol = "Name";
const QString SecondCol ="Price";
const QString ThirdCol  ="Count";
const QString ForthCol  ="Description";


class DataBase: public QObject
{
    Q_OBJECT

private:
     QSqlDatabase _db;

    bool openDB();
    bool restoreDB();
    bool createDB();

public:
    DataBase(QObject*pwgt = nullptr);
    ~DataBase();
    void connectToDB();
    void closeDB();
    QSqlDatabase getDataBase()const {return  _db;}
public slots:
    bool insertIntoTable(const QVariantList&data);
    bool insertIntoTable(const QString&name,const QString&price,const QString&count,const QString&description);
    bool removeRecord(const int id);
    bool updateRow(const int id,const int count);
signals:
    void update();
};

