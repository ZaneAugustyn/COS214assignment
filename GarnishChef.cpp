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
  ItemIterator* itemIterator = new ItemIterator(orderComp);
  int counter = 0;
  
  while (!itemIterator->isDone()) {
      OrderComponent* item = itemIterator->currentItem();
      if (dynamic_cast<OrderItem*>(item)) {

          OrderItem* orderItem = dynamic_cast<OrderItem*>(item);
          cout << "Item name/type: " << orderItem->getName() << ", Price: " << item->getPrice() << endl;

          if (orderItem->getName() != "Lettuce")
          {
            counter += 1;
          }
          else if (orderItem->getName() == "Lettuce")
          {
            //add a lettuce to the plate
            cout<<"Lettuce added to the plate"<<endl;
            break;
          }
          else if (orderItem->getName() != "Tomato")
          {
            counter += 1;
          }
          else if (orderItem->getName() == "Tomato")
          {
            //add a tomato to the plate
            cout<<"Tomato added to the plate"<<endl;
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