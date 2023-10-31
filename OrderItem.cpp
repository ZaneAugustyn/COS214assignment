#include "OrderItem.h"

OrderItem::OrderItem(double price, string name)
{
    price_ = price;
    name_ = name;
}

OrderItem::~OrderItem()
{
}

double OrderItem::getPrice()
{

    return price_;

}