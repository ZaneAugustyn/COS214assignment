#ifndef _LETTUCE_H
#define _LETTUCE_H

#include "Garnish.h"

/**
 * @class Lettuce
 * @brief This class inherits from Garnish and represents lettuce to garnish a burger
*/
class Lettuce : public Garnish
{
public:

    /**
     * @brief default constructor - sets Garnish's attributes to the values of lettuce
     * @return none
    */
    Lettuce();

    /**
     * @brief destructor
     * @return none
    */
    ~Lettuce();
};

#endif