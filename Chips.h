#ifndef _CHIPS_H
#define _CHIPS_H

#include "Side.h"

/**
 * @class Chips
 * @brief This class inherits from Side and represents chips
*/

class Chips : public Side
{
private:
public:

    /**
     * @brief default constructor - sets Sides's attributes to the values of chips
     * @return none
    */
    Chips();

    /**
     * @brief destructor
     * @return none
    */
    ~Chips();
};



#endif
