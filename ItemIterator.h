#ifndef _ITEMITERATOR_H
#define _ITEMITERATOR_H

#include "IteratorItems.h" 
#include "Order.h"   
class ItemIterator : public IteratorItems
{
private:
    vector<OrderComponent*> items_;
    int currentIndex_;

public:
    ItemIterator(vector<OrderComponent*> items_);
    OrderComponent* next() override;
    bool isDone() override;
    OrderComponent* currentItem() override;
};

#endif
