#ifndef _PATTY_H
#define _PATTY_H

#include "OrderItem.h"

class Patty : public OrderItem
{
private:
    bool grilled_;
public:
    Patty(bool grilled, double price, string name);
    ~Patty();
};

#endif
