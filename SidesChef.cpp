#include "SidesChef.h"

#include "Plate.h"
#include "OrderItem.h"

#include <iostream>
using namespace std;

SidesChef::SidesChef()
{
}

SidesChef::~SidesChef()
{
}

void SidesChef::handleOrder(Plate *plate, vector<OrderComponent *> orderComp)
{
  ItemIterator *itemIterator = new ItemIterator(orderComp);
  int counter = 0;

  while (!itemIterator->isDone())
  {
    OrderComponent *item = itemIterator->currentItem();
    if (dynamic_cast<OrderItem *>(item))
    {

      OrderItem *orderItem = dynamic_cast<OrderItem *>(item);

      if (orderItem->getName() != "Chips" && orderItem->getName() != "Salad")
      {
        counter += 1;
      }
      else
      {
        cout << "The Sides Chef adds the " << orderItem->getName() << " to the plate" << endl;
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
