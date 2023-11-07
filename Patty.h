#ifndef _PATTY_H
#define _PATTY_H

#include "OrderItem.h"

/**
 * @class Patty
 * @brief This class inherits from OrderItem and represents a burger patty
*/

class Patty : public OrderItem
{
protected:
    bool grilled_;
public:

    /**
     * @brief constructor
     * @param grilled takes in a boolean value - the Patty will be grilled in the Kitchen if this is true, otherwise it will be fried
     * @param price takes in the price of the Patty
     * @param name takes in a name for the Patty
     * @return none
    */
    Patty(bool grilled, double price, string name);

    /**
     * @brief getter for grilled_
     * @return whether the Patty should be grilled (or alternatively, fried) in the Kitchen
    */
    bool getGrilledStatus();

    /**
     * @brief destructor
     * @return none
    */
    ~Patty();
};

#endif
