#ifndef _ITEMITERATOR_H
#define _ITEMITERATOR_H

class Order;   // Forward declaration of Order class 
class OrderComponent;   // Forward declaration of OrderComponent class
#include <vector>

using namespace std;

class ItemIterator 
{
private:
    vector<OrderComponent*> items_;
    int currentIndex_;

public:
    ItemIterator(vector<OrderComponent*> items_);
    OrderComponent* next();
    bool isDone();
    OrderComponent* currentItem();
};

#endif
