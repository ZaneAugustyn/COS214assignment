#ifndef GROUPSTATE_H
#define GROUPSTATE_H

#include "Group.h"
#include <string>

class Group;

using namespace std;

/**
 * @class GroupState
 * @brief This class represents the group's state
*/
class GroupState
{
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
     * @brief an interface method to return the ConcreteState name
     * @return string
    */
    virtual string ToString() = 0;
};


#endif
