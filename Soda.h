#ifndef _SODA_H
#define _SODA_H

#include "Drink.h"

/**
 * @class Soda
 * @brief This class inherits from Drink and represents a soda
*/
class Soda : public Drink
{
public:

    /**
     * @brief default constructor - sets Drink's attributes to the values of a soda
     * @return none
    */
    Soda();

    /**
     * @brief destructor
     * @return none
    */
    ~Soda();
};

#endif
