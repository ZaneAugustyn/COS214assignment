#ifndef _ORDER_H
#define _ORDER_H

#include <vector>

#include "OrderComponent.h" // Forward declaration
class Group;

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