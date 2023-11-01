#include "ReadyForBill.h"
#include "Happy.h"
#include "Unhappy.h"

ReadyForBill::ReadyForBill()
{
    stateName_ = "ReadyForBill";
    cout << "State changed to " << stateName_ << endl;
}

ReadyForBill::~ReadyForBill()
{
}

void ReadyForBill::RequestToOrder(Group *group)
{
    cout << "Cannot order more items after the bill was received." << endl;
}

void ReadyForBill::WaitInQueue(Group *group)
{
    cout << "Cannot move back to the queue." << endl;
}

void ReadyForBill::MakeUnhappy(Group *group)
{
    group->SetState(new Unhappy());
}

void ReadyForBill::MakeHappy(Group *group)
{
    group->SetState(new Happy());
}

void ReadyForBill::RequestTab(Group *group)
{
    cout << "Cannot request for a tab when seated." << endl;
}

void ReadyForBill::RequestBill(Group *group)
{
    cout << "Currently in the ReadyForBill state." << endl;
}

string ReadyForBill::ToString()
{
    return this->stateName_;
}
