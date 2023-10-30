#ifndef _ORDER_H
#define _ORDER_H

#include "OrderComponent.h"
#include "Group.h"

#include <vector>

using namespace std;

class Order : public OrderComponent
{
private:
    Group* group_;
    vector<OrderComponent*> components_;
public:
    Order(Group* group);
    ~Order();
    double getPrice();
    void addComponent(OrderComponent* component);
    void removeComponent(OrderComponent* component);
};

#endif