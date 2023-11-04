#ifndef _DRINKCHEF_H
#define _DRINKCHEF_H

#include "Chef.h"

class Plate;
class OrderItem;

/**
 * @class DrinkChef
 * @brief This class is a Concrete Handler of the Chain of Responsibility Pattern
*/

class DrinkChef : public Chef
{
public:
    /**
     * @brief default constructor
     * @return none
    */
    DrinkChef();
    /**
     * @brief destructor
     * @return none
    */
    virtual ~DrinkChef();
    /**
     * @brief part of the chain of responsibility design pattern to delegate to handle the order
     * @param plate pass the plate object to which the food will be added
     * @param orderComp hold the group order to be handled through the chain
     * @return void
    */
    void handleOrder(Plate* plate, vector<OrderComponent*> orderComp);
};

#endif
