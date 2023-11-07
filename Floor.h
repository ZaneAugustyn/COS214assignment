#ifndef _FLOOR_H
#define _FLOOR_H

#include <iostream>
#include <vector>

#include "FloorState.h"
#include "Group.h"
#include "SpaceAvailable.h"

class MaitreD;

/**
* @class Floor
* @brief This class represents the floor of the restaurant
*/
class Floor
{
private:
    /* data */
    FloorState* floorState_;
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
    FloorState* GetCurrentState();

    /**
     * @brief this method gets the std::vector<Group*> groups_ of the floor
     * @param none
     * @return std::vector<Group*>
    */
    std::vector<Group*> GetGroups();
    
     /**
     * @brief this method sets the std::vector<Group*> groups_ of the floor
     * @param std::vector<Group*>
     * @return void
    */
    void SetGroups(std::vector<Group*> g);

    /**
     * @brief this method sets the current state of the floor
     * @param state of the floor to which floor must be updated to
     * @return void
    */
    void SetCurrentState(FloorState* state);

    /**
     * @brief this method seats a group to the floor by adding it to the groups vector
     * @param group that will be seated to the floor
     * @return void
    */
    void SeatGroup(Group* group);

    /**
     * @brief this method removes a group to the floor by adding it to the groups vector
     * @param group that will be removed to the floor
     * @return void
    */
    void ExcuseGroup(Group* group);

    /**
     * @brief this method sets the current state of the floor to Full
     * @param none
     * @return void
    */
    void SetFull();

    /**
     * @brief this method sets the current state of the floor to SpaceAvailable
     * @param none
     * @return void
    */
    void SetSpaceAvailable();
};

#endif
