#ifndef _DRINK_H
#define _DRINK_H

#include "OrderItem.h"

/**
 * @class Drink
 * @brief This class inherits from OrderItem and represents a drink that a guest can have with their burger
*/

class Drink : public OrderItem
{
private:
public:

    /**
     * @brief constructor
     * @param price takes in the price of the drink
     * @param name takes in a name for the drink
     * @return none
    */
    Drink(double price, string name);

    /**
     * @brief destructor
     * @return none
    */
    ~Drink();
};


#endif
