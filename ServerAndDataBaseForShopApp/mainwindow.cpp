#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtSql>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _db = new DataBase();
    _db->connectToDB();
    //_server->slotReadDataBase();
    _server = new Server(nullptr,_db);
    showTable();

    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::onPressed);
    connect(ui->deleteButton,&QPushButton::clicked,this,&MainWindow::onPressedDelete);


    connect(_db,&DataBase::update,_server,&Server::slotReadDataBase);
    connect(_server,&Server::countUpdate,this,&MainWindow::updateDataBase);
}

void MainWindow::onPressed()
{
    _db->connectToDB();
    QVariantList list;
    list.append(ui->lineEdit->text());
    list.append(ui->lineEdit_2->text());
    list.append(ui->lineEdit_3->text());
    list.append(ui->lineEdit_4->text());

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();

    _db->insertIntoTable(list);
    showTable();
    emit _db->update();
    _db->closeDB();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTable()
{
    _db->connectToDB();
    QSqlQuery query(_db->getDataBase());
    query.exec("SELECT * FROM testtable");

    ui->textBrowser->clear();
    while (query.next()) {
        auto id = query.record().value(0).toString();
        auto name= query.record().value(1).toString();
        auto price=query.record().value(2).toString();
        auto count = query.record().value(3).toString();
        auto desc = query.record().value(4).toString();
        ui->textBrowser->append("--------------------------------------------");
        ui->textBrowser->append(id+" | "+name+" | "+price+" | "+count+" | "+desc+"");
        ui->textBrowser->append("--------------------------------------------");
    }
    _db->closeDB();
}


void MainWindow::onPressedDelete()
{
    _db->connectToDB();
    _db->removeRecord(ui->idEdit->text().toInt());
    ui->idEdit->clear();
    showTable();
    emit _db->update();
    _db->closeDB();

}

void MainWindow::updateDataBase(const int id,const int count)
{
    _db->connectToDB();
    _db->updateRow(id,count);
    emit _db->update();
    showTable();
    _db->closeDB();
}
