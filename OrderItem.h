#ifndef _ORDERITEM_H
#define _ORDERITEM_H

#include <OrderComponent.h>

class OrderItem : public OrderComponent
{
private:
    double price_;
public:
    OrderItem(double price);
    ~OrderItem();
    double getPrice();
};

#endif