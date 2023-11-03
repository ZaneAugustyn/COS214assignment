#include "Unhappy.h"
#include "ReadyToOrder.h"
#include "Happy.h"
#include "ReadyForBill.h"

Unhappy::Unhappy()
{
    stateName_ = "Unhappy";
    cout << "State changed to " << stateName_ << endl;
}

Unhappy::~Unhappy()
{
}

void Unhappy::RequestToOrder(Group *group)
{
    group->SetState(new ReadyToOrder());
    group->notify();
}

void Unhappy::WaitInQueue(Group *group)
{
    cout << "Cannot move to WaitForTable state." << endl;
}

void Unhappy::MakeUnhappy(Group *group)
{
    cout << "Currently in the Unhappy state" << endl;
}

void Unhappy::MakeHappy(Group *group)
{
    group->SetState(new Happy());
}

void Unhappy::RequestTab(Group *group)
{
    cout << "Cannot request a tab when seated." << endl;
}

void Unhappy::RequestBill(Group *group)
{
    group->SetState(new ReadyForBill());
    group->notify();
}

string Unhappy::ToString()
{
    return this->stateName_;
}
