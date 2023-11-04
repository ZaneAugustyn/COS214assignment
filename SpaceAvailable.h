#ifndef _SPACEAVAILABLE_H
#define _SPACEAVAILABLE_H

#include "Floor.h"
#include "FloorState.h"
// code here
class SpaceAvailable : public FloorState 
{
private:
    /* data */
    string name_;
public:
    /**
     * @brief constructor
    */
    SpaceAvailable(/* args */);

    /**
     * @brief destructor
    */
    ~SpaceAvailable();

    /**
     * @brief used to get the name of the state and return it
     * @param none
     * @return string
    */
    string getName(){return this->name_;};

    /**
     * @brief This method is used to change the current state of the floor
     * @param floor is the floor that wants to change its state, and state is the state that floor wants to be changed to
     * @return void
    */
    void ChangeState(Floor* floor, FloorState* state);
};

#endif
