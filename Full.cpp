#include "Full.h"

Full::Full(/* args */)
{
}

Full::~Full()
{
}

void Full::ChangeState(Floor* floor, FloorState* state)
{
    floor->setCurrentState(state);
}