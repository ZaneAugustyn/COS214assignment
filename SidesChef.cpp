#include "SidesChef.h"
#include <iostream>
using namespace std;

SidesChef::SidesChef()
{
}

SidesChef::~SidesChef()
{
}

void SidesChef::HandleOrder(Plate* plate)
{
    // iterate over the order to find the side
    // remove the side from the order
    // add the side to the plate
    cout << "The Side Chef has added the side to the plate" << endl;
    Chef::HandleOrder(plate);
}
