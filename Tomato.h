#ifndef _TOMATO_H
#define _TOMATO_H

#include "Garnish.h"

/**
 * @class Tomato
 * @brief This class inherits from Garnish and represents tomato to garnish a burger
*/
class Tomato : public Garnish
{
public:

    /**
     * @brief default constructor - sets Garnish's attributes to the values of tomato
     * @return none
    */
    Tomato();

    /**
     * @brief destructor
     * @return none
    */
    ~Tomato();
};

#endif
