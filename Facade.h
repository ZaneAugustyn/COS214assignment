#ifndef _FACADE_H
#define _FACADE_H

#include "Floor.h"
#include "FloorState.h"
#include "Full.h"
#include "SpaceAvailable.h"
#include "MaitreD.h"
#include "OrderComponent.h"
#include "OrderItem.h"
#include "Group.h"
#include "GroupState.h"
#include "Bun.h"
#include "Patty.h"
#include "BeefPatty.h"
#include "ChickenPatty.h"
#include "Side.h"
#include "Salad.h"
#include "Chips.h"
#include "Drink.h"
#include "Milkshake.h"
#include "Soda.h"
#include "Garnish.h"
#include "Lettuce.h"
#include "Tomato.h"
#include "Chef.h"
#include "HeadChef.h"
#include "MeatChef.h"
#include "DrinkChef.h"
#include "SidesChef.h"
#include "GarnishChef.h"
#include "Pass.h"
#include "Colleague.h"
#include "Waiter.h"
#include "WaitForTable.h"
#include "Bill.h"
#include "BillPayment.h"
#include "Customer.h"
#include "CustomerPays.h"
#include "Happy.h"
#include "MakeTab.h"
#include "PayTab.h"
#include "ReadyForBill.h"
#include "ReadyToOrder.h"
#include "SplitBill.h"
#include "Tab.h"
#include "Unhappy.h"
#include "Neutral.h"

using namespace std;
#include <string>

/**
 * @class Facade
 * @brief Facade class that provides a simplified interface for managing a restaurant simulation.
 */
class Facade
{
private:
    /* data */
    Floor* floor_;         
    MaitreD* maitreD_;      
    Chef* chef_;          
    HeadChef* headChef_;    
    Pass* kitchenPass_;    
    int numGroups_ = 0;     

public:
    /**
     * @brief Constructor for the facade class.
     */
    Facade(/* args */);

    /**
     * @brief Destructor for the facade class.
     */
    ~Facade();

    /**
     * @brief Run the restaurant simulation.
     */
    void Run();

    /**
     * @brief Option 1: Add a group to the queue outside the restaurant.
     * @return void
     */
    void Option1();

    /**
     * @brief Option 2: Let a group inside the restaurant.
     * @return void
     */
    void Option2();

    /**
     * @brief Option 3: Let a group place an order.
     * @return void
     */
    void Option3();

    /**
     * @brief Option 4: Let a group pay their bill.
     * @return void
     */
    void Option4();

    /**
     * @brief Option 5: Remove a group from the restaurant.
     * @return void
     */
    void Option5();

    /**
     * @brief Option 6: Exit the simulation.
     * @return void
     */
    void Option6();

    /**
     * @brief Initialize basic components and setup for the restaurant simulation.
     * @return void
     */
    void InitBasic();
    
};

#endif
