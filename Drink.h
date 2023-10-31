#ifndef _DRINK_H
#define _DRINK_H

#include "OrderItem.h"

class Drink : public OrderItem
{
private:
public:
    Drink(double price, string name);
    ~Drink();
};


#endif
