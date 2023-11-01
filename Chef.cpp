#include "Chef.h"
#include "Plate.h"
#include "Pass.h"

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

void Chef::handleOrder(Plate* plate)
{
    if(nextChef_)
    {
        nextChef_->handleOrder(plate);
    }
}

void Chef::createGroupOrder()
{
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