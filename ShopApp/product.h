#pragma once
#include<QImage>

class Product
{
private:
    QString _name;
    QString _image;
    QString _description;
    quint32 _id;
    quint32 _count;
    quint32 _price;
public:
    Product(const quint32 id,const QString name,const quint32 price,const quint32 count,const QString image,const QString description);
    ~Product();
    void operator=(const Product prod){

        this->_id = prod._id;
        this->_name = prod._name;
        this->_count = prod._count;
        this->_price = prod._price;
        this->_image = prod._image;
        this->_description = prod._description;
    }
public slots:
    QString getName() const;
    QString getImage() const;
    quint32 getCount() const;
    quint32 getPrice() const;
    quint32 getId() const;
    QString getDesc()const{return _description;}
    void setImage(const QString &image);
    void setCount(const quint32 &count);
signals:
    void dataChanged();
};

