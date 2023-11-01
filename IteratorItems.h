#ifndef _ITERATORITEMS_H
#define _ITERATORITEMS_H

class OrderComponent; 

class IteratorItems
{
public:
    IteratorItems();
    virtual ~IteratorItems();
    virtual OrderComponent* next() = 0;
    virtual bool isDone() = 0;
    virtual OrderComponent* currentItem() = 0;
};

#endif
