#include "gridmodel.h"
#include<QByteArray>
#include<QModelIndex>

GridModel::GridModel()
{
    _recive = new ReciveData;
    qDebug()<<"SIZE OF PIZZA: "<<_pizza.size();
    connect(_recive,&ReciveData::allDownload,this,[&](){

        if(_pizza.size()!=0)
        {
            emit beginRemoveRows(QModelIndex(),0,_pizza.size()-1);
            _pizza.clear();
            emit endRemoveRows();
        }

        //_pizza = _recive->getProducts();
        beginInsertRows(QModelIndex(),0,_recive->size()-1);
        for(const auto &i: _recive->getProducts())
        {
            _pizza.push_back(new Product(i->getId(),i->getName(),i->getPrice(),i->getCount(),i->getImage(),i->getDesc()));
        }
        _pizza.toSet();
        endInsertRows();
        emit dataChanged(createIndex(0,0),createIndex(0,_pizza.size()-1));
    });


    //connect(this,&GridModel::created,_recive,&ReciveData::connect);
    connect(this,&GridModel::countChanged,_recive,&ReciveData::load);
}

GridModel::~GridModel()
{
    _pizza.clear();
}

int GridModel::rowCount(const QModelIndex &parent) const
{
    return _pizza.size();
}

QHash<int,QByteArray> GridModel::roleNames() const
{
    QHash<int,QByteArray> roles;
    roles[ProdRoles::IDROLE] = "id";
    roles[ProdRoles::NAMEROLE]  ="name";
    roles[ProdRoles::COUNTROLE] = "count";
    roles[ProdRoles::PRICEROLE] = "price";
    roles[ProdRoles::IMAGEROLE] = "image";
    roles[ProdRoles::DESCROLE] = "descrip";
    return roles;
}

QVariant GridModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()==false || index.row() > this->rowCount())
    {
        return {};
    }
    else if(role == ProdRoles::IDROLE)
        return QVariant::fromValue(_pizza.at(index.row())->getId());
    else if (role == ProdRoles::NAMEROLE)
        return QVariant::fromValue(_pizza.at(index.row())->getName());
    else if(role==ProdRoles::COUNTROLE)
        return QVariant::fromValue(_pizza.at(index.row())->getCount());
    else if(role ==ProdRoles::PRICEROLE)
        return QVariant::fromValue(_pizza.at(index.row())->getPrice());
    else if(role == ProdRoles::IMAGEROLE)
        return QVariant::fromValue(_pizza.at(index.row())->getImage());
    else if(role==ProdRoles::DESCROLE)
        return QVariant::fromValue(_pizza.at(index.row())->getDesc());
    else
        return {};
}
