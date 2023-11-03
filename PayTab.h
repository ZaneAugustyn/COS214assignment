#ifndef PAYTAB_H
#define PAYTAB_H

#include "GroupState.h"
#include <iostream>

class PayTab : public GroupState
{
private:
    string stateName_;
public:
    PayTab();
    ~PayTab();
    virtual void RequestToOrder(Group * group);
    virtual void WaitInQueue(Group * group);
    virtual void MakeUnhappy(Group * group);
    virtual void MakeHappy(Group * group);
    virtual void RequestTab(Group * group);
    virtual void RequestBill(Group * group);
    virtual string ToString();
};

#endif