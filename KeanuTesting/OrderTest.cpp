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

//functions for testing
void createMockOrder(){

    globalOrder = new Order(NULL);

    //add orders for two customers
    Order* customerOrderA = new Order(NULL);
    customerOrderA->addComponent(new Bun()); //cost = 0
    customerOrderA->addComponent(new ChickenPatty(true)); //cost = 30
    customerOrderA->addComponent(new Lettuce()); //cost = 5
    customerOrderA->addComponent(new Salad()); //cost = 25
    customerOrderA->addComponent(new Milkshake()); //cost = 40

    Order* customerOrderB = new Order(NULL);
    customerOrderB->addComponent(new Bun()); //cost = 0
    customerOrderB->addComponent(new BeefPatty()); //cost = 40
    customerOrderB->addComponent(new Tomato()); //cost = 10
    customerOrderB->addComponent(new Chips()); //cost = 20
    customerOrderB->addComponent(new Soda()); //cost = 30

    globalOrder->addComponent(customerOrderA);
    globalOrder->addComponent(customerOrderB);

    //total cost of globalOrder should be 200

}

TEST(TestOrderPrice, getPrice){
    createMockOrder();
    float price = 200;
    EXPECT_EQ(
        price,
        globalOrder->getPrice());
}