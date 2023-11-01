#include "Order.h"
#include "Group.h"
#include "OrderItem.h"
#include "Waiter.h"

#include <algorithm>

Order::Order(Group *group)
{

  group_ = group;
}

Order::~Order()
{

  for (OrderComponent *component : components_)
  {
      delete component;
  }
}

double Order::getPrice()
{

  double totalPrice = 0;

  for (OrderComponent *component : components_)
  {
      totalPrice += component->getPrice();
  }

  return totalPrice;
}

void Order::addComponent(OrderComponent *component)
{
  // Notify the head chef that a order was added
  Waiter* orderWaiter = this->group_->getWaiter();
  orderWaiter->changed();
  components_.push_back(component);
}

void Order::removeComponent(OrderComponent *component)
{

  components_.erase(remove(components_.begin(), components_.end(), component), components_.end());
}

GroupIterator *Order::createIterator()
{
  return new GroupIterator();
}

Order *Order::getNextComponent()
{

  if (currentComponentIndex_ < components_.size())
  {
      return dynamic_cast<Order *>(components_[currentComponentIndex_++]);
  }
  return nullptr;
}

bool Order::isDone()
{

  return currentComponentIndex_ >= components_.size();
}

Order *Order::getCurrentComponent()
{

  if (currentComponentIndex_ < components_.size())
  {
      return dynamic_cast<Order *>(components_[currentComponentIndex_]);
  }
  return nullptr;
}

std::vector<OrderComponent *> Order::getItems()
{

  vector<OrderComponent *> items;
  for (OrderComponent *component : components_)
  {
      if (dynamic_cast<OrderItem *>(component))
      {
          items.push_back(component);
      }
  }
  return items;
}

int Order::getGroupNumber()
{

  return group_->getGroupNumber();
}