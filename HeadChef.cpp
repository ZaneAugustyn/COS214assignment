#include "HeadChef.h"
#include "Plate.h"
#include "OrderItem.h"

HeadChef::HeadChef(/* args */)
{
}

void HeadChef::handleOrder(Plate *plate, vector<OrderComponent *> orderComp)
{
  ItemIterator *itemIterator = new ItemIterator(orderComp);
  int counter = 0;

  if (orderComp.empty())
  {
    cout << "The Head Chef garnishes the plate and adds it to the tray" << endl;
    addToTray(plate);
    return;
  }

  while (!itemIterator->isDone())
  {
    OrderComponent *item = itemIterator->currentItem();
    if (dynamic_cast<OrderItem *>(item))
    {
      OrderItem *orderItem = dynamic_cast<OrderItem *>(item);

      if (orderItem->getName() != "Bun")
      {
        counter += 1;
      }
      else
      {
        cout << "The Head Chef adds the bun to the plate" << endl;
        break;
      }
    }
    itemIterator->next();
  }

  // remove bun from orderComp
  orderComp.erase(orderComp.begin() + counter);

  // send to the next chef
  Chef::handleOrder(plate, orderComp);

  // TO DO: chain of responsibility
  // if order is not empty
  // cout << "The Head Chef adds the bun to the plate"
  // Chef::heandleOrder(plate);
  // if order is empty
  // cout << "The Head Chef garnishes the plate and adds it to the tray" << endl;
  // addToTray(plate);
}

void HeadChef::addToTray(Plate *plate)
{
  tray_.push_back(plate);
}

HeadChef::~HeadChef()
{
}
