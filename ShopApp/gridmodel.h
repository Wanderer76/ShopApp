#pragma once
#include<QAbstractListModel>
#include"recivedata.h"


class GridModel: public QAbstractListModel
{
    Q_OBJECT
private:
    QList<Product*>_pizza;
    enum ProdRoles {
        IDROLE = Qt::UserRole+1,
        NAMEROLE,COUNTROLE,PRICEROLE,IMAGEROLE,DESCROLE
    };
    ReciveData *_recive;
public:
    GridModel();
    ~GridModel();
    virtual int rowCount(const QModelIndex&parent = QModelIndex())const override;
    //virtual int columnCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex&index,int role)const override;
    virtual QHash<int,QByteArray>roleNames()const override;
public slots:
  void setCount(const int index,const int value)
    {
        if(index>=0&&index<_pizza.size()-1)
            _pizza.at(index)->setCount(value);
        emit countChanged(_pizza.at(index));
    }
signals:
    void countChanged(Product*);
    void created();
};

