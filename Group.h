#ifndef _GROUP_H
#define _GROUP_H
// code here

#include <iostream>
#include <vector>
#include<string>

#include <GroupState.h>
#include <Customer.h>
#include <Bill.h>
#include <Waiter.h>


class Group
{
private:
    /* data */
    GroupState* groupState_;
    std::vector<Customer*> customers_;
    Bill* bill_;
    Waiter* waiter_;
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
    std::string CurrentState();
};

#endif
