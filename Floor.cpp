#include "Floor.h"
#include "Full.h"
#include "SpaceAvailable.h"

Floor::Floor(/* args */)
{
    floorState_ = new SpaceAvailable();
}

Floor::~Floor()
{
}

FloorState* Floor::getCurrentState()
{ 
    return floorState_; 
}
void Floor::setCurrentState(FloorState* state)
{
    cout<<"The floor state has been changed to "<<state->getName()<<endl;
    this->floorState_ = state;
}

void Floor::seatGroup(Group* group)
{
    groups_.push_back(group);
}

void Floor::excuseGroup(Group* group)
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

void Floor::setFull()
{
    this->setCurrentState(new Full());
}

void Floor::setSpaceAvailable()
{
    this->setCurrentState(new SpaceAvailable());
}