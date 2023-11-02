#include "Chef.h"
#include "Plate.h"
#include "Pass.h"
#include "Order.h"
#include "OrderComponent.h"
#include "OrderItem.h"

#include <iostream>
using namespace std;

Chef::Chef()
{
  cout << "Chef Created" << endl;
  //pass_ = new Pass(); // may have to pass in the pass
}

Chef::Chef(Pass* p)
{
  this->pass_ = p;
}

Chef::~Chef()
{
}

void Chef::add(Chef* nextChef)
{
    if(nextChef_)
    {
        nextChef_->add(nextChef);
    }
    else
    {
        nextChef_ = nextChef;
    }
}

void Chef::handleOrder(Plate* plate, vector<OrderComponent*> orderComp)
{
    if(nextChef_)
    {
        nextChef_->handleOrder(plate, orderComp);
    }
}

void Chef::createGroupOrder(Order* order)
{
    GroupIterator* iterator = order->createIterator();
    iterator->setOrder(order);

    while (!iterator->isDone()) {
        Order* currentComponent = iterator->currentItem();
        cout << "The kitchen is preparing an order for group " << currentComponent->getGroupNumber() << endl;
        if (currentComponent) {
            handleOrder(new Plate(), currentComponent->getItems());
        }
        cout<<endl;
        iterator->next();
    }
    
    if (iterator->isDone())
    {
        cout << "The kitchen is done preparing all orders for group " << order->getGroupNumber() << endl;
        pass_->addToListOfTrays(tray_); // add tray to list of trays
        tray_.clear();  // clear tray
        changed();
    }
}

void Chef::changed()
{
    pass_->notifyWaiter(this);
}