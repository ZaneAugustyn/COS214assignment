#include "MaitreD.h"
#include "Bill.h"
#include <cmath>

#define YELLOW  "\033[33m"      /* Yellow */
#define RED     "\033[31m"      /* Red */
#define RESET   "\033[0m"
#define LIGHT_GREEN "\033[92m"  /* Light Green */
#define PINK    "\033[38;5;206m"  /* Pink */

MaitreD::MaitreD(Floor* myF, int tables)
{
    if(myF == nullptr)
    {
        return;
    }

    myFloor_ = myF;
    availableTables_ = tables;
}

MaitreD::~MaitreD()
{
}

int MaitreD::calculateTablesNeeded(int groupSize)
{
    float numNeeded = 0;
    float test = groupSize;
    numNeeded = (test - 2)/2;
    numNeeded = ceil(numNeeded);
    int ret = numNeeded;
    return ret;
}

bool MaitreD::checkAvailability(int groupSize)
{
    this->tableChecker();//makes sure that the floor state is up to date
    if(!checkCurrentFloorState(myFloor_->getCurrentState()))//floor state is full
    {
        return false;
    }
    int numTablesNeeded = 0;
    numTablesNeeded = calculateTablesNeeded(groupSize);
    if(availableTables_ < numTablesNeeded)
    {
        return false;
    }
    return true;
}

bool MaitreD::checkCurrentFloorState(FloorState* floorState)
{
    if(floorState == nullptr)
    {
        return false;;
    }

    if(floorState->getName() == "SPACEAVAILABLE")
    {
        return true;
    }
    return false;
}

void MaitreD::addGroupToFloor()
{
    if (WaitingGroups_.empty()) 
    {
        std::cout << "No waiting groups available." << std::endl;
        return;
    }
    
    if(WaitingGroups_.front()->GetState()->ToString() == "PayTab") 
    {
        cout<<endl<<PINK<<"Welcome back to Le McDonalds - thank you for coming to settle the tab"<<RESET<<endl;
        WaitingGroups_.front()->getBill()->Pay(WaitingGroups_.front(), 'F');
        WaitingGroups_.erase(WaitingGroups_.begin());
        return;
    }

    this->tableChecker();//sets table to full or spaceavailable if needed

    if(!this->checkCurrentFloorState(myFloor_->getCurrentState()))//this checks if the curent floorstate is full 
    {
        return;//state is full
    }

    Group* group = WaitingGroups_.front();

    if (checkAvailability(group->getCustomers().size())) 
    {
        int tablesNeeded = calculateTablesNeeded(group->getCustomers().size());
        availableTables_ -= tablesNeeded;

        // Decide how you want to add the group to the floor.

        WaitingGroups_.erase(WaitingGroups_.begin());//remove group from waiting groups
        myFloor_->seatGroup(group);//group is seating on the floor

        Waiter* w1 = Waiters_.front();
        group->addWaiter(w1);
        //w1->addGroup(group);


        Waiters_.erase(Waiters_.begin());
        Waiters_.push_back(w1);


        std::cout <<LIGHT_GREEN<< "Group "<<group->getGroupNumber()<<" added to the floor." <<RESET<< std::endl;
    } else 
    {
        std::cout <<RED<< "No availability for the group." <<RESET<< std::endl;
    }
}

void MaitreD::removeGroupFromFloor(Group* group)
{
    if(group == nullptr)
    {
        return;
    }
    availableTables_ = availableTables_ + calculateTablesNeeded(group->getCustomers().size());//update tables since group left
    //addGroupToFloor(add group somehow) or are we going to just use a queue and add the first one to said queue or have 
    //a var where we keep the group that is waiting if we need to pop the queue to be able to access the group
    myFloor_->excuseGroup(group);//group is excused from the floor

    cout<<LIGHT_GREEN<<"Group  "<<group->getGroupNumber()<<" removed from floor"<<RESET<<endl;

    if(group->GetState()->ToString() == "PayTab") 
    {
        addGroupToWaitingGroups(group);
    }


}

void MaitreD::addGroupToWaitingGroups(Group* group)
{
    if(group == nullptr)
    {
        return;
    }

    WaitingGroups_.push_back(group);
}

void MaitreD::setWaiterList(std::vector<Waiter*> W)
{
    cout<<LIGHT_GREEN<<"Waiters have been hired"<<RESET<<endl;
    this->Waiters_ = W;
}

void MaitreD::tableChecker()
{
    if(availableTables_ == 0)
    {
        if(myFloor_->getCurrentState()->getName() == "FULL")
            {
                return;
            }
        myFloor_->setFull();
    }
    else if(availableTables_ >= 1)
    {
        if(myFloor_->getCurrentState()->getName() == "SPACEAVAILABLE")
            {
                return;
            }
        myFloor_->setSpaceAvailable();
    }
}

std::vector<Group*> MaitreD::getAwaitingGroup()
{
    return WaitingGroups_;
}

Floor* MaitreD::getFloor()
{
    return myFloor_;
}
