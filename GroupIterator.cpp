#include "GroupIterator.h"
#include "Order.h"

GroupIterator::GroupIterator()
{

}

GroupIterator::GroupIterator(Order* order) : order_(order) {}

GroupIterator::~GroupIterator() {}

Order* GroupIterator::next()
{
    return order_->getNextComponent();
}

bool GroupIterator::isDone()
{
    return order_->isDone();
}

Order* GroupIterator::currentItem()
{
    return order_->getCurrentComponent();
}

void GroupIterator::setOrder(Order* o)
{
    this->order_ = o;
}
