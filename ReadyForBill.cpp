#include "ReadyForBill.h"
#include "Happy.h"
#include "Unhappy.h"
#include "Neutral.h"

ReadyForBill::ReadyForBill()
{
    stateName_ = "ReadyForBill";
    cout << "Group state changed to " << stateName_ << endl;
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

void ReadyForBill::RequestTab(Group *group)
{
    cout << "Cannot request for a tab when seated." << endl;
}

void ReadyForBill::RequestBill(Group *group)
{
    cout << "Group has already paid their bill." << endl;
}

string ReadyForBill::ToString()
{
    return this->stateName_;
}
