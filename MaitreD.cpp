#include "MaitreD.h"

#include <cmath>

MaitreD::MaitreD(Floor* myF)
{
    myFloor = myF;
    availableTables = 20;
}

MaitreD::~MaitreD()
{
}

int MaitreD::calculateTablesNeeded(int groupSize)
{
    float numNeeded = 0;
    float test = groupSize;
    numNeeded = (test - 2)/2;
    numNeeded = ceil(numNeeded);
    int ret = numNeeded;
    return ret;
}

bool MaitreD::checkAvailability(int groupSize)
{
    if(!checkCurrentFloorState(myFloor->getCurrentState()))//floor state is full
    {
        return false;
    }
    int numNeeded = 0;
    numNeeded = calculateTablesNeeded(groupSize);
    if(availableTables < numNeeded)
    {
        return false;
    }
    return true;
}

bool MaitreD::checkCurrentFloorState(FloorState* floorState)
{
    if(floorState->getName() == "SPACEAVAILABLE")
    {
        return true;
    }
    return false;
}

// void MaitreD::addGroupToFloor(Group* group)
// {
//     if(checkAvailability(group->getGroupNumber()))
//     {
//         availableTables = availableTables - calculateTablesNeeded(group->getGroupNumber());
//         //We need to decide how we want to add the groups to the floor.
//         cout<<"Group added to the floor"<<endl;
//     }
// }

// void MaitreD::removeGroupFromFloor(Group* group)
// {
//     availableTables = availableTables + calculateTablesNeeded(group->getGroupNumber());//update tables since group left
//     //addGroupToFloor(add group somehow) or are we going to just use a queue and add the first one to said queue or have 
//     //a var where we keep the group that is waiting if we need to pop the queue to be able to access the group
//     cout<<"Group removed from floor"<<endl;

// }
