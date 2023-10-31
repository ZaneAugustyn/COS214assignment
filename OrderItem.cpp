#include <OrderItem.h>

OrderItem::OrderItem(double price)
{
    price_ = price;
}

OrderItem::~OrderItem()
{
}

double OrderItem::getPrice()
{

    return price_;

}