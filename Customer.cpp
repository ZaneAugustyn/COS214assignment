#include "Customer.h"

Customer::Customer(string name):name_(name)
{
}

Customer::~Customer()
{
}

Tab* Customer::getTab()
{
    return this->tab_;
}

void Customer::setTab(Tab* tab)
{
    this->tab_ = tab;
}

string Customer::getName()
{
    return this->name_;
}
