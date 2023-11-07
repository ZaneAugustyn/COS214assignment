#ifndef _BEEFPATTY_H
#define _BEEFPATTY_H

#include "Patty.h"

/**
 * @class BeefPatty
 * @brief This class inherits from Patty and represents a beef patty
*/
class BeefPatty : public Patty
{
public:

    /**
     * @brief default constructor - sets Patty's attributes to the values of a beef patty - beef patties are always grilled
     * @return none
    */
    BeefPatty();

    /**
     * @brief destructor
     * @return none
    */
    ~BeefPatty();
};

#endif
