#ifndef _SIDE_H
#define _SIDE_H

#include "OrderItem.h"

/**
 * @class Side
 * @brief This class inherits from OrderItem and represents a side that a guest can have with their burger
*/
class Side : public OrderItem
{
public:
    /**
     * @brief constructor
     * @param price takes in the price of the Side
     * @param name takes in a name for the Side
     * @return none
    */
    Side(double price, string name);

    /**
     * @brief destructor
     * @return none
    */
    ~Side();
};

#endif
