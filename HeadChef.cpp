#include "HeadChef.h"

HeadChef::HeadChef(/* args */)
{

}

void HeadChef::changed()
{
  // TO DO: mediator

  this->pass_.notifyWaiter(this);
}

Pass* HeadChef::get()
{
  // TO DO: mediator
}

void HeadChef::set(Pass* pass)
{
  // TO DO: mediator
}

void HeadChef::handleOrder(Plate* plate)
{
  // TO DO: chain of responsibility
}

void HeadChef::addToTray(Plate* plate)
{

}

HeadChef::~HeadChef()
{

}
