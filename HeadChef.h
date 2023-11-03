#ifndef _HEADCHEF_H
#define _HEADCHEF_H

#include <vector>

#include "Chef.h"
class Plate;
class OrderItem;
class Pass;

using namespace std;

/**
 * @class HeadChef
 * @brief This class is a Concrete Handler of the Chain of Responsibility Pattern
*/

class HeadChef : public Chef
{
  public:
    /**
     * @brief default constructor
     * @return none
    */
    HeadChef();
    /**
     * @brief constructor
     * @param p the shared pass member variable
     * @return none
    */
    HeadChef(Pass* p);
    /**
     * @brief part of the chain of responsibility design pattern to delegate to handle the order
     * @param plate pass the plate object to which the food will be added
     * @param orderComp hold the group order to be handled through the chain
     * @return void
    */
    void handleOrder(Plate* plate, vector<OrderComponent*> orderComp) override;
    /**
     * @brief destructor
     * @return none
    */
    virtual ~HeadChef();
  private:
    /**
     * @brief auxilary method to add a completed plate to the tray
     * @param plate pass the plate object to add to the groups tray
     * @return void
    */
    void addToTray(Plate* plate);
};

#endif
