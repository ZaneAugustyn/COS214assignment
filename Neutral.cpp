#include "Neutral.h"
#include "Happy.h"
#include "ReadyToOrder.h"
#include "Unhappy.h"
#include "ReadyForBill.h"

Neutral::Neutral()
{
    stateName_ = "Neutral";
}

Neutral::~Neutral()
{
}

void Neutral::RequestToOrder(Group *group)
{
    group->SetState(new ReadyToOrder());
}

void Neutral::WaitInQueue(Group *group)
{
    cout << "Cannot move to WaitForTable state." << endl;
}

void Neutral::MakeUnhappy(Group *group)
{
    group->SetState(new Unhappy());
}

void Neutral::MakeHappy(Group * group) 
{
    group->SetState(new Happy());
}

void Neutral::MakeNeutral(Group *group)
{
    cout << "Already in Neutral state." << endl;
}

void Neutral::RequestTab(Group *group)
{
    cout << "Cannot request a tab when seated." << endl;
}

void Neutral::RequestBill(Group *group)
{
    group->SetState(new ReadyForBill());
}

string Neutral::ToString()
{
    return this->stateName_;
}
