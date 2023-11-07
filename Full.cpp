
#include "Full.h"
#include "Floor.h"

Full::Full()
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
    floor->SetCurrentState(state);
}

string Full::GetName()
{
    return name_;
}
