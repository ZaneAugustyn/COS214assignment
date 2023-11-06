#include "PayTab.h"

PayTab::PayTab()
{
    stateName_ = "PayTab";
    cout << "Group state changed to " << stateName_ << endl;
}

PayTab::~PayTab()
{
}

void PayTab::RequestToOrder(Group *group)
{
    cout << "Cannot change state to ReadyToOrder." << endl;
}

void PayTab::WaitInQueue(Group *group)
{
    cout << "Cannot change state to WaitForTable." << endl;
}

void PayTab::MakeUnhappy(Group *group)
{
    cout << "Cannot change state to Unhappy." << endl;
}

void PayTab::MakeHappy(Group *group)
{
    cout << "Cannot change state to Happy." << endl;
}

void PayTab::RequestTab(Group *group)
{
    cout << "Currently in the PayTab state." << endl;
}

void PayTab::MakeNeutral(Group *group)
{
    cout << "Cannot change state to Neutral." << endl;
}

void PayTab::RequestBill(Group *group)
{
    cout << "Cannot request a bill - have to pay tab." << endl;
}

string PayTab::ToString()
{
    return this->stateName_;
}
