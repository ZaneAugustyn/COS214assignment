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
    int availableTables_;
    Floor* myFloor_;
    std::vector<Group*> WaitingGroups_;

public:
    MaitreD(Floor* myF);
    ~MaitreD();

    int calculateTablesNeeded(int groupSize);

    bool checkAvailability(int groupSize);
    bool checkCurrentFloorState(FloorState* currState);

    void addGroupToFloor();
    void removeGroupFromFloor(Group* group);


    void addGroupToWaitingGroups(Group* group);

    bool isPeopleWaiting();

};

#endif
