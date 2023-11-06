#include "Happy.h"
#include "ReadyToOrder.h"
#include "Unhappy.h"
#include "ReadyForBill.h"
#include "Neutral.h"

Happy::Happy()
{
    stateName_ = "Happy";
    cout << "Group emotional state changed to " << stateName_ << endl;
    
}

Happy::~Happy()
{
}

void Happy::RequestToOrder(Group *group)
{
    // cout << "in Happy: Move to RequestToOrder state" << endl;
    group->SetState(new ReadyToOrder());
}

void Happy::WaitInQueue(Group *group)
{
    cout << "Cannot move to WaitForTable state." << endl;
}

void Happy::MakeUnhappy(Group *group)
{
    group->SetState(new Unhappy());
    group->updateLastEmotion(new Unhappy());
    
}

void Happy::MakeHappy(Group *group)
{
    cout << "Already in Happy state." << endl;
}

void Happy::MakeNeutral(Group *group)
{
    group->SetState(new Neutral());
    group->updateLastEmotion(new Neutral());
}

void Happy::RequestTab(Group *group)
{
    cout << "Cannot request a tab when seated." << endl;
}

void Happy::RequestBill(Group *group)
{
    group->SetState(new ReadyForBill());
}

string Happy::ToString()
{
    return this->stateName_;
}