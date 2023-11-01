#ifndef GROUP_H
#define GROUP_H

#include "Waiter.h"
#include <iostream>

using namespace std;

class GroupState;

class Group
{
private:
    GroupState * groupState_;
    Waiter * waiter_;
    int groupNumber_;
public:
    Group(GroupState * state, int groupNumber);
    ~Group();
    void SetWaiter(Waiter * waiter);
    void SetState(GroupState * state);
    void RequestToOrder();
    void WaitInQueue();
    void MakeUnhappy();
    void MakeHappy();
    void RequestTab();
    void RequestBill();
    int GetGroupNumber();
    GroupState * GetState();
    string CurrentState();
};

#endif