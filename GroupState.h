#ifndef GROUPSTATE_H
#define GROUPSTATE_H

#include "Group.h"
#include <string>
using namespace std;

class Group;
class GroupState
{
private:
    
public:

    /**
     * @brief default constructor
     * */  
    GroupState();

    /**
     * @brief destructor
    */
    virtual ~GroupState();

    /**
     * @brief the State participant of the State pattern that defines the interface for the RequestToOrder behaviour of the ConcreteStates
     * @param group the group that is requesting the request
     * @return void
    */
    virtual void RequestToOrder(Group * group) = 0;

    /**
     * @brief the State participant of the State pattern that defines the interface for the WaitInQueue behaviour of the ConcreteStates
     * @param group the group that is requesting the request
     * @return void
    */
    virtual void WaitInQueue(Group * group) = 0;

    /**
     * @brief the State participant of the State pattern that defines the interface for the MakeUnhappy behaviour of the ConcreteStates
     * @param group the group that is requesting the request
     * @return void
    */
    virtual void MakeUnhappy(Group * group) = 0;

    /**
     * @brief the State participant of the State pattern that defines the interface for the MakeHappy behaviour of the ConcreteStates
     * @param group the group that is requesting the request
     * @return void
    */
    virtual void MakeHappy(Group * group) = 0;

    /**
     * @brief the State participant of the State pattern that defines the interface for the RequestTab behaviour of the ConcreteStates
     * @param group the group that is requesting the request
     * @return void
    */
    virtual void RequestTab(Group * group) = 0;

    /**
     * @brief the State participant of the State pattern that defines the interface for the RequestBill behaviour of the ConcreteStates
     * @param group the group that is requesting the request
     * @return void
    */
    virtual void RequestBill(Group * group) = 0;

    /**
     * @brief the State participant of the State pattern that defines the interface for the MakeNeutral behaviour of the ConcreteStates
     * @param group the group that is requesting the request
     * @return void  
    */
    virtual void MakeNeutral(Group * group) = 0;


    /**
     * @brief an interface method to return the ConcreteState name
     * @return string
    */
    virtual string ToString() = 0;
};


#endif
