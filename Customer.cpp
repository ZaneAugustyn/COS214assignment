#include "Customer.h"

Customer::Customer(string name):name_(name)
{
}

Customer::~Customer()
{
}

Tab* Customer::GetTab()
{
    return this->tab_;
}

void Customer::SetTab(Tab* tab)
{
    this->tab_ = tab;
}

string Customer::GetName()
{
    return this->name_;
}
