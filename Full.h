#ifndef _FULL_H
#define _FULL_H

#include "FloorState.h"
#include "Floor.h"
// code here
class Full : public FloorState
{
private:
    /* data */
public:
    Full(/* args */);
    ~Full();

    void ChangeState(Floor* floor, FloorState* state);
};

#endif
