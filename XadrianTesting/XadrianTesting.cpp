#include "../Floor.h"
#include "../FloorState.h"
#include "../Full.h"
#include "../SpaceAvailable.h"
#include "../MaitreD.h"
#include "../OrderComponent.h"
#include "../OrderItem.h"
#include "../Group.h"
#include "../GroupState.h"
#include "../Bun.h"
#include "../Patty.h"
#include "../BeefPatty.h"
#include "../ChickenPatty.h"
#include "../Side.h"
#include "../Salad.h"
#include "../Chips.h"
#include "../Drink.h"
#include "../Milkshake.h"
#include "../Soda.h"
#include "../Garnish.h"
#include "../Lettuce.h"
#include "../Tomato.h"
#include "../Chef.h"
#include "../HeadChef.h"
#include "../MeatChef.h"
#include "../DrinkChef.h"
#include "../SidesChef.h"
#include "../GarnishChef.h"
#include "../Pass.h"
#include "../Colleague.h"
#include "../Waiter.h"
#include "../WaitForTable.h"
#include "../Bill.h"
#include "../BillPayment.h"
#include "../Customer.h"
#include "../CustomerPays.h"
#include "../Happy.h"
#include "../MakeTab.h"
#include "../PayTab.h"
#include "../ReadyForBill.h"
#include "../ReadyToOrder.h"
#include "../SplitBill.h"
#include "../Tab.h"
#include "../Unhappy.h"
#include "../Neutral.h"
#include "../Order.h"

#include "gtest/gtest.h"

using namespace std;

// Create global variables for testing
Floor* floor;
MaitreD* maitreD;
std::vector<Waiter*> Waiters;
Pass* pass = new Pass();
int size;
Group* group;
Customer* c1; 
Customer* c2;
Bill* bill;

//Create functions to use and create stuff

void initGroup()
{
    group = new Group(new Neutral(), 1);
    c1 = new Customer("Bob");
    c2 = new Customer("Alice");
    group->addCustomer(c1);
    group->addCustomer(c2);
    bill = new Bill(200);
}

//Create TESTS
TEST(BillPayment, billPayment)
{
    initGroup();
    
    EXPECT_EQ(
        200,
        bill->getTotal());
    // setFloorSpaceAvailable();
    // EXPECT_EQ(
    //     "SPACEAVAILABLE",
    //     floor->getCurrentState()->getName());;
}

TEST(basicFUnctionalityMaitreD, MaitreD)
{
    // initMaitreD();
    // //tesing calculateTablesNeeded()
    // EXPECT_EQ(
    //     2,
    //     maitreD->calculateTablesNeeded(6));;

    // //testing checkAvailability()
    // EXPECT_EQ(
    //     true,
    //     maitreD->checkAvailability(6));

    // EXPECT_EQ(
    //     false,
    //     maitreD->checkAvailability(250));

    // //testing checkCurrentFloorState()

    // setFloorFull();
    // EXPECT_EQ(
    //     false,
    //     maitreD->checkCurrentFloorState(floor->getCurrentState()));

    // setFloorSpaceAvailable();
    // EXPECT_EQ(
    //     true,
    //     maitreD->checkCurrentFloorState(floor->getCurrentState()));

    //testing setWaiters

    // size = maitreD->getWaiterList().size();
    // EXPECT_EQ(
    //     0,
    //     size);

    // maitreD->setWaiterList(Waiters);
    // size = maitreD->getWaiterList().size();
    // EXPECT_EQ(
    //     3,
    //     size);

    // //testing addGroupToWaitingGroups
    // size = maitreD->getWaitingGroups().size();
    // EXPECT_EQ(
    //     0,
    //     size);

    // maitreD->addGroupToWaitingGroups(group);
    // size = maitreD->getWaitingGroups().size();
    // EXPECT_EQ(
    //     1,
    //     size);

    // //testing addGroupToFloor
    // size = floor->getGroups().size();
    // EXPECT_EQ(
    //     0,
    //     size);

    // maitreD->addGroupToFloor();
    // size = floor->getGroups().size();
    // EXPECT_EQ(
    //     1,
    //     size);

    // //testing removeFloor
    // size = floor->getGroups().size();
    // EXPECT_EQ(
    //     1,
    //     size);

    // maitreD->removeGroupFromFloor(group);
    // size = floor->getGroups().size();
    // EXPECT_EQ(
    //     0,
    //     size);
}