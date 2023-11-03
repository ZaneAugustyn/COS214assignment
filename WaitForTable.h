#ifndef WAITFORTABLE_H
#define WAITFORTABLE_H

#include "GroupState.h"
#include <iostream>

class WaitForTable : public GroupState
{
private:
    string stateName_;
public:
    WaitForTable();
    ~WaitForTable();
    virtual void RequestToOrder(Group * group);
    virtual void WaitInQueue(Group * group);
    virtual void MakeUnhappy(Group * group);
    virtual void MakeHappy(Group * group);
    virtual void RequestTab(Group * group);
    virtual void RequestBill(Group * group);
    virtual string ToString();
};


#endif