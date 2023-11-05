#include "ReadyToOrder.h"
#include "Happy.h"
#include "Unhappy.h"
#include "ReadyForBill.h"
#include "Neutral.h"

ReadyToOrder::ReadyToOrder()
{
    stateName_ = "ReadyToOrder";
    cout << "State changed to " << stateName_ << endl;
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
    group->updateLastEmotion(new Unhappy());
}

void ReadyToOrder::MakeHappy(Group *group)
{
    // cout << "in ReadyToOrder: Move to Happy State." << endl;
    group->SetState(new Happy());
    group->updateLastEmotion(new Happy());
}

void ReadyToOrder::MakeNeutral(Group * group)
{
    group->SetState(new Neutral());
    group->updateLastEmotion(new Neutral());
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
