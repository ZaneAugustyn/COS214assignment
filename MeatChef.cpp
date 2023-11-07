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

void MeatChef::HandleOrder(Plate *plate, vector<OrderComponent *> orderComp)
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

      if (orderItem->GetName() != "Chicken Patty" && orderItem->GetName() != "Beef Patty")
      {
        counter += 1;
      }
      else if (orderItem->GetName() == "Chicken Patty")
      {
        // add a chicken patty to the plate
        Patty *chic = dynamic_cast<ChickenPatty *>(orderItem);
        if (chic->GetGrilledStatus() == true)
        {
          cout << "The Meat Chef adds a grilled chicken patty to the plate" << endl;
          plate->AddToPlate(chic);
          plate->PrintPlate();

          // remove bun from orderComp
          orderComp.erase(orderComp.begin() + counter);

          break;
        }
        else
        {
          cout << "The Meat Chef adds a fried chicken patty to the plate" << endl;
          plate->AddToPlate(chic);
          plate->PrintPlate();

          // remove bun from orderComp
          orderComp.erase(orderComp.begin() + counter);

          break;
        }
      }
      else if (orderItem->GetName() == "Beef Patty")
      {
        cout << "The Meat Chef a grilled beef patty to the plate" << endl;
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
