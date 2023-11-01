#include "Waiter.h"
#include "Pass.h"

Waiter::Waiter(/* args */)
{

}

void Waiter::changed()
{
  // TO DO: mediator
  this->pass_->notifyHeadChef(this);
}

Waiter::~Waiter()
{

}
