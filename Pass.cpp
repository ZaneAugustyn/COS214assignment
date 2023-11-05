#include "Pass.h"
#include "Order.h"
#include "Waiter.h"
#include "Chef.h"
#include "Plate.h"
#include "Group.h"

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
  dequeueOrder();
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
  // Notify the head chef that a order was added
  Group* groups = order->getGroup();
  Waiter* waiter = groups->getWaiter();

  this->orders_.push_back(order);

  waiter->changed();

}

void Pass::dequeueOrder()
{
  Order* order =  this->orders_.front();
  Bill* groupBill = new Bill(order->getPrice());
  order->getGroup()->setBill(groupBill);
  this->orders_.erase(this->orders_.begin());

  this->headChef_->createGroupOrder(order);
}

Pass::~Pass()
{
}

void Pass::addChef(Chef* c)
{
  this->headChef_ = c;
}
