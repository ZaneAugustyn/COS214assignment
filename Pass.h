#ifndef _PASS_H
#define _PASS_H

#include <vector>
#include <iostream>
using namespace std;

class Order;
class Waiter;
class Chef;
class Plate;

/**
 * @class Pass
 * @brief This class acts as the mediator between the chefs and the waiters, it connects the floor and the kitchen together
*/

class Pass
{
  private:
    vector<Order*> orders_;
    vector<vector<Plate*>> listOfTrays_;

  protected:
    vector<Waiter*> listOfWaiters_;
    Chef* headChef_;

  public:
    /**
     * @brief default constructor
     * @return none
    */
    Pass();

    /**
     * @brief Constructor
     * @param waiters takes in the list of waiters in the restaurant
     * @param headChef takes in a head chef pointer to the chef that is the start of the chain of responsibility
     * @return none
    */
    Pass(vector<Waiter*> waiters, Chef* headChef);

    /**
     * @brief the head chef is notifies when the waiter added a order to the plate
     * @param waiter contains a reference of the waiter who is notifying the head chef
     * @return void
    */
    void notifyHeadChef(Waiter* waiter);

    /**
     * @brief waiter is notified as soon as a order is complete and added to the pass
     * @param headchef contains a reference of the chef who is notifying the waiter that the order is complete
     * @return void
    */
    void notifyWaiter(Chef* headchef);

    /**
     * @brief add a plate (a completed order) to the tray on the pass
     * @param plates contain the plate containing the order items
     * @return void
    */
    void addToListOfTrays(vector<Plate*> plates);

    /**
     * @brief used by waiter to add a order to the order list in the pass
     * @param order contains the group order
     * @return void
    */
    void addOrder(Order* order);

    /**
     * @brief dequeue the first order from the list (First come first serve)
     * @return void
    */
    void dequeueOrder();

    /**
     * @brief virtual destructor
     * @return none
    */
    virtual ~Pass();
};

#endif
