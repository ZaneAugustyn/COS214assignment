#ifndef _SPACEAVAILABLE_H
#define _SPACEAVAILABLE_H

#include "Floor.h"
#include "FloorState.h"
// code here
class SpaceAvailable : public FloorState 
{
private:
    /* data */
    string name;
public:
    SpaceAvailable(/* args */);
    ~SpaceAvailable();

    string getName(){return this->name;};
    void ChangeState(Floor* floor, FloorState* state);
};

#endif
