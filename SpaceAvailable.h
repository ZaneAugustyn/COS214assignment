#ifndef _SPACEAVAILABLE_H
#define _SPACEAVAILABLE_H

#include "Floor.h"
#include "FloorState.h"
// code here
class SpaceAvailable : public FloorState 
{
private:
    /* data */
public:
    SpaceAvailable(/* args */);
    ~SpaceAvailable();

    void ChangeState(Floor* floor, FloorState* state);
};

#endif
