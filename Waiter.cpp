#include "Waiter.h"

Waiter::Waiter(/* args */)
{

}

void Waiter::changed()
{
  // TO DO: mediator
  this->pass_.notifyHeadChef(this);
}

Pass* Waiter::get()
{
// TO DO: mediator
}
void Waiter::set(Pass* pass)
{
// TO DO: mediator
}

Waiter::~Waiter()
{

}
