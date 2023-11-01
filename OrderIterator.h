#ifndef _ORDERITERATOR_H
#define _ORDERITERATOR_H

#include "Iterator.h" // Include the Iterator class
#include "Order.h"    // Include the Order class

class OrderIterator : public Iterator
{
private:
    Order* order;

public:
    OrderIterator(Order* order);
    ~OrderIterator();
    Order* next() override;
    bool isDone() override;
    Order* currentItem() override;
};

#endif
