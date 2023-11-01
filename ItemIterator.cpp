#include "ItemIterator.h"
#include "Order.h"
#include "OrderComponent.h"

ItemIterator::ItemIterator()
{

}

ItemIterator::ItemIterator(vector<OrderComponent*> items_)
    : items_(items_), currentIndex_(0) {}

OrderComponent* ItemIterator::next() {
    if (!isDone()) {
        return items_[currentIndex_++];
    }
    return nullptr;
}

bool ItemIterator::isDone() {
    return currentIndex_ >= items_.size();
}

void ItemIterator::setOrderComponents(vector<OrderComponent*> items_)
{
    this->items_ = items_;
}

OrderComponent* ItemIterator::currentItem() {
    if (!isDone()) {
        return items_[currentIndex_];
    }
    return nullptr;
}
