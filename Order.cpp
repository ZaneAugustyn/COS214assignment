#include "Order.h"
#include "Group.h"
#include "OrderItem.h"
#include "Waiter.h"
#include "ItemIterator.h"
#include <cmath>


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
  components_.push_back(component);
}

void Order::removeComponent(OrderComponent *component)
{

  components_.erase(remove(components_.begin(), components_.end(), component), components_.end());
}

GroupIterator* Order::createIterator()
{
  return new GroupIterator(this);
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

Group* Order::getGroup()
{
  return this->group_;
}

string Order::formatOrder(LanguageTarget* lt, char lang)
{
  string formattedOrder = "";
  int counter = 1;

  ItemIterator* iterator = new ItemIterator(components_);

  while(!iterator->isDone()){
    OrderItem* currentItem = dynamic_cast<OrderItem *>(iterator->currentItem());
    lt->setOrderItems(currentItem);
    formattedOrder += to_string(counter) + " " + lt->getOrderItemInLanguage(lang) + "\t\t\tR" + to_string(trunc(currentItem->getPrice())) + ".00\n";
    counter++;
    iterator->next();
  }

  return formattedOrder;

}