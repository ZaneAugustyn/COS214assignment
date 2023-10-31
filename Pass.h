#ifndef _PASS_H
#define _PASS_H

#include <vector>
#include "Order.h"
#include "Chef.h"
#include "Waiter.h"
#include "Plate.h"

// code here
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
