#include "Happy.h"
#include "ReadyToOrder.h"
#include "Unhappy.h"
#include "ReadyForBill.h"
#include "Neutral.h"

Happy::Happy()
{
    stateName_ = "Happy";    
}

Happy::~Happy()
{
}

void Happy::RequestToOrder(Group *group)
{
    group->SetState(new ReadyToOrder());
}

void Happy::WaitInQueue(Group *group)
{
    cout << "Cannot move to WaitForTable state." << endl;
}

void Happy::MakeUnhappy(Group *group)
{
    group->SetState(new Unhappy());
    
}

void Happy::MakeHappy(Group *group)
{
    cout << "Already in Happy state." << endl;
}

void Happy::MakeNeutral(Group *group)
{
    group->SetState(new Neutral());
}

void Happy::RequestTab(Group *group)
{
    cout << "Cannot request a tab when seated." << endl;
}

void Happy::RequestBill(Group *group)
{
    group->SetState(new ReadyForBill());
    group->notify();
}

string Happy::ToString()
{
    return this->stateName_;
}