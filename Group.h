#ifndef _GROUP_H
#define _GROUP_H

#include <iostream>
#include <vector>
#include<string>

#include "GroupState.h"
#include "EmotionalState.h"
#include "Customer.h"


class GroupState;
class EmotionalState;

class Waiter;
class Bill;

using namespace std;

/**
 * @class Group
 * @brief This class represents the group of customers that will be seated and will order
*/
class Group
{
private:
    GroupState* groupState_;
    std::vector<Customer*> customers_;
    Bill* bill_;
    Waiter* waiter_;
    int groupNumber_;
    EmotionalState* lastEmotion_;

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
    void AddCustomer(Customer* customer);

    /**
     * @brief Get the customers in the group.
     * @return A vector of Customer pointers.
     */
    vector<Customer*> GetCustomers();
    
    /**
     * @brief Get the waiter serving the group.
     * @return The waiter serving the group.
     */
    Waiter* GetWaiter();

    /**
     * @brief set the state of the group
     * @param state the state to be assigned to a group
     * @return void
    */
    void SetState(GroupState * state);

    /**
     * @brief set the emotional state of the group
     * @param state the emotional state to be assigned to a group
     * @return void
    */
    void SetLastEmotion(EmotionalState * state);

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
    void MakeNeutral();

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

    /**
     * @brief function to return the first customer in the group
     * @return Customer*
    */
    Customer* GetFirstCustomer();

    /**
     * @brief Add a waiter to serve the group.
     * @param waiter The waiter to be assigned to the group.
     * @return void
     */
    void AddWaiter(Waiter* waiter);

     /**
     * @brief Remove the waiter serving the group.
     * @param waiter The waiter to be removed from the group.
     * @return void
     */
    void RemoveWaiter(Waiter* waiter);

     /**
     * @brief Set the bill associated with the group.
     * @param bill The bill to be associated with the group.
     * @return void
     */
    void SetBill(Bill* bill);

     /**
     * @brief Get the bill associated with the group.
     * @return The bill associated with the group.
     */
    Bill* GetBill();
    
     /**
     * @brief Notify the waiter about group updates.
     * @return void
     */
    void Notify();

    /**
     * @brief Update last emotion
     * @param State to update the lastEmotion to
     * @return void
     */
    void UpdateLastEmotion(GroupState* State);

    /**
     * @brief get last emotion
     * @return EmotionalState*
     */
    EmotionalState* GetLastEmotion();
};

#endif
