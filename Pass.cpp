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
  cout<<"NOTIFY: The headchef was notified of a new order"<<endl;

  // add order to the order queue
}

void Pass::notifyWaiter(Chef* headchef)
{
  cout<<"NOTIFY: Waiter fetch the plate"<<endl;
}

void Pass::addToListOfTrays(vector<Plate*> plates)
{
  this->listOfTrays_.push_back(plates);
}

void Pass::addOrder(Order* order)
{
  this->orders_.push_back(order);
}

void Pass::dequeueOrder()
{
  Order* order =  this->orders_.front();
  this->orders_.erase(this->orders_.begin());
  this->headChef_->createGroupOrder(order);
}

Pass::~Pass()
{

}
