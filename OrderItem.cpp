#include "OrderItem.h"

OrderItem::OrderItem(double price, string name)
{
    price_ = price;
    name_ = name;
}

OrderItem::~OrderItem()
{
}

float OrderItem::getPrice()
{

    return price_;

}

string OrderItem::getName()
{
    return name_;
}

