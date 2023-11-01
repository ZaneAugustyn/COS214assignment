#ifndef _ORDERITEM_H
#define _ORDERITEM_H

#include "OrderComponent.h"

#include <string>

using namespace std;

class OrderItem : public OrderComponent
{
private:
    double price_;
    string name_;
public:
    OrderItem(double price, string name);
    ~OrderItem();
    double getPrice();
};

#endif
