#ifndef _ORDERCOMPONENT_H
#define _ORDERCOMPONENT_H

#include <Iterator.h>

class OrderComponent
{
private:
public:
    OrderComponent();
    virtual ~OrderComponent();
    virtual double getPrice() = 0;
    Iterator* createIterator();
};

#endif