#ifndef _FLOOR_H
#define _FLOOR_H

#include <iostream>
#include <vector>

#include "FloorState.h"
#include "Group.h"
#include "SpaceAvailable.h"

class MaitreD;
// code here
class Floor
{
private:
    /* data */
    FloorState* floorState_;
    MaitreD* maitreD_;
    std::vector<Group*> groups_;
public:
    /**
     * @brief constructor
     * @param none
     * @return none
    */
    Floor(/* args */);
    /**
     * @brief destructor
     * @param none
     * @return none
    */
    ~Floor();

    /**
     * @brief this method gets the current state of the floor
     * @param none
     * @return FloorState*
    */
    FloorState* getCurrentState();

    /**
     * @brief this method gets the std::vector<Group*> groups_ of the floor
     * @param none
     * @return std::vector<Group*>
    */
    std::vector<Group*> getGroups();

    /**
     * @brief this method sets the current state of the floor
     * @param state of the floor to which floor must be updated to
     * @return FloorState*
    */
    void setCurrentState(FloorState* state);

    /**
     * @brief this method seats a group to the floor by adding it to the groups vector
     * @param group that will be seated to the floor
     * @return void
    */
    void seatGroup(Group* group);

    /**
     * @brief this method removes a group to the floor by adding it to the groups vector
     * @param group that will be removed to the floor
     * @return void
    */
    void excuseGroup(Group* group);

    /**
     * @brief this method sets the current state of the floor to Full
     * @param none
     * @return void
    */
    void setFull();

    /**
     * @brief this method sets the current state of the floor to SpaceAvailable
     * @param none
     * @return void
    */
    void setSpaceAvailable();
};

#endif
