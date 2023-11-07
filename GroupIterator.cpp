#include "GroupIterator.h"
#include "Order.h"

GroupIterator::GroupIterator() : order_(nullptr), current_position(0) {}

GroupIterator::GroupIterator(Order* order) : order_(order), current_position(0) {}

GroupIterator::~GroupIterator() {}

Order* GroupIterator::next() {
    if (current_position < order_->components_.size()) {
        Order* nextComponent = dynamic_cast<Order*>(order_->components_[current_position]);
        current_position++; 
        return nextComponent;
    }
    return nullptr; 
}

bool GroupIterator::isDone() {
    return current_position >= order_->components_.size();
}

Order* GroupIterator::currentItem() {
    if (current_position < order_->components_.size()) {
        return dynamic_cast<Order*>(order_->components_[current_position]);
    }
    return nullptr;
}

void GroupIterator::setOrder(Order* o) {
    order_ = o;
    current_position = 0;  // Reset the current position when setting a new Order for iteration.
}
