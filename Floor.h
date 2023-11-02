#ifndef _FLOOR_H
#define _FLOOR_H

#include <iostream>
#include <vector>

#include <FloorState.h>
#include "Group.h"
#include "SpaceAvailable.h"

class MaitreD;
// code here
class Floor
{
private:
    /* data */
    FloorState* floorState;
    MaitreD* maitreD;
    std::vector<Group*> groups_;
public:
    Floor(/* args */);
    ~Floor();

    void Request();
    FloorState* getCurrentState();
    void setCurrentState(FloorState* state);
};

#endif
