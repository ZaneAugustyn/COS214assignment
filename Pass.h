#ifndef _PASS_H
#define _PASS_H

#include <vector>
using namespace std;

class Order;
class Waiter;
class Chef;
class Plate;

class Pass
{
  private:
    vector<Order*> orders_;
    vector<vector<Plate*>> listOfTrays;

  protected:
    vector<Waiter*> listOfWaiters_;
    Chef* headChef_;

  public:
    Pass();
    Pass(vector<Waiter*> waiters, Chef* headChef);
    void notifyHeadChef(Waiter* waiter);
    void notifyWaiter(Chef* headchef);
    void addRoListOfTrays(vector<Plate*> plates);
    void addOrder(Order* order);
    virtual ~Pass();
};

#endif
