#ifndef _FLOORSTATE_H
#define _FLOORSTATE_H
// code here
class FloorState
{
private:
    /* data */
public:
    FloorState(/* args */);
    ~FloorState();

    virtual void ChangeState(Floor* floor, FloorState* state) = 0;
};

#endif
