#include "ItemIterator.h"
#include "Order.h"
#include "OrderComponent.h"

ItemIterator::ItemIterator()
{

}

ItemIterator::ItemIterator(vector<OrderComponent*> items_)
    : items_(items_), currentIndex_(0) {}

OrderComponent* ItemIterator::Next() {
    if (!IsDone()) {
        int current = currentIndex_;
        ++currentIndex_;
        return items_[current];
    }
    return nullptr;
}

bool ItemIterator::IsDone() {
    return currentIndex_ >= items_.size();
}

void ItemIterator::SetOrderComponents(vector<OrderComponent*> items_)
{
    this->items_ = items_;
}

OrderComponent* ItemIterator::CurrentItem() {
    if (!IsDone()) {
        return items_[currentIndex_];
    }
    return nullptr;
}
