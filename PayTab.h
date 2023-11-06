#ifndef PAYTAB_H
#define PAYTAB_H

#include "GroupState.h"
#include <iostream>

/**
 * @class PayTab
 * @brief This class is used for managing the tab of customers that can be payed at a later stage
*/

class PayTab : public GroupState
{
private:
    string stateName_;
public:
    /**
     * @brief constructor
    */
    PayTab();

    /**
     * @brief destructor
    */
    ~PayTab();

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
     * @brief the ConcreteClass method to handle the MankeUnhappy request
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
     * @brief the ConcreteClass method to handle the Neutral request
     * @param group the group to update the state of
     * @return void  
    */
    virtual void MakeNeutral(Group * group);

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
