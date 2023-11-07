#include "SpaceAvailable.h"

SpaceAvailable::SpaceAvailable(/* args */)
{
    name_ = "SPACEAVAILABLE";
}

SpaceAvailable::~SpaceAvailable()
{
}

void SpaceAvailable::ChangeState(Floor* floor, FloorState* state)
{
    if(floor == nullptr || state == nullptr)
    {
        return;
    }

    floor->SetCurrentState(state);
}

string SpaceAvailable::GetName()
{
    return name_;
}
