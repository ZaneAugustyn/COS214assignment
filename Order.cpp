#include "Order.h"
#include "Group.h"
#include "OrderItem.h"
#include "Waiter.h"
#include "ItemIterator.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>

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

float Order::GetPrice()
{

  float totalPrice = 0;

  for (OrderComponent *component : components_)
  {
      totalPrice += component->GetPrice();
  }

  return totalPrice;
}

void Order::AddComponent(OrderComponent *component)
{
  components_.push_back(component);
}

void Order::RemoveComponent(OrderComponent *component)
{

  components_.erase(remove(components_.begin(), components_.end(), component), components_.end());
}

GroupIterator* Order::CreateIterator()
{
  return new GroupIterator(this);
}

std::vector<OrderComponent *> Order::GetItems()
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

int Order::GetGroupNumber()
{

  return group_->GetGroupNumber();
}

Group* Order::GetGroup()
{
  return this->group_;
}

string Order::FormatOrder(LanguageTarget* lt, char lang)
{
  string formattedOrder = "";
  int counter = 1;

  ItemIterator* iterator = new ItemIterator(components_);

  while(!iterator->IsDone()){

    OrderItem* currentItem = dynamic_cast<OrderItem *>(iterator->CurrentItem());
    lt->SetOrderItems(currentItem);

    std::ostringstream formattedStream;
    
    string item = to_string(counter) + ". " + lt->GetOrderItemInLanguage(lang);

    formattedStream << left << setfill('.') << setw(20) << item << right << setfill('.') << setw(20) << currentItem->GetPrice()  << endl;
    formattedOrder += formattedStream.str();

    counter++;
    iterator->Next();
  }

  return formattedOrder;
}