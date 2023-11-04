#include "GarnishChef.h"

#include "Plate.h"
#include "OrderItem.h"

#include <iostream>
using namespace std;

GarnishChef::GarnishChef(/* args */)
{
}

GarnishChef::~GarnishChef()
{
}

void GarnishChef::handleOrder(Plate* plate, vector<OrderComponent*> orderComp)
{
  if (orderComp.empty())
  {
    Chef::handleOrder(plate,orderComp);
    return;
  }

  ItemIterator* itemIterator = new ItemIterator(orderComp);
  int counter = 0;
  
  while (!itemIterator->isDone()) {
      OrderComponent* item = itemIterator->currentItem();
      if (dynamic_cast<OrderItem*>(item)) {

          OrderItem* orderItem = dynamic_cast<OrderItem*>(item);

          if (orderItem->getName() != "Lettuce" && orderItem->getName() != "Tomato")
          {
            counter += 1;
          }
          else 
          {
            cout << "The Garnish Chef adds the " << orderItem->getName() << " to the plate" << endl;
            plate->addToPlate(orderItem);
            plate->printPlate();
            break;
          }
      }
      itemIterator->next();
  }
  
  //remove bun from orderComp
  orderComp.erase(orderComp.begin() + counter);
  
  //send to the next chef
  Chef::handleOrder(plate,orderComp);

  // iterate over the order to find the garnish
  // remove the garnish from the order
  // add the garnish to the plate
}