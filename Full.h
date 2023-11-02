#ifndef _FULL_H
#define _FULL_H

#include "FloorState.h"
#include "Floor.h"
// code here
class Full : public FloorState
{
private:
    /* data */
    string name;
public:
    Full(/* args */);
    ~Full();

    string getName(){return this->name;};
    void ChangeState(Floor* floor, FloorState* state);
};

#endif
