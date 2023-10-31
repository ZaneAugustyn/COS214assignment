#include "HeadChef.h"

HeadChef::HeadChef(/* args */)
{

}

void HeadChef::changed()
{
  // TO DO: mediator
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
  // if order is not empty
    // Chef::heandleOrder(plate);
  // if order is empty 
    // cout << "The Head Chef garnishes the plate and adds it to the tray" << endl;
    // addToTray(plate);   
}

void HeadChef::addToTray(Plate* plate)
{
    tray_.push_back(plate);
}

HeadChef::~HeadChef()
{

}