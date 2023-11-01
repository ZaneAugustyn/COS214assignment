#include <iostream>
#include <string>
#include "Chef.h"
#include "HeadChef.h"
#include "MeatChef.h"
#include "DrinkChef.h"
#include "SidesChef.h"
#include "GarnishChef.h"
#include "OrderComponent.h"
#include "Order.h"
#include "OrderItem.h"
#include "Group.h"
#include "Bun.h"
#include "ChickenPatty.h"
#include "BeefPatty.h"
#include "Chips.h"
#include "Salad.h"
#include "Soda.h"
#include "Milkshake.h"
#include "Tomato.h"
#include "Lettuce.h"
#include "ItemIterator.h"
#include "GroupIterator.h"
#include "Plate.h"
#include "Waiter.h"
#include "Pass.h"
#include "Colleague.h"


using namespace std;

int main()
{

    // build chain
    Chef* headChef = new HeadChef();

    headChef->add(new MeatChef());
    headChef->add(new DrinkChef());
    headChef->add(new SidesChef());
    headChef->add(new GarnishChef());
    headChef->add(headChef);

    //headChef->createGroupOrder();

    //delete headChef;

    //Create a group for Bob's Birthday
    Group* bobsBirthday = new Group();

    //Create an order for the group
    Order* bobsBirthdayOrder = new Order(bobsBirthday);

    //First get Bob's order
    Order* bobsOrder = new Order(bobsBirthday);
    bobsOrder->addComponent(new Bun()); //cost = 10
    bobsOrder->addComponent(new ChickenPatty(false)); //cost = 30
    bobsOrder->addComponent(new Chips()); //cost = 20
    bobsOrder->addComponent(new Tomato()); //cost = 10
    bobsOrder->addComponent(new Lettuce()); //cost = 5
    bobsOrder->addComponent(new Milkshake()); //cost = 40

    //Then get Alice's order
    Order* alicesOrder = new Order(bobsBirthday);
    alicesOrder->addComponent(new Bun()); //cost = 10
    alicesOrder->addComponent(new BeefPatty()); //cost = 40
    alicesOrder->addComponent(new Salad()); //cost = 25
    alicesOrder->addComponent(new Soda()); //cost = 30

    //Add both orders to the group's order
    bobsBirthdayOrder->addComponent(bobsOrder);
    bobsBirthdayOrder->addComponent(alicesOrder);

    headChef->createGroupOrder(bobsBirthdayOrder);

//     GroupIterator* iterator = bobsBirthdayOrder->createIterator();

//     cout << "Iterating through bobsBirthdayOrder components:" << endl;
//     while (!iterator->isDone()) {
//         Order* currentComponent = iterator->currentItem();
//         if (currentComponent) {
//             cout << "Order component price: " << currentComponent->getPrice() << endl;

//             // Get the items within the current component
//             vector<OrderComponent*> items = currentComponent->getItems();

//             //ItemIterator to iterate through the items
//             ItemIterator* itemIterator = new ItemIterator(items);
//             while (!itemIterator->isDone()) {
//                 OrderComponent* item = itemIterator->currentItem();
//                 if (dynamic_cast<OrderItem*>(item)) {
//                     OrderItem* orderItem = dynamic_cast<OrderItem*>(item);
//                     cout << "Item name/type: " << orderItem->getName() << ", Price: " << item->getPrice() << endl;
//                 }
//                 itemIterator->next();
//             }
//             delete itemIterator;
//         }
//     iterator->next();
// }
    //Print out the total cost of the order, should be 220
    cout << bobsBirthdayOrder->getPrice() << endl;

    //Remove alicesOrder
    bobsBirthdayOrder->removeComponent(alicesOrder);

    //Print out the total cost of the order, should be 115
    cout << bobsBirthdayOrder->getPrice() << endl;

    delete bobsBirthdayOrder;
    delete alicesOrder;
    delete bobsBirthday;
  
    cout<<"Hello world - this is my first commit!"<<endl;

  cout<<"Create waiters"<<endl;
  Waiter* waiterOne = new Waiter();
  Waiter* waiterTwo = new Waiter();
  Waiter* waiterThree = new Waiter();

  cout<<"Create waiter list"<<endl;
  vector<Waiter*> waiterList;
  waiterList.push_back(waiterOne);
  waiterList.push_back(waiterTwo);
  waiterList.push_back(waiterThree);

  cout<<"Create a group and assign waiter to a group"<<endl;
  Group* groupOne = new Group();
  groupOne->addWaiter(waiterOne);

  cout<<"Create the chef"<<endl;
  Chef* chef = new Chef();

  cout<<"Create the pass"<<endl;
  Pass* passMediator = new Pass(waiterList, chef);

  // create a order...

  // waiter add the order to the pass and call change...

    

    return 0;
}