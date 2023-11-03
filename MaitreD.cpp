#include "MaitreD.h"
#include <cmath>

MaitreD::MaitreD(Floor* myF)
{
    if(myF == nullptr)
    {
        return;
    }

    myFloor_ = myF;
    availableTables_ = 20;
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
    if(!checkCurrentFloorState(myFloor_->getCurrentState()))//floor state is full
    {
        return false;
    }
    int numTablesNeeded = 0;
    numTablesNeeded = calculateTablesNeeded(groupSize);
    if(availableTables_ < numTablesNeeded)
    {
        return false;
    }
    return true;
}

bool MaitreD::checkCurrentFloorState(FloorState* floorState)
{
    if(floorState == nullptr)
    {
        return false;;
    }

    if(floorState->getName() == "SPACEAVAILABLE")
    {
        return true;
    }
    return false;
}

void MaitreD::addGroupToFloor() {
    if (WaitingGroups_.empty()) {
        std::cout << "No waiting groups available." << std::endl;
        return;
    }

    Group* group = WaitingGroups_.front();

    if (checkAvailability(group->GetGroupNumber())) {
        int tablesNeeded = calculateTablesNeeded(group->GetGroupNumber());
        availableTables_ -= tablesNeeded;

        // Decide how you want to add the group to the floor.

        WaitingGroups_.erase(WaitingGroups_.begin());//remove group from waiting groups
        myFloor_->seatGroup(group);//group is seating on the floor

        std::cout << "Group added to the floor." << std::endl;
    } else {
        std::cout << "No availability for the group." << std::endl;
    }
}

void MaitreD::removeGroupFromFloor(Group* group)
{
    if(group == nullptr)
    {
        return;
    }

    availableTables_ = availableTables_ + calculateTablesNeeded(group->GetGroupNumber());//update tables since group left
    //addGroupToFloor(add group somehow) or are we going to just use a queue and add the first one to said queue or have 
    //a var where we keep the group that is waiting if we need to pop the queue to be able to access the group
    myFloor_->excuseGroup(group);//group is excused from the floor

    cout<<"Group removed from floor"<<endl;

}

void MaitreD::addGroupToWaitingGroups(Group* group)
{
    if(group == nullptr)
    {
        return;
    }

    WaitingGroups_.push_back(group);
}