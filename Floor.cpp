#include "Floor.h"

Floor::Floor(/* args */)
{
    floorState = new SpaceAvailable();
}

Floor::~Floor()
{
}

FloorState* Floor::getCurrentState()
{ 
    return floorState; 
}
void Floor::setCurrentState(FloorState* state)
{
    cout<<"The floor state has been changed to "<<state->getName()<<endl;
    this->floorState = state;

}