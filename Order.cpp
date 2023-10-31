#include <Order.h>

#include <algorithm>

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