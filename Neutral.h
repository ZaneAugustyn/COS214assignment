#ifndef NEUTRAL_H
#define NEUTRAL_H

#include "EmotionalState.h"
#include <iostream>

/**
 * @class Neutral
 * @brief This class is represent the neutral state of the group
*/

class Neutral : public EmotionalState
{
private:
    string stateName_;
public:
    /**
     * @brief constructor
    */
    Neutral();

    /**
     * @brief destructor
    */
    ~Neutral();

    /**
     * @brief the ConcreteClass method to handle the MakeUnhappy request
     * @param group the group to update the state of
     * @return void  
    */
    virtual void MakeUnhappy(Group * group);
    
    /**
     * @brief the ConcreteClass method to handle the Happy request
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