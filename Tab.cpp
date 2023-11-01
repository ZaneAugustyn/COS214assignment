#include "Tab.h"

Tab::Tab(float amount): TotalAmountOwed(amount)
{
}

Tab::~Tab()
{
}

float Tab::getAmount() const
{
    return this->TotalAmountOwed;
}