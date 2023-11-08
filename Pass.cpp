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

void Pass::NotifyHeadChef(Waiter* waiter)
{
  cout<<"NOTIFY: The headchef was notified of a new order"<<endl;
  DequeueOrder();
}

void Pass::NotifyWaiter(Chef* headchef)
{
  cout<<"NOTIFY: Waiter fetch the plate"<<endl;

  cout<<"The group has been served their meal." << endl;

}

void Pass::AddToListOfTrays(vector<Plate*> plates)
{
  this->listOfTrays_.push_back(plates);
}

void Pass::AddOrder(Order* order)
{
  // Notify the head chef that a order was added
  Group* groups = order->GetGroup();
  Waiter* waiter = groups->GetWaiter();

  this->orders_.push_back(order);

  waiter->Changed();

}

void Pass::DequeueOrder()
{
  Order* order =  this->orders_.front();
  Bill* groupBill = new Bill(order->GetPrice());
  order->GetGroup()->SetBill(groupBill);
  this->orders_.erase(this->orders_.begin());

  this->headChef_->CreateGroupOrder(order);
}

Pass::~Pass()
{
}

void Pass::AddChef(Chef* c)
{
  this->headChef_ = c;
}
