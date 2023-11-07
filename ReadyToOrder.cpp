#include "ReadyToOrder.h"
#include "Happy.h"
#include "Unhappy.h"
#include "ReadyForBill.h"
#include "Neutral.h"

ReadyToOrder::ReadyToOrder()
{
    stateName_ = "ReadyToOrder";
    cout << "Group state changed to " << stateName_ << endl;
}

ReadyToOrder::~ReadyToOrder()
{
}

void ReadyToOrder::RequestToOrder(Group *group) 
{
    cout << "Group has already ordered." << endl;
}

void ReadyToOrder::WaitInQueue(Group *group)
{
    cout << "Cannot move to WaitForTable state." << endl;
}

void ReadyToOrder::RequestTab(Group *group)
{
    cout << "Cannot request a tab when seated." << endl;
}

void ReadyToOrder::RequestBill(Group *group)
{
    group->SetState(new ReadyForBill());
    group->notify();
}

string ReadyToOrder::ToString()
{
    return this->stateName_;
}
