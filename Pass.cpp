#include "Pass.h"
#include "Order.h"
#include "Waiter.h"
#include "Chef.h"
#include "Plate.h"

Pass::Pass()
{

}

Pass::Pass(vector<Waiter*> waiters, Chef* headChef)
{
  // this is a shallow copy for now - can change it to a deep copy if deemed necessary
  this->listOfWaiters_ = waiters; 

  this->headChef_ = headChef;
}

void Pass::notifyHeadChef(Waiter* waiter)
{

}

void Pass::notifyWaiter(Chef* headchef)
{

}

void Pass::addRoListOfTrays(vector<Plate*> plates)
{

}

void Pass::addOrder(Order* order)
{

}

Pass::~Pass()
{

}