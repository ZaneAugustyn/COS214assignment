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

void DrinkChef::HandleOrder(Plate *plate, vector<OrderComponent *> orderComp)
{
  if (orderComp.empty())
  {
    Chef::HandleOrder(plate,orderComp);
    return;
  }

  ItemIterator *itemIterator = new ItemIterator(orderComp);
  int counter = 0;

  while (!itemIterator->IsDone())
  {
    OrderComponent *item = itemIterator->CurrentItem();
    if (dynamic_cast<OrderItem *>(item))
    {

      OrderItem *orderItem = dynamic_cast<OrderItem *>(item);

      if (orderItem->GetName() != "Soda" && orderItem->GetName() != "Milkshake")
      {
        counter += 1;
      }
      else 
      {
        cout << "The Drink Chef adds the " << orderItem->GetName() << " to the plate" << endl;
        plate->AddToPlate(orderItem);
        plate->PrintPlate();

        // remove bun from orderComp
        orderComp.erase(orderComp.begin() + counter);

        break;
      }
    }
    itemIterator->Next();
  }

  // send to the next chef
  Chef::HandleOrder(plate, orderComp);
}
