#ifndef _GROUP_H
#define _GROUP_H
// code here

#include <iostream>
#include <vector>
#include<string>

#include "GroupState.h"
#include "Customer.h"
#include "Bill.h"

class GroupState;

class Waiter;

class Group
{
private:
    /* data */
    GroupState* groupState_;
    std::vector<Customer*> customers_;
    Bill* bill_;
    Waiter* waiter_;
    int groupNumber_;
    GroupState* lastEmotion;

public:
    /**
     * @brief parameterized constructor for Group to initialise a group
     * @param state the initial state of the group
     * @param groupNumber the number of the group 
    */
    Group(GroupState * state, int groupNumber);

    /**
     * @brief destructor
    */
    ~Group();

    /**
     * @brief set the waiter of a group
     * @param waiter the waiter to be assigned to a group
     * @return void
    */

    void addCustomer(Customer* customer){

        customers_.push_back(customer);

    }

    void SetWaiter(Waiter * waiter);

    /**
     * @brief set the state of the group
     * @param state the state to be assigned to a group
     * @return void
    */
    void SetState(GroupState * state);

    /**
     * @brief the Context class of the State pattern that defines the requests for the state changes
     * @return void
    */
    void RequestToOrder();

    /**
     * @brief the Context class of the State pattern that defines the requests for the state changes
     * @return void
    */
    void WaitInQueue();

    /**
     * @brief the Context class of the State pattern that defines the requests for the state changes
     * @return void
    */
    void MakeUnhappy();

    /**
     * @brief the Context class of the State pattern that defines the requests for the state changes
     * @return void
    */
    void MakeHappy();

    /**
     * @brief the Context class of the State pattern that defines the requests for the state changes
     * @return void
    */
    void RequestTab();

    /**
     * @brief the Context class of the State pattern that defines the requests for the state changes
     * @return void
    */
    void RequestBill();

    /**
     * @brief the function to return the groupNumber
     * @return int
    */
    int GetGroupNumber();

    /**
     * @brief the function to return the the state of the group
     * @return GroupState*
    */
    GroupState * GetState();

    /**
     * @brief function to create a string to show the current state of the group
     * @return string
    */
    std::string CurrentState();

    void addWaiter(Waiter* waiter);
    void removeWaiter(Waiter* waiter);

    void setBill(Bill* bill);
    
    void notify();
};

#endif
