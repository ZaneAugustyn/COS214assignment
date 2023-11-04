#ifndef _SALAD_H
#define _SALAD_H

#include "Side.h"

/**
 * @class Salad
 * @brief This class inherits from Side and represents side salad
*/

class Salad : public Side
{
private:
public:

    /**
     * @brief default constructor - sets Sides's attributes to the values of a salad
     * @return none
    */
    Salad();

    /**
     * @brief destructor
     * @return none
    */
    ~Salad();
};

#endif
