#ifndef _FLOORSTATE_H
#define _FLOORSTATE_H

class Floor;
// code here

#include <array>
using namespace std;
#include <iostream>
#include <string>

class FloorState
{
private:
    /* data */
public:
    /**
     * @brief constructor
     * @return none
    */
    FloorState(/* args */);
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
    virtual string getName() = 0;

    /**
     * @brief This is a virtual method that is used to change the current state of the floor
     * @param floor is the floor that wants to change its state
     * @param state is the state that floor wants to be changed to
     * @return void
    */
    virtual void ChangeState(Floor* floor, FloorState* state)=0;
};

#endif
