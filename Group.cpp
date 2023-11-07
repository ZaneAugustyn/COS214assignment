#include "Group.h"
#include "GroupState.h"
#include "Unhappy.h"
#include "Happy.h"
#include "Neutral.h"
#include "Waiter.h"
#include "Bill.h"
#include "Neutral.h"

Group::Group(GroupState * state, int groupNumber)
{
    groupState_ = state;
    groupNumber_ = groupNumber;
    lastEmotion_ = new Neutral();
}

Group::~Group()
{
}


void Group::SetState(GroupState *state)
{
    delete groupState_;
    groupState_ = state;

}

void Group::setLastEmotion(EmotionalState *state)
{
    delete lastEmotion_;
    lastEmotion_ = state;
    cout<<"Group emotion changed to "<<lastEmotion_->ToString()<<endl;

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
    lastEmotion_->MakeUnhappy(this);
    lastEmotion_ = new Unhappy();
}

void Group::MakeHappy()
{
    if (waiter_ == NULL) {
        cout << "Can't have Happy state when in the queue." << endl;
        return;
    }
    lastEmotion_->MakeHappy(this);
    lastEmotion_ = new Happy();
}

void Group::MakeNeutral()
{
    if (waiter_ == NULL) {
        cout << "Can't have Happy state when in the queue." << endl;
        return;
    }
    lastEmotion_->MakeNeutral(this);
    lastEmotion_ = new Neutral();
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

int Group::getGroupNumber()
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

void Group::addWaiter(Waiter* waiter)
{
    waiter_ = waiter;
    cout<<"Group has been assigned "<<waiter->getName()<<" as their waiter."<<endl;
}

void Group::removeWaiter(Waiter* waiter)
{
    cout<<"Group has removed "<<waiter->getName()<<" as their waiter."<<endl;
    waiter_ = nullptr;
}
    
void Group::notify()
{
    waiter_->update(this);
}

void Group::setBill(Bill* bill){

    bill_ = bill;

}

Bill* Group::getBill(){

    return bill_;

}

Customer* Group::getFirstCustomer(){
    if(customers_.size() > 0){
        Customer* customer = this->customers_[0];
        if (customer != NULL)
            return customer;
    }
    return NULL;
}

Waiter* Group::getWaiter(){
    return waiter_;
}

EmotionalState* Group::getLastEmotion()
{
    return this->lastEmotion_;
}