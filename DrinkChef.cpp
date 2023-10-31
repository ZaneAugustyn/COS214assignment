#include "DrinkChef.h"
#include <iostream>
using namespace std;

DrinkChef::DrinkChef(/* args */)
{
}

DrinkChef::~DrinkChef()
{
}

void DrinkChef::HandleOrder(Plate* plate)
{
    // iterate over the order to find the drink
    // remove the drink from the order
    // add the drink to the plate
    cout << "The Drink Chef has added the drink to the plate" << endl;
    Chef::HandleOrder(plate);
}
