#include "SpaceAvailable.h"

SpaceAvailable::SpaceAvailable(/* args */)
{
    name = "SPACEAVAILABLE";
}

SpaceAvailable::~SpaceAvailable()
{
}

void SpaceAvailable::ChangeState(Floor* floor, FloorState* state)
{
    floor->setCurrentState(state);
}