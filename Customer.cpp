#include "Customer.h"

Customer::Customer(/* args */)
{
}

Customer::~Customer()
{
}

Tab* Customer::getTab()
{
    return this->tab;
}

void Customer::setTab(Tab* tab)
{
    this->tab = tab;
}
