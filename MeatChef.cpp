#include "MeatChef.h"
#include "Plate.h"
#include "OrderItem.h"

#include <iostream>
using namespace std;

MeatChef::MeatChef()
{
}

MeatChef::~MeatChef()
{
}

void MeatChef::handleOrder(Plate *plate, vector<OrderComponent *> orderComp)
{
  ItemIterator *itemIterator = new ItemIterator(orderComp);
  int counter = 0;

  while (!itemIterator->isDone())
  {
    OrderComponent *item = itemIterator->currentItem();
    if (dynamic_cast<OrderItem *>(item))
    {

      OrderItem *orderItem = dynamic_cast<OrderItem *>(item);

      if (orderItem->getName() != "Chicken Patty" && orderItem->getName() != "Beef Patty")
      {
        counter += 1;
      }
      else if (orderItem->getName() == "Chicken Patty")
      {
        // add a chicken patty to the plate
        Patty *chic = dynamic_cast<ChickenPatty *>(orderItem);
        if (chic->getGrilledStatus() == true)
        {
          cout << "The Meat Chef adds a grilled chicken patty to the plate" << endl;
          plate->addToPlate(chic);
          plate->printPlate();
          break;
        }
        else
        {
          cout << "The Meat Chef adds a fried chicken patty to the plate" << endl;
          plate->addToPlate(chic);
          plate->printPlate();
          break;
        }
      }
      else if (orderItem->getName() == "Beef Patty")
      {
        cout << "The Meat Chef a grilled beef patty to the plate" << endl;
        plate->addToPlate(orderItem);
        plate->printPlate();
        break;
      }
    }
    itemIterator->next();
  }

  // remove bun from orderComp
  orderComp.erase(orderComp.begin() + counter);

  // send to the next chef
  Chef::handleOrder(plate, orderComp);
}
