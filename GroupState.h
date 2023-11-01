#ifndef GROUPSTATE_H
#define GROUPSTATE_H

#include "Group.h"

class GroupState
{
private:
    
public:
    GroupState();
    virtual ~GroupState();
    virtual void RequestToOrder(Group * group) = 0;
    virtual void WaitInQueue(Group * group) = 0;
    virtual void MakeUnhappy(Group * group) = 0;
    virtual void MakeHappy(Group * group) = 0;
    virtual void RequestTab(Group * group) = 0;
    virtual void RequestBill(Group * group) = 0;
    virtual string ToString() = 0;
};


#endif