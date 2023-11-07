#ifndef _MEATCHEF_H
#define _MEATCHEF_H

#include "Chef.h"
#include "ChickenPatty.h"

class Plate;
class OrderItem;

/**
 * @class MeatChef
 * @brief This class is a Concrete Handler of the Chain of Responsibility Pattern
*/

class MeatChef : public Chef
{
public:
    /**
     * @brief default constructor
     * @return none
    */
    MeatChef();
    /**
     * @brief destructor
     * @return none
    */
    ~MeatChef();
    /**
     * @brief part of the chain of responsibility design pattern to delegate to handle the order
     * @param plate pass the plate object to which the food will be added
     * @param orderComp hold the group order to be handled through the chain
     * @return void
    */
    void HandleOrder(Plate* plate, vector<OrderComponent*> orderComp);
};

#endif
