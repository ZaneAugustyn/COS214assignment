#include "MeatChef.h"
#include "Plate.h"
#include "OrderItem.h"

#include <iostream>
using namespace std;

MeatChef::MeatChef(/* args */)
{
}

MeatChef::~MeatChef()
{
}

void MeatChef::handleOrder(Plate* plate, vector<OrderComponent*> orderComp)
{
  ItemIterator* itemIterator = new ItemIterator(orderComp);
  int counter = 0;
  
  while (!itemIterator->isDone()) {
      OrderComponent* item = itemIterator->currentItem();
      if (dynamic_cast<OrderItem*>(item)) {

          OrderItem* orderItem = dynamic_cast<OrderItem*>(item);
          cout << "Item name/type: " << orderItem->getName() << ", Price: " << item->getPrice() << endl;
          cout << "The Meat Chef has added the meat to the plate" << endl;

          if (orderItem->getName() != "Chicken Patty")
          {
            counter += 1;
          }
          else if (orderItem->getName() == "Chicken Patty")
          {
            //add a chicken patty to the plate
            Patty* chic = dynamic_cast<ChickenPatty*>(orderItem);
            if (chic->getGrilledStatus() == true)
            {
              cout<<"Grilled chicken patty added to the plate"<<endl;
              break;
            }
            else
            {
              cout<<"Fried patty added to the plate"<<endl;
              break;
            }
          }
          else if (orderItem->getName() != "Beef Patty")
          {
            counter += 1;
          }
          else if (orderItem->getName() == "Beef Patty")
          {
            //add a beef patty to the plate
            cout<<"Beef patty added to the plate"<<endl;
            break;
          }
      }
      itemIterator->next();
  }
  
  //remove bun from orderComp
  orderComp.erase(orderComp.begin() + counter);
  
  //send to the next chef
  Chef::handleOrder(plate,orderComp);

    // iterate over the order to find the meet
        // check preparation method
    // remove the meat from the order
    // add the meat to the plate
}

