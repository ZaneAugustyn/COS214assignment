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

void Chef::HandleOrder(Plate* plate)
{
    // iterate over order using the plate object -> if order is not empty -> nextChef_->HandleOrder(plate)
}