
#ifndef _GARNISHCHEF_H
#define _GARNISHCHEF_H

#include "Chef.h"

class Plate;
class OrderItem;

/**
 * @class GarnishChef
 * @brief This class is a Concrete Handler of the Chain of Responsibility Pattern
*/
class GarnishChef : public Chef
{
public:
    /**
     * @brief default constructor
     * @return none
    */
    GarnishChef();
    
    /**
     * @brief destructor
     * @return none
    */
    virtual ~GarnishChef();
    /**
     * @brief part of the chain of responsibility design pattern to delegate to handle the order
     * @param plate pass the plate object to which the food will be added
     * @param orderComp hold the group order to be handled through the chain
     * @return void
    */
    void HandleOrder(Plate* plate, vector<OrderComponent*> orderComp);
};

#endif
