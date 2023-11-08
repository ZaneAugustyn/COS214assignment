#ifndef EMOTIONALSTATE_H
#define EMOTIONALSTATE_H

#include "Group.h"
#include <string>
using namespace std;

class Group;

/**
 * @class EmotionalState
 * @brief This class represents the group's emotional state
*/
class EmotionalState
{
private:
    
public:

    /**
     * @brief default constructor
     * */  
    EmotionalState();

    /**
     * @brief destructor
    */
    virtual ~EmotionalState();

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