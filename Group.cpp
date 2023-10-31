#include "Group.h"

Group::Group(/* args */)
{
}

void Group::addWaiter(Waiter* waiter)
{
  this->waiter_ = waiter;
}

Waiter* Group::getWaiter()
{
  return this->waiter_;
}

Group::~Group()
{
}
