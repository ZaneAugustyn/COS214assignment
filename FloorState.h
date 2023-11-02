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
    FloorState(/* args */);
    ~FloorState();

    virtual string getName() = 0;
    virtual void ChangeState(Floor* floor, FloorState* state)=0;
};

#endif
