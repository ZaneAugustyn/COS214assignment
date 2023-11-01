#include "Patty.h"

Patty::Patty(bool grilled, double price, string name):OrderItem(price, name)
{
    grilled_ = grilled;
}

Patty::~Patty()
{
}
