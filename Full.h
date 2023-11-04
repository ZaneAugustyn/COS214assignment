#ifndef _FULL_H
#define _FULL_H

#include "FloorState.h"
// code here
class Full : public FloorState
{
private:
    /* data */
    string name_;
public:
    /**
     * @brief constructor
     * @return none
    */
    Full(/* args */);

    /**
     * @brief destructor
     * @return none
    */
    ~Full();

    /**
     * @brief used to get the name of the state and return it
     * @param none
     * @return string
    */
    string getName(){return this->name_;};

    /**
     * @brief This method is used to change the current state of the floor
     * @param floor is the floor that wants to change its state
     * @param state is the state that floor wants to be changed to
     * @return void
    */
    void ChangeState(Floor* floor, FloorState* state);

};

#endif
