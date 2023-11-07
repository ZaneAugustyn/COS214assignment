#ifndef HAPPY_H
#define HAPPY_H

#include "EmotionalState.h"
#include <iostream>

/**
 * @class Happy
 * @brief This class is represents the group's happy state
*/

class Happy : public EmotionalState
{
private:
    string stateName_;
public:
    /**
     * @brief constructor
    */
    Happy();

    /**
     * @brief destructor
    */
    ~Happy();

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