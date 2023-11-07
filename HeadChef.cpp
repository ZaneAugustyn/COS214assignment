#include "HeadChef.h"
#include "Plate.h"
#include "OrderItem.h"
#include "Pass.h"

HeadChef::HeadChef(/* args */)
{
}

HeadChef::HeadChef(Pass* pass)
{
  this->pass_ = pass;
}

void HeadChef::HandleOrder(Plate *plate, vector<OrderComponent *> orderComp)
{
  ItemIterator *itemIterator = new ItemIterator(orderComp);
  int counter = 0;

  if (orderComp.empty())
  {
    cout << "The Head Chef garnishes the plate and adds it to the tray" << endl;
    AddToTray(plate);
    return;
  }

  while (!itemIterator->IsDone())
  {
    OrderComponent *item = itemIterator->CurrentItem();
    if (dynamic_cast<OrderItem *>(item))
    {
      OrderItem *orderItem = dynamic_cast<OrderItem *>(item);

      if (orderItem->GetName() != "Bun")
      {
        counter += 1;
      }
      else
      {
        cout << "The Head Chef adds the bun to the plate" << endl;
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

void HeadChef::AddToTray(Plate *plate)
{
  tray_.push_back(plate);
}

HeadChef::~HeadChef()
{
}
