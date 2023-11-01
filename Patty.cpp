#include "Patty.h"

Patty::Patty(bool grilled, double price, string name):OrderItem(price, name)
{
    grilled_ = grilled;
}

bool Patty::getGrilledStatus()
{
    return this->grilled_;
}

Patty::~Patty()
{
}
