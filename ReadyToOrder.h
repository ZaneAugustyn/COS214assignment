#ifndef READYTOORDER_H
#define READYTOORDER_H

#include "GroupState.h"
#include <iostream>

/**
 * @class ReadyToOrder
 * @brief This class represent the ReadyToOrder state of the customer
*/
class ReadyToOrder : public GroupState
{
private:
    string stateName_;
public:
    /**
     * @brief constructor
    */
    ReadyToOrder();

    /**
     * @brief destructor
    */
    ~ReadyToOrder();

    /**
     * @brief the ConcreteClass method to handle the RequestToOrder request
     * @param group the group to update the state of
     * @return void  
    */
    virtual void RequestToOrder(Group * group);

    /**
     * @brief the ConcreteClass method to handle the WaitInQueue request
     * @param group the group to update the state of
     * @return void  
    */
    virtual void WaitInQueue(Group * group);

    /**
     * @brief the ConcreteClass method to handle the RequestTab request
     * @param group the group to update the state of
     * @return void  
    */
    virtual void RequestTab(Group * group);

    /**
     * @brief the ConcreteClass method to handle the RequestBill request
     * @param group the group to update the state of
     * @return void  
    */
    virtual void RequestBill(Group * group);

    /**
     * @brief method to return a string of the state name
     * @return string
    */
    virtual string ToString();
};

#endif
