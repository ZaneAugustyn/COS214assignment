
#include "Full.h"
#include "Floor.h"

Full::Full(/* args */)
{
    name_ = "FULL";
}

Full::~Full()
{
}

void Full::ChangeState(Floor* floor, FloorState* state)
{
    if(floor == nullptr || state == nullptr)
    {
        return;
    }
    floor->setCurrentState(state);
}
