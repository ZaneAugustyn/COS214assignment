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
    cout << "Group state changed to " << stateName_ << endl;
}

WaitForTable::~WaitForTable()
{
}

void WaitForTable::RequestToOrder(Group *group)
{
    group->SetState(new ReadyToOrder());
    group->Notify();
}

void WaitForTable::WaitInQueue(Group *group)
{
    cout << "Currently in the WaitForTable state." << endl;
}

void WaitForTable::RequestTab(Group *group)
{
    group->SetState(new PayTab());
    group->Notify();
}

void WaitForTable::RequestBill(Group *group)
{
    cout << "Cannot request the bill before having ordered." << endl;
}

string WaitForTable::ToString()
{
    return this->stateName_;
}
