#include "GarnishChef.h"
#include <iostream>
using namespace std;

GarnishChef::GarnishChef(/* args */)
{
}

GarnishChef::~GarnishChef()
{
}

void GarnishChef::HandleOrder(Plate* plate)
{
    // iterate over the order to find the garnish
    // remove the garnish from the order
    // add the garnish to the plate
    cout << "The Garnish Chef has added the garnish to the plate" << endl;
    Chef::HandleOrder(plate);
}