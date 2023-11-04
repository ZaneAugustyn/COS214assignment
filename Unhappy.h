#ifndef UNHAPPY_H
#define UNHAPPY_H

#include "GroupState.h"
#include <iostream>

class Unhappy : public GroupState
{
private:
    string stateName_;
public:
    /**
     * @brief constructor
    */
    Unhappy();

    /**
     * @brief destructor
    */
    ~Unhappy();

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
     * @brief the ConcreteClass method to handle the MakeUnhappy request
     * @param group the group to update the state of
     * @return void  
    */
    virtual void MakeUnhappy(Group * group);

    /**
     * @brief the ConcreteClass method to handle the MakeHappy request
     * @param group the group to update the state of
     * @return void  
    */
    virtual void MakeHappy(Group * group);

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
