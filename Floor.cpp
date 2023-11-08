#include "Floor.h"
#include "Full.h"
#include "SpaceAvailable.h"

Floor::Floor()
{
    floorState_ = new SpaceAvailable();
    cout<<"Floor Created"<<endl;
}

Floor::~Floor()
{
}

FloorState* Floor::GetCurrentState()
{ 
    return floorState_; 
}
void Floor::SetCurrentState(FloorState* state)
{
    cout<<"The floor state has been changed to "<<state->GetName()<<endl;
    this->floorState_ = state;
}

void Floor::SeatGroup(Group* group)
{
    groups_.push_back(group);
}

void Floor::ExcuseGroup(Group* group)
{
    if(group != nullptr)
    {
        for (auto it = groups_.begin(); it != groups_.end(); ++it) {
                if (*it == group) {
                    // Remove the element from the vector
                    groups_.erase(it);
                    break;  // Break to avoid further unnecessary iterations
                }
            }
    }
}

void Floor::SetFull()
{
    this->SetCurrentState(new Full());
}

void Floor::SetSpaceAvailable()
{
    this->SetCurrentState(new SpaceAvailable());
}

std::vector<Group*> Floor::GetGroups()
{
    return groups_;
}

void Floor::SetGroups(std::vector<Group*> g)
{
    groups_ = g;
}