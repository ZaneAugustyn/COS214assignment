#ifndef _SIDE_H
#define _SIDE_H

#include "OrderItem.h"

class Side : public OrderItem
{
private:
public:
    Side(double price, string name);
    ~Side();
};

#endif
