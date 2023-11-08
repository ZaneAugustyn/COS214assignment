#ifndef _MILKSHAKE_H
#define _MILKSHAKE_H

#include "Drink.h"

/**
 * @class Milkshake
 * @brief This class inherits from Drink and represents a milkshake
*/
class Milkshake : public Drink
{
public:

    /**
     * @brief default constructor - sets Drink's attributes to the values of a milkshake
     * @return none
    */
    Milkshake();

    /**
     * @brief destructor
     * @return none
    */
    ~Milkshake();
};

#endif
