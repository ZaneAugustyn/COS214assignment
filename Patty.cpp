#include "Patty.h"

Patty::Patty(bool grilled, double price, string name):OrderItem(price, name)
{
    grilled_ = grilled;
}

bool Patty::GetGrilledStatus()
{
    return this->grilled_;
}

Patty::~Patty()
{
}
