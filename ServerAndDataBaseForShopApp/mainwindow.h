#pragma once

#include <QMainWindow>
#include"database.h"
#include"server.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    DataBase* _db;
    Server*_server;

    void showTable();
private slots:
    void updateDataBase(const int id,const int count);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void onPressed();
    void onPressedDelete();
};
