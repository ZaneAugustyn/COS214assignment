#include "SpaceAvailable.h"

SpaceAvailable::SpaceAvailable(/* args */)
{
}

SpaceAvailable::~SpaceAvailable()
{
}

void SpaceAvailable::ChangeState(Floor* floor, FloorState* state)
{
    floor->setCurrentState(state);
}