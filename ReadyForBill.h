#ifndef READYFORBILL_H
#define READYFORBILL_H

#include "GroupState.h"
#include <iostream>

class ReadyForBill : public GroupState
{
private:
    string stateName_;
public:
    ReadyForBill();
    ~ReadyForBill();
    virtual void RequestToOrder(Group * group);
    virtual void WaitInQueue(Group * group);
    virtual void MakeUnhappy(Group * group);
    virtual void MakeHappy(Group * group);
    virtual void RequestTab(Group * group);
    virtual void RequestBill(Group * group);
    virtual string ToString();
};

#endif