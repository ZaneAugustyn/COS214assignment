#include "ReadyToOrder.h"
#include "Happy.h"
#include "Unhappy.h"

ReadyToOrder::ReadyToOrder()
{
    stateName_ = "ReadyToOrder";
    cout << "New State: " << stateName_ << endl;
}

ReadyToOrder::~ReadyToOrder()
{
}

void ReadyToOrder::RequestToOrder(Group *group) 
{
    cout << "Currently in ReadyToOrder state." << endl;
}

void ReadyToOrder::WaitInQueue(Group *group)
{
    cout << "Cannot move to WaitForTable state." << endl;
}

void ReadyToOrder::MakeUnhappy(Group *group)
{
    // cout << "Move to Unhappy State." << endl;
    group->SetState(new Unhappy());
}

void ReadyToOrder::MakeHappy(Group *group)
{
    // cout << "in ReadyToOrder: Move to Happy State." << endl;
    group->SetState(new Happy());
}

void ReadyToOrder::RequestTab(Group *group)
{
    cout << "Cannot request a tab when seated." << endl;
}

void ReadyToOrder::RequestBill(Group *group)
{
    cout << "Move to ReadyForBill State." << endl;
}

string ReadyToOrder::ToString()
{
    return this->stateName_;
}
