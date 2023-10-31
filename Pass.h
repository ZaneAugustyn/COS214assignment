#ifndef _PASS_H
#define _PASS_H

#include <vector>
#include <Order.h>
#include <HeadChef.h>
#include <Waiter.h>
#include <Plate.h>

// code here
class Pass
{
  private:
    vector<Order*> orders_;
    vector<vector<Plate*>> listOfTrays;

  protected:
    vector<Waiter*> listOfWaiters_;
    HeadChef* headChef_;

  public:
    Pass();
    Pass(vector<Waiter*> waiters, HeadChef* headChef);
    void notifyHeadChef(HeadChef* headchef);
    void notifyWaiter(Waiter* waiter);
    void addRoListOfTrays(vector<Plate*> plates);
    void addOrder(Order* order);
    virtual ~Pass();
};

#endif
