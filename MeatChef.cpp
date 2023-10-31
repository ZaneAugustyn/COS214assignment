#include "MeatChef.h"
#include <iostream>
using namespace std;

MeatChef::MeatChef(/* args */)
{
}

MeatChef::~MeatChef()
{
}

void MeatChef::HandleOrder(Plate* plate)
{
    // iterate over the order to find the meet
        // check preparation method
    // remove the meat from the order
    // add the meat to the plate
    cout << "The Meat Chef has added the meat to the plate" << endl;
    Chef::handleOrder(plate);
}

