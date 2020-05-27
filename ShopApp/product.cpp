#include "product.h"

Product::Product(const quint32 id,const  QString name,const quint32 price,const  quint32 count,const  QString image,const QString description)
    : _id{id},_name{name},_count{count},_price{price},_image{image},_description{description}
{
}

Product::~Product(){}


QString Product::getName() const
{
    return _name;
}

QString Product::getImage() const
{
    return _image;
}

void Product::setImage(const QString &image)
{
    _image = image;
}



void Product::setCount(const quint32 &count)
{
    _count = count;

}

quint32 Product::getCount() const
{
    return _count;
}

quint32 Product::getPrice() const
{
    return _price;
}

quint32 Product::getId() const
{
    return _id;
}
