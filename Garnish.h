#ifndef _GARNISH_H
#define _GARNISH_H

#include "OrderItem.h"

/**
 * @class Garnish
 * @brief This class inherits from OrderItem and represents garnish that a guest can have on their burger
*/

class Garnish : public OrderItem
{
private:
public:

    /**
     * @brief constructor
     * @param price takes in the price of the Side
     * @param name takes in a name for the Side
     * @return none
    */
    Garnish(double price, string name);

    /**
     * @brief destructor
     * @return none
    */
    ~Garnish();
};

#endif
