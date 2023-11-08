#ifndef _MAITRED_H
#define _MAITRED_H

#include "FloorState.h"
#include "Floor.h"
#include "Group.h"
#include "Full.h"
#include "SpaceAvailable.h"

using namespace std;

/**
 * @class MaitreD
 * @brief This class is represent the Maitre D that is responsible for the managing the floor
*/
class MaitreD
{
private:
    int availableTables_;
    Floor* myFloor_;
    vector<Group*> waitingGroups_;
    vector<Waiter*> waiters_;

public:
    /**
     * @brief constructor
     * @param myF is the floor that the maitreD will be working on
     * @return none
    */
    MaitreD(Floor* myF, int tables);

    /**
     * @brief destructor
     * @param none
     * @return none
    */
    ~MaitreD();

    /**
     * @brief This method calculates how many tables are needed for the group
     * @param groupsize is the size of the group that wants to be seated
     * @return int
    */
    int CalculateTablesNeeded(int groupSize);

    /**
     * @brief this method checks if there are enough tables for the current group to be seated
     * @param groupsize is the size of the group that wants to be seated
     * @return bool
    */
    bool CheckAvailability(int groupSize);

    /**
     * @brief This method checks if the state of the floor is Full or SpaceAvailable if full it returns false otherwise true
     * @param currentState of the floor (full or space available)
     * @return bool
    */
    bool CheckCurrentFloorState(FloorState* currState);

    /**
     * @brief this method seats the group to the floor
     * @param none
     * @return void
    */
    void AddGroupToFloor();

    /**
     * @brief this method removes the group from the floor letting those tables open up for the next group
     * @param group that wants to leave the floor
     * @return void
    */
    void RemoveGroupFromFloor(Group* group);

    /**
     * @brief this method adds a group to the waiting queue of groups that are waiting to be seated in the floor
     * @param group that wants to be added to the waiting queue to enter the floor
     * @return void
    */
    void AddGroupToWaitingGroups(Group* group);

    /**
     * @brief This method is used to set the waiterList vector that holds all the waiters
     * @param  W is a vector of waiters that holds all waiters that will be working between the floor and the kitchen
     * @return void
    */
    void SetWaiterList(std::vector<Waiter*> W);

    /**
     * @brief This method checks if tables are available if not it sets the floor state to full
     * @param  none
     * @return void
    */
    void TableChecker();

    /**
     * @brief This method returns the groups waiting to enter the floor
     * @param  none
     * @return std::vector<Group*>
    */
    vector<Group*> GetAwaitingGroup();
    /**
     * @brief This method returns floor that the maitreD is on
     * @param  none
     * @return Floor*
    */
    Floor* GetFloor();
};

#endif
