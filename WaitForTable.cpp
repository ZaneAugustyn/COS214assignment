#include "WaitForTable.h"
#include "ReadyToOrder.h"
#include "Happy.h"
#include "Unhappy.h"
#include "PayTab.h"
#include "Neutral.h"
#include "GroupState.h"

WaitForTable::WaitForTable()
{
    stateName_ = "WaitForTable";
    cout << "State changed to " << stateName_ << endl;
}

WaitForTable::~WaitForTable()
{
}

void WaitForTable::RequestToOrder(Group *group)
{
    group->SetState(new ReadyToOrder());
    group->notify();
}

void WaitForTable::WaitInQueue(Group *group)
{
    cout << "Currently in the WaitForTable state." << endl;
}

void WaitForTable::MakeUnhappy(Group *group)
{
    group->SetState(new Unhappy());
    group->updateLastEmotion(new Unhappy());
}

void WaitForTable::MakeNeutral(Group *group)
{
    group->SetState(new Neutral());
    group->updateLastEmotion(new Neutral());
}

void WaitForTable::MakeHappy(Group *group)
{
    group->SetState(new Happy());
    group->updateLastEmotion(new Happy());
}

void WaitForTable::RequestTab(Group *group)
{
    group->SetState(new PayTab());
    group->notify();
}

void WaitForTable::RequestBill(Group *group)
{
    cout << "Cannot request the bill while in the queue." << endl;
}

string WaitForTable::ToString()
{
    return this->stateName_;
}
