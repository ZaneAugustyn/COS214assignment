#include "Full.h"

Full::Full(/* args */)
{
    name = "FULL";
}

Full::~Full()
{
}

void Full::ChangeState(Floor* floor, FloorState* state)
{
    floor->setCurrentState(state);
}