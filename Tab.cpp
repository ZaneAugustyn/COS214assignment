#include "Tab.h"

Tab::Tab(float amount): TotalAmountOwed_(amount)
{
}

Tab::~Tab()
{
}

float Tab::GetAmount() const
{
    return this->TotalAmountOwed_;
}