#ifndef _ITERATOR_H
#define _ITERATOR_H

class Order; // Forward declaration

class Iterator
{
public:
    Iterator();
    virtual ~Iterator();
    virtual Order* next() = 0;
    virtual bool isDone() = 0;
    virtual Order* currentItem() = 0;
};

#endif
