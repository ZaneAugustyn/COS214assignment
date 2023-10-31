#ifndef _GARNISH_H
#define _GARNISH_H

#include "OrderItem.h"

class Garnish : public OrderItem
{
private:
public:
    Garnish(double price, string name);
    ~Garnish();
};

#endif
