#ifndef _MAITRED_H
#define _MAITRED_H

#include "FloorState.h"
#include "Floor.h"
#include "Group.h"
// code here
class MaitreD
{
private:
    /* data */
    int availableTables;
    Floor* myFloor;
public:
    MaitreD(Floor* myF);
    ~MaitreD();

    int calculateTablesNeeded(int groupSize);

    bool checkAvailability(int groupSize);
    bool checkCurrentFloorState(FloorState* currState);

    // void addGroupToFloor(Group* group);
    // void removeGroupFromFloor(Group* group);
};

#endif
