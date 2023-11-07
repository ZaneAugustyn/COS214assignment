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

int MaitreD::CalculateTablesNeeded(int groupSize)
{
    float numNeeded = 0;
    float test = groupSize;
    numNeeded = (test - 2)/2;
    numNeeded = ceil(numNeeded);
    int ret = numNeeded;
    return ret;
}

bool MaitreD::CheckAvailability(int groupSize)
{
    this->TableChecker();//makes sure that the floor state is up to date
    if(!CheckCurrentFloorState(myFloor_->GetCurrentState()))//floor state is full
    {
        return false;
    }
    int numTablesNeeded = 0;
    numTablesNeeded = CalculateTablesNeeded(groupSize);
    if(availableTables_ < numTablesNeeded)
    {
        return false;
    }
    return true;
}

bool MaitreD::CheckCurrentFloorState(FloorState* floorState)
{
    if(floorState == nullptr)
    {
        return false;;
    }

    if(floorState->GetName() == "SPACEAVAILABLE")
    {
        return true;
    }
    return false;
}

void MaitreD::AddGroupToFloor()
{
    if (waitingGroups_.empty()) 
    {
        std::cout << "No waiting groups available." << std::endl;
        return;
    }
    
    if(waitingGroups_.front()->GetState()->ToString() == "PayTab") 
    {
        cout<<endl<<PINK<<"Welcome back to Le McDonalds - thank you for coming to settle the tab"<<RESET<<endl;
        waitingGroups_.front()->GetBill()->Pay(waitingGroups_.front(), 'F');
        waitingGroups_.erase(waitingGroups_.begin());
        return;
    }

    this->TableChecker();//sets table to full or spaceavailable if needed

    if(!this->CheckCurrentFloorState(myFloor_->GetCurrentState()))//this checks if the curent floorstate is full 
    {
        return;//state is full
    }

    Group* group = waitingGroups_.front();

    if (CheckAvailability(group->GetCustomers().size())) 
    {
        int tablesNeeded = CalculateTablesNeeded(group->GetCustomers().size());
        availableTables_ -= tablesNeeded;

        // Decide how you want to add the group to the floor.

        waitingGroups_.erase(waitingGroups_.begin());//remove group from waiting groups
        myFloor_->SeatGroup(group);//group is seating on the floor

        Waiter* w1 = waiters_.front();
        group->AddWaiter(w1);
        //w1->addGroup(group);


        waiters_.erase(waiters_.begin());
        waiters_.push_back(w1);


        std::cout <<LIGHT_GREEN<< "Group "<<group->GetGroupNumber()<<" added to the floor." <<RESET<< std::endl;
    } else 
    {
        std::cout <<RED<< "No availability for the group." <<RESET<< std::endl;
    }
}

void MaitreD::RemoveGroupFromFloor(Group* group)
{
    if(group == nullptr)
    {
        return;
    }

    if(group->GetState()->ToString() == "ReadyToOrder")
    {
        cout<<RED<<"You cannot leave without paying"<<RESET<<endl;
        return;
    }
    
    availableTables_ = availableTables_ + CalculateTablesNeeded(group->GetCustomers().size());//update tables since group left
    //addGroupToFloor(add group somehow) or are we going to just use a queue and add the first one to said queue or have 
    //a var where we keep the group that is waiting if we need to pop the queue to be able to access the group
    myFloor_->ExcuseGroup(group);//group is excused from the floor

    if(group->GetState()->ToString() == "PayTab") 
    {
        AddGroupToWaitingGroups(group);
    }


}

void MaitreD::AddGroupToWaitingGroups(Group* group)
{
    if(group == nullptr)
    {
        return;
    }

    waitingGroups_.push_back(group);
}

void MaitreD::SetWaiterList(std::vector<Waiter*> W)
{
    cout<<LIGHT_GREEN<<"Waiters have been hired"<<RESET<<endl;
    this->waiters_ = W;
}

void MaitreD::TableChecker()
{
    if(availableTables_ == 0)
    {
        if(myFloor_->GetCurrentState()->GetName() == "FULL")
            {
                return;
            }
        myFloor_->SetFull();
    }
    else if(availableTables_ >= 1)
    {
        if(myFloor_->GetCurrentState()->GetName() == "SPACEAVAILABLE")
            {
                return;
            }
        myFloor_->SetSpaceAvailable();
    }
}

std::vector<Group*> MaitreD::GetAwaitingGroup()
{
    return waitingGroups_;
}

Floor* MaitreD::GetFloor()
{
    return myFloor_;
}
