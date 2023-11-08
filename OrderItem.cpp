#include "OrderItem.h"

OrderItem::OrderItem(double price, string name)
{
    price_ = price;
    name_ = name;
}

OrderItem::~OrderItem()
{
}

float OrderItem::GetPrice()
{

    return price_;

}

string OrderItem::GetName()
{
    return name_;
}

