#include "WaitForTable.h"
#include "ReadyToOrder.h"
#include "Happy.h"
#include "Unhappy.h"
#include "PayTab.h"

WaitForTable::WaitForTable()
{
    stateName_ = "WaitForTable";
    cout << "New State: " << stateName_ << endl;
}

WaitForTable::~WaitForTable()
{
}

void WaitForTable::RequestToOrder(Group *group)
{
    group->SetState(new ReadyToOrder());
}

void WaitForTable::WaitInQueue(Group *group)
{
    cout << "Currently in the WaitForTable state." << endl;
}

void WaitForTable::MakeUnhappy(Group *group)
{
    group->SetState(new Unhappy());
}

void WaitForTable::MakeHappy(Group *group)
{
    group->SetState(new Happy());
}

void WaitForTable::RequestTab(Group *group)
{
    group->SetState(new PayTab());
}

void WaitForTable::RequestBill(Group *group)
{
    cout << "Cannot request the bill while in the queue." << endl;
}

string WaitForTable::ToString()
{
    return this->stateName_;
}
