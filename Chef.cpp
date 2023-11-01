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

    cout << "Iterating through bobsBirthdayOrder components:" << endl;
    while (!iterator->isDone()) {
        Order* currentComponent = iterator->currentItem();
        if (currentComponent) {
            cout << "Order component price: " << currentComponent->getPrice() << endl;
            Chef::handleOrder(new Plate(), currentComponent->getItems());
        }
        iterator->next();
    }
    
    if (iterator->isDone())
    {
        pass_->addToListOfTrays(tray_); // add tray to list of trays
        tray_.clear();  // clear tray
        changed();
    }
    // iterate over all the customer orders in the group order
        // if orders left -> Chef::handleOrder(plate)

    // if no orders
        // pass_->addToListOfTrays(tray_); // add tray to list of trays
        // tray_.clear();  // clear tray
        // changed();
}

void Chef::changed()
{
    pass_->notifyWaiter(this);
}