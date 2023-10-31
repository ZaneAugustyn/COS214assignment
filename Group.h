#ifndef _GROUP_H
#define _GROUP_H

#include <vector>

#include "Waiter.h"

class Group
{
  private:
    Waiter* waiter_;
    int groupNumber_;

  public:
    Group(/* args */);
    void addWaiter(Waiter* waiter);
    Waiter* getWaiter();
    ~Group();
};

#endif
