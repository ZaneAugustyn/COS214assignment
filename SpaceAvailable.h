#ifndef _SPACEAVAILABLE_H
#define _SPACEAVAILABLE_H

#include "Floor.h"
#include "FloorState.h"

/**
 * @class SpaceAvailable
 * @brief This class represent the SpaceAvailable state of the customer
*/
class SpaceAvailable : public FloorState 
{
private:
    string name_;
public:
    /**
     * @brief constructor
    */
    SpaceAvailable();

    /**
     * @brief destructor
    */
    ~SpaceAvailable();

    /**
     * @brief used to get the name of the state and return it
     * @param none
     * @return string
    */
    string GetName();

    /**
     * @brief This method is used to change the current state of the floor
     * @param floor is the floor that wants to change its state, and state is the state that floor wants to be changed to
     * @return void
    */
    void ChangeState(Floor* floor, FloorState* state);
};

#endif
