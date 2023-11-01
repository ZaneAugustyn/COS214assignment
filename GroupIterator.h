#ifndef _ORDERITERATOR_H
#define _ORDERITERATOR_H

class Order;
#include "OrderComponent.h"
#include <vector>

using namespace std;

class GroupIterator {
private:
    Order* order_;

public:
    GroupIterator();
    GroupIterator(Order* order);
    ~GroupIterator();
    Order* next();
    bool isDone();
    Order* currentItem();
    void setOrder(Order* o);
};

#endif
