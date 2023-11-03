#ifndef _ORDERCOMPONENT_H
#define _ORDERCOMPONENT_H

#include "ItemIterator.h"
// #include "GroupIterator.h"

/**
 * @class OrderComponent
 * @brief This class acts as the (abstract) Component participant of the Composite design pattern, and represents any node in the resulting tree structure of orders.
*/

class OrderComponent
{
private:
public:

    /**
     * @brief default constructor
     * @return none
    */
    OrderComponent();

    /**
     * @brief virtual destructor
     * @return none
    */
    virtual ~OrderComponent();

    /**
     * @brief pure virtual getter for price that will be implemented differently in derived classes
     * @return total price of the OrderComponent and any of its children
    */
    virtual double getPrice() = 0;

    // GroupIterator* createIterator();

    /**
     * @brief function that creates an ItemIterator object to iterate over the individual OrderItems in the Order
     * @return a pointer to the ItemIterator object that is created
    */
    ItemIterator* createItemIterator();
};
#endif