#include "Group.h"
#include "Waiter.h"

Group::Group(int groupNumber) : groupNumber_(groupNumber)
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

int Group::getGroupNumber()
{
  return this->groupNumber_;
}