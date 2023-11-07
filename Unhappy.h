#ifndef UNHAPPY_H
#define UNHAPPY_H

#include "EmotionalState.h"
#include <iostream>
/**
 * @class Unhappy
 * @brief This class represents a type of state of the group-that they are currently unhappy with the service
*/
class Unhappy : public EmotionalState
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
     * @brief the ConcreteClass method to handle the Neutral request
     * @param group the group to update the state of
     * @return void  
    */
    virtual void MakeNeutral(Group * group);

    /**
     * @brief method to return a string of the state name
     * @return string
    */
    virtual string ToString();
};



#endif
