#include "GroupIterator.h"
#include "Order.h"

GroupIterator::GroupIterator() : order_(nullptr), current_position_(0) {}

GroupIterator::GroupIterator(Order* order) : order_(order), current_position_(0) {}

GroupIterator::~GroupIterator() {}

Order* GroupIterator::Next() {
    if (current_position_ < order_->components_.size()) {
        Order* nextComponent = dynamic_cast<Order*>(order_->components_[current_position_]);
        ++current_position_;
        return nextComponent;
    }
    return nullptr; 
}

bool GroupIterator::IsDone() {
    return current_position_ >= order_->components_.size();
}

Order* GroupIterator::CurrentItem() {
    if (current_position_ < order_->components_.size()) {
        return dynamic_cast<Order*>(order_->components_[current_position_]);
    }
    return nullptr;
}

void GroupIterator::SetOrder(Order* o) {
    order_ = o;
    current_position_ = 0;  // Reset the current position when setting a new Order for iteration.
}
