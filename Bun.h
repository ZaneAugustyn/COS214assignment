#ifndef _BUN_H
#define _BUN_H

#include "OrderItem.h"

/**
 * @class Bun
 * @brief This class inherits from OrderItem and represents a burger bun to be served in the restaurant
*/

class Bun : public OrderItem
{
private:
public:

    /**
     * @brief default constructor - sets OrderItem's attributes to the values of a bun
     * @return none
    */
    Bun();

    /**
     * @brief destructor
     * @return none
    */
    ~Bun();
};


#endif