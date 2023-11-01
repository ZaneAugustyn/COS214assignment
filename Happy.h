#ifndef HAPPY_H
#define HAPPY_H

#include "GroupState.h"
#include <iostream>

class Happy : public GroupState
{
private:
    string stateName_;
public:
    Happy();
    ~Happy();
    virtual void RequestToOrder(Group * group);
    virtual void WaitInQueue(Group * group);
    virtual void MakeUnhappy(Group * group);
    virtual void MakeHappy(Group * group);
    virtual void RequestTab(Group * group);
    virtual void RequestBill(Group * group);
    virtual string ToString();
};



#endif