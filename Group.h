#ifndef _GROUP_H
#define _GROUP_H

#include <vector>
#include <GroupState.h>
#include <Customer.h>
#include <Bill.h>
#include <Waiter.h>

class Group
{
  private:
    GroupState* groupState_;
    vector<Customer*> customers_;
    Bill* bill_;
    Waiter* waiter_;
    int groupNumber_;

  public:
    Group(/* args */);
    void addWaiter(Waiter* waiter);
    Waiter* getWaiter();
    ~Group();
};

#endif
