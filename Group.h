#ifndef _GROUP_H
#define _GROUP_H
// code here

#include <iostream>
#include <vector>
#include<string>

#include "GroupState.h"
#include "Customer.h"

using namespace std;

class GroupState;

class Waiter;
class Bill;

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
     * @brief Add a customer to the group.
     * @param customer The customer to be added.
     * @return void
     */
    void addCustomer(Customer* customer){

        customers_.push_back(customer);

    }

    /**
     * @brief Get the customers in the group.
     * @return A vector of Customer pointers.
     */
    std::vector<Customer*> getCustomers()
    {
        return customers_;
    }
    
    /**
     * @brief Get the waiter serving the group.
     * @return The waiter serving the group.
     */
    Waiter* getWaiter();

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
    int getGroupNumber();

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

    /**
     * @brief function to return the first customer in the group
     * @return Customer*
    */
    Customer* getFirstCustomer();

    /**
     * @brief Add a waiter to serve the group.
     * @param waiter The waiter to be assigned to the group.
     * @return void
     */
    void addWaiter(Waiter* waiter);

     /**
     * @brief Remove the waiter serving the group.
     * @param waiter The waiter to be removed from the group.
     * @return void
     */
    void removeWaiter(Waiter* waiter);

     /**
     * @brief Set the bill associated with the group.
     * @param bill The bill to be associated with the group.
     * @return void
     */
    void setBill(Bill* bill);

     /**
     * @brief Get the bill associated with the group.
     * @return The bill associated with the group.
     */
    Bill* getBill();
    
     /**
     * @brief Notify the waiter about group updates.
     * @return void
     */
    void notify();
};

#endif
