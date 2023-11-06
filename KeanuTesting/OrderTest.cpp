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

//global variables for testing
Order* globalOrder;
Order* globalCustomerOrderA;
Order* globalCustomerOrderB;

//functions for testing
void createMockOrder(){

    globalOrder = new Order(NULL);

    //add orders for two customers
    globalCustomerOrderA = new Order(NULL);
    globalCustomerOrderA->addComponent(new Bun()); //cost = 0
    globalCustomerOrderA->addComponent(new ChickenPatty(true)); //cost = 30
    globalCustomerOrderA->addComponent(new Tomato()); //cost = 10
    globalCustomerOrderA->addComponent(new Salad()); //cost = 25
    globalCustomerOrderA->addComponent(new Milkshake()); //cost = 40
    //total cost of OrderA is 105

    globalCustomerOrderB = new Order(NULL);
    globalCustomerOrderB->addComponent(new Bun()); //cost = 0
    globalCustomerOrderB->addComponent(new BeefPatty()); //cost = 40
    globalCustomerOrderB->addComponent(new Lettuce()); //cost = 5
    globalCustomerOrderB->addComponent(new Chips()); //cost = 20
    globalCustomerOrderB->addComponent(new Soda()); //cost = 30
    //total cost of OrderB is 95

    globalOrder->addComponent(globalCustomerOrderA);
    globalOrder->addComponent(globalCustomerOrderB);

    //total cost of globalOrder should be 200

}

TEST(TestOrderPrice, getPrice){
    createMockOrder();
    float price = 200;
    EXPECT_EQ(
        price,
        globalOrder->getPrice());
}

TEST(TestOrderRemoveComponentAndPrice, removeComponent){
    createMockOrder();
    float price = 105;
    globalOrder->removeComponent(globalCustomerOrderB);
    EXPECT_EQ(
        price,
        globalOrder->getPrice());
}