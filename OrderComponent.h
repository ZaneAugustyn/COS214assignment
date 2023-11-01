#ifndef _ORDERCOMPONENT_H
#define _ORDERCOMPONENT_H

#include "ItemIterator.h"
// #include "GroupIterator.h"

class OrderComponent
{
private:
public:
    OrderComponent();
    virtual ~OrderComponent();
    virtual double getPrice() = 0;
    // GroupIterator* createIterator();
    ItemIterator* createItemIterator();
};

#endif