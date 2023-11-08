#ifndef _FLOORSTATE_H
#define _FLOORSTATE_H

class Floor;

#include <array>
#include <iostream>
#include <string>

using namespace std;

/**
 * @class FloorState
 * @brief This class represents the state of the floor in the restaurant
*/
class FloorState
{
public:
    /**
     * @brief constructor
     * @return none
    */
    FloorState();

    /**
     * @brief destructor
     * @return none
    */
    ~FloorState();

    /**
     * @brief virtyal method used to get the name of the state
     * @param none
     * @return string
    */
    virtual string GetName() = 0;

    /**
     * @brief This is a virtual method that is used to change the current state of the floor
     * @param floor is the floor that wants to change its state
     * @param state is the state that floor wants to be changed to
     * @return void
    */
    virtual void ChangeState(Floor* floor, FloorState* state)=0;
};

#endif
