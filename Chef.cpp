#include "Chef.h"

Chef::Chef(/* args */)
{
}

Chef::~Chef()
{
}

void Chef::setNextChef(Chef* nextChef)
{
    if(nextChef_)
    {
        nextChef_->setNextChef(nextChef);
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
        // if orders left -> Chef::handleOrder(plate, false)
        // else -> Chef::handleOrder(plate, true)
}