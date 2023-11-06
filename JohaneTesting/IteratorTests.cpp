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

Order *global_Menu;
Pass *global_Pass;
Group *global_Group;
Order *global_Order;
Order *global_CustomerOrder1;
Order *global_CustomerOrder2;
string global_errorMessage;

using namespace std;
void createMockPass()
{
    global_Pass = new Pass();
}

void createMockGroup()
{
    global_Group = new Group(new Neutral(), 1);
    global_Group->addCustomer(new Customer("John"));
    global_Group->addCustomer(new Customer("Jane"));
}
void createMockMenu()
{
    global_Menu = new Order(NULL);
    // maeats
    Order *meats = new Order(NULL);
    meats->addComponent(new ChickenPatty(true));
    meats->addComponent(new BeefPatty());

    // sides
    Order *sides = new Order(NULL);
    sides->addComponent(new Chips());
    sides->addComponent(new Salad());

    // garnish
    Order *garnish = new Order(NULL);
    garnish->addComponent(new Lettuce());
    garnish->addComponent(new Tomato());

    // drinks
    Order *drinks = new Order(NULL);
    drinks->addComponent(new Milkshake());
    drinks->addComponent(new Soda());

    global_Menu->addComponent(meats);
    global_Menu->addComponent(sides);
    global_Menu->addComponent(garnish);
    global_Menu->addComponent(drinks);
}

void createOrders()
{
    global_CustomerOrder1->addComponent(new Lettuce());
    global_CustomerOrder1->addComponent(new BeefPatty());

    global_CustomerOrder2->addComponent(new Salad());
    global_CustomerOrder2->addComponent(new ChickenPatty(true));

    global_Order->addComponent(global_CustomerOrder1);
    global_Order->addComponent(global_CustomerOrder2);
}

TEST(IteratorTest, GroupIteratorTest) {
    //createMockPass();
    createMockGroup();
    createMockMenu();  
    //createOrders();

    GroupIterator* iterator=global_Menu->createIterator();

    // //Test hasNext() and next()
     EXPECT_EQ(
        false,
        iterator->isDone());
    EXPECT_TRUE(iterator->next());
    EXPECT_TRUE(iterator->next());
}

TEST(IteratorTest, ItemIteratorTest) {

    ItemIterator* iterator=global_Menu->createItemIterator();
    EXPECT_EQ(
        true,
        iterator->isDone());
    EXPECT_FALSE(iterator->next());
}
