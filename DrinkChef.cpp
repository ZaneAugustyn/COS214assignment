#include "DrinkChef.h"

#include "Plate.h"
#include "OrderItem.h"

#include <iostream>
using namespace std;

DrinkChef::DrinkChef(/* args */)
{
}

DrinkChef::~DrinkChef()
{
}

void DrinkChef::handleOrder(Plate *plate, vector<OrderComponent *> orderComp)
{
  if (orderComp.empty())
  {
    Chef::handleOrder(plate,orderComp);
    return;
  }

  ItemIterator *itemIterator = new ItemIterator(orderComp);
  int counter = 0;

  while (!itemIterator->isDone())
  {
    OrderComponent *item = itemIterator->currentItem();
    if (dynamic_cast<OrderItem *>(item))
    {

      OrderItem *orderItem = dynamic_cast<OrderItem *>(item);

      if (orderItem->getName() != "Soda" && orderItem->getName() != "Milkshake")
      {
        counter += 1;
      }
      else 
      {
        cout << "The Drink Chef adds the " << orderItem->getName() << " to the plate" << endl;
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

  // iterate over the order to find the drink
  // remove the drink from the order
  // add the drink to the plate
}
