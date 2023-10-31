#include "Pass.h"

Pass::Pass()
{

}

Pass::Pass(vector<Waiter*> waiters, HeadChef* headChef)
{
  // this is a shallow copy for now - can change it to a deep copy if deemed necessary
  this->listOfWaiters_ = waiters; 

  this->headChef_ = headChef;
}

void Pass::notifyHeadChef(HeadChef* headchef)
{

}

void Pass::notifyWaiter(Waiter* waiter)
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