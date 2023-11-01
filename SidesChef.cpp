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

void SidesChef::handleOrder(Plate* plate, vector<OrderComponent*> orderComp)
{
  ItemIterator* itemIterator = new ItemIterator(orderComp);
  int counter = 0;
  
  while (!itemIterator->isDone()) {
      OrderComponent* item = itemIterator->currentItem();
      if (dynamic_cast<OrderItem*>(item)) {

          OrderItem* orderItem = dynamic_cast<OrderItem*>(item);
          cout << "Item name/type: " << orderItem->getName() << ", Price: " << item->getPrice() << endl;

          if (orderItem->getName() != "Chips")
          {
            counter += 1;
          }
          else if (orderItem->getName() == "Chips")
          {
            //add a chips to the plate
            cout<<"Chips added to the plate"<<endl;
            break;
          }
          else if (orderItem->getName() != "Salad")
          {
            counter += 1;
          }
          else if (orderItem->getName() == "Salad")
          {
            //add a salad to the plate
            cout<<"Salad added to the plate"<<endl;
            break;
          }
      }
      itemIterator->next();
  }
  
  //remove bun from orderComp
  orderComp.erase(orderComp.begin() + counter);
  
  //send to the next chef
  Chef::handleOrder(plate,orderComp);

  // iterate over the order to find the side
  // remove the side from the order
  // add the side to the plate
}
