#include "Order.h"
#include "OrderIterator.h" 
#include "OrderComponent.h"
#include <algorithm>
#include "ItemIterator.h"
Order::Order(Group* group)
{

    group_ = group;

}

Order::~Order()
{

    for(OrderComponent* component : components_){
        delete component;
    }

}

double Order::getPrice()
{

    double totalPrice = 0;

    for(OrderComponent* component : components_){
        totalPrice += component->getPrice();
    }

    return totalPrice;

}

void Order::addComponent(OrderComponent* component)
{

    components_.push_back(component);

}

void Order::removeComponent(OrderComponent* component)
{

    components_.erase(remove(components_.begin(), components_.end(), component), components_.end());

}
Iterator* Order::createIterator()
{

    return new OrderIterator(this);

}

Order* Order::getNextComponent()
{

    if (currentComponentIndex_ < components_.size())
    {
        return dynamic_cast<Order*>(components_[currentComponentIndex_++]);
    }
    return nullptr;

}

bool Order::isDone()
{

    return currentComponentIndex_ >= components_.size();

}

Order* Order::getCurrentComponent()
{

    if (currentComponentIndex_ < components_.size())
    {
        return dynamic_cast<Order*>(components_[currentComponentIndex_]);
    }
    return nullptr;

}
IteratorItems* Order::createItemIterator() {

    vector<OrderComponent*> items = getItems();
    return new ItemIterator(items);

}
std::vector<OrderComponent*> Order::getItems()
{

   vector<OrderComponent*> items;
        for (OrderComponent* component : components_)
        {
            if (dynamic_cast<OrderItem*>(component))
            {
                items.push_back(component);
            }
        }
        return items;
        
}