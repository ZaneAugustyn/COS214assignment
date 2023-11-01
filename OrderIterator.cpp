#include "OrderIterator.h"

OrderIterator::OrderIterator(Order* order) : order(order) {}

OrderIterator::~OrderIterator() {}

Order* OrderIterator::next()
{
    return order->getNextComponent();
}

bool OrderIterator::isDone()
{
    return order->isDone();
}

Order* OrderIterator::currentItem()
{
    return order->getCurrentComponent();
}
