#include "HeadChef.h"
#include "Plate.h"

HeadChef::HeadChef(/* args */)
{

}

void HeadChef::handleOrder(Plate* plate)
{
  // TO DO: chain of responsibility
  // if order is not empty
    // cout << "The Head Chef adds the bun to the plate"
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