#ifndef _CHICKENPATTY_H
#define _CHICKENPATTY_H

#include "Patty.h"

/**
 * @class ChickenPatty
 * @brief This class inherits from Patty and represents a chicken patty
*/
class ChickenPatty : public Patty
{
private:
public:

    /**
     * @brief constructor - sets Patty's attributes to the values of a chicken patty - chicken patties can be grilled or fried
     * @return none
    */
    ChickenPatty(bool grilled);

    /**
     * @brief destructor
     * @return none
    */
    ~ChickenPatty();
};

#endif