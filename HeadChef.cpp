#include "HeadChef.h"
#include "Plate.h"
#include "OrderItem.h"

HeadChef::HeadChef(/* args */)
{

}

void HeadChef::handleOrder(Plate* plate, vector<OrderComponent*> orderComp)
{
  cout<<"HERRRREEEEE"<<endl;
  ItemIterator* itemIterator = new ItemIterator(orderComp);
  int counter = 0;

  if (orderComp.empty())
  {
    cout << "The Head Chef garnishes the plate and adds it to the tray" << endl;
    addToTray(plate);  
    return;
  }

  while (!itemIterator->isDone()) {
      OrderComponent* item = itemIterator->currentItem();
      if (dynamic_cast<OrderItem*>(item)) {

          OrderItem* orderItem = dynamic_cast<OrderItem*>(item);
          cout << "Item name/type: " << orderItem->getName() << ", Price: " << item->getPrice() << endl;
          cout << "The Head Chef adds the bun to the plate"<<endl;

          if (orderItem->getName() != "Bun")
          {
            counter += 1;
          }
      }
      itemIterator->next();
  }

  //add a bun to the plate
  cout<<"Bun added to the plate"<<endl;
  
  //remove bun from orderComp
  orderComp.erase(orderComp.begin() + counter);
  
  //send to the next chef
  Chef::handleOrder(plate,orderComp);

  // TO DO: chain of responsibility
  // if order is not empty
    // cout << "The Head Chef adds the bun to the plate"
    // Chef::heandleOrder(plate);
  // if order is empty 
    // cout << "The Head Chef garnishes the plate and adds it to the tray" << endl;
    // addToTray(plate);   
}

void HeadChef::addToTray(Plate* plate)
{
    tray_.push_back(plate);
}

HeadChef::~HeadChef()
{

}
