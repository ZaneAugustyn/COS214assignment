#ifndef UNHAPPY_H
#define UNHAPPY_H

#include "GroupState.h"
#include <iostream>

class Unhappy : public GroupState
{
private:
    string stateName_;
public:
    Unhappy();
    ~Unhappy();
    virtual void RequestToOrder(Group * group);
    virtual void WaitInQueue(Group * group);
    virtual void MakeUnhappy(Group * group);
    virtual void MakeHappy(Group * group);
    virtual void RequestTab(Group * group);
    virtual void RequestBill(Group * group);
    virtual string ToString();
};



#endif