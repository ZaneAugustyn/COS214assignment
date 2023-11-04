#include "Tab.h"

Tab::Tab(float amount): TotalAmountOwed_(amount)
{
}

Tab::~Tab()
{
}

float Tab::getAmount() const
{
    return this->TotalAmountOwed_;
}