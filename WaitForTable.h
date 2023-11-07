#ifndef WAITFORTABLE_H
#define WAITFORTABLE_H

#include "GroupState.h"
#include <iostream>
    /**
     * @class WaitForTable
     * @brief This class represents that the group should wait for a table (that is their state)
    */
class WaitForTable : public GroupState
{
private:
    string stateName_;
public:
    /**
     * @brief constructor
    */
    WaitForTable();

    /**
     * @brief destructor
    */
    ~WaitForTable();

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
