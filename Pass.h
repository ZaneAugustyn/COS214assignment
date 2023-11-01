#ifndef _PASS_H
#define _PASS_H

#include <vector>
#include <iostream>
using namespace std;

class Order;
class Waiter;
class Chef;
class Plate;

class Pass
{
  private:
    vector<Order*> orders_;
    vector<vector<Plate*>> listOfTrays_;

  protected:
    vector<Waiter*> listOfWaiters_;
    Chef* headChef_;

  public:
    Pass();
    Pass(vector<Waiter*> waiters, Chef* headChef);
    void notifyHeadChef(Waiter* waiter);
    void notifyWaiter(Chef* headchef);
    void addToListOfTrays(vector<Plate*> plates);
    void addOrder(Order* order);
    void dequeueOrder();
    virtual ~Pass();
};

#endif
