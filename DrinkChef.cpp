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

void DrinkChef::handleOrder(Plate* plate, vector<OrderComponent*> orderComp)
{
  ItemIterator* itemIterator = new ItemIterator(orderComp);
  int counter = 0;
  
  while (!itemIterator->isDone()) {
      OrderComponent* item = itemIterator->currentItem();
      if (dynamic_cast<OrderItem*>(item)) {

          OrderItem* orderItem = dynamic_cast<OrderItem*>(item);
          cout << "Item name/type: " << orderItem->getName() << ", Price: " << item->getPrice() << endl;

          if (orderItem->getName() != "Soda")
          {
            counter += 1;
          }
          else if (orderItem->getName() == "Soda")
          {
            //add a soda to the plate
            cout<<"Soda added to the plate"<<endl;
            break;
          }
          else if (orderItem->getName() != "Milkshake")
          {
            counter += 1;
          }
          else if (orderItem->getName() == "Milkshake")
          {
            //add a milkshake to the plate
            cout<<"Milkshake added to the plate"<<endl;
            break;
          }
      }
      itemIterator->next();
  }
  
  //remove bun from orderComp
  orderComp.erase(orderComp.begin() + counter);
  
  //send to the next chef
  Chef::handleOrder(plate,orderComp);

  // iterate over the order to find the drink
  // remove the drink from the order
  // add the drink to the plate
}
