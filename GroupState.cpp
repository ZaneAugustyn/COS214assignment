#include "Group.h"
#include "GroupState.h"

Group::Group(GroupState * state, int groupNumber)
{
    groupState_ = state;
    groupNumber_ = groupNumber;
}

Group::~Group()
{
}

void Group::SetWaiter(Waiter *waiter)
{
    this->waiter_ = waiter;
}

void Group::SetState(GroupState *state)
{
    delete groupState_;
    groupState_ = state;
}

void Group::RequestToOrder()
{
    if (waiter_ == NULL) {
        cout << "Can't order when waiting in the queue." << endl;
        return;
    }
    groupState_->RequestToOrder(this);
}

void Group::WaitInQueue()
{
    if (waiter_ != NULL) {
        cout << "Can't go back to the queue once seated." << endl;
        return;
    }
    groupState_->WaitInQueue(this);
}

void Group::MakeUnhappy()
{
    if (waiter_ == NULL) {
        cout << "Can't have Unhappy state when in the queue." << endl;
        return;
    }
    groupState_->MakeUnhappy(this);
}

void Group::MakeHappy()
{
    if (waiter_ == NULL) {
        cout << "Can't have Happy state when in the queue." << endl;
        return;
    }
    groupState_->MakeHappy(this);
}

void Group::RequestTab()
{
    if (waiter_ !=  NULL) {
        cout << "Can't request a tab when seated at a table." << endl;
        return;
    }
    groupState_->RequestTab(this);
}

void Group::RequestBill()
{
    if (waiter_ == NULL) {
        cout << "Can't request a bill when waiting in the queue." << endl;
        return;
    }
    groupState_->RequestBill(this);
}

int Group::GetGroupNumber()
{
    return groupNumber_;
}

GroupState *Group::GetState()
{
    return this->groupState_;
}

string Group::CurrentState()
{
    string ret = "Group " + to_string(this->groupNumber_);
    ret += "\n\tCurrent State: " + this->GetState()->ToString();
    return ret;
}
