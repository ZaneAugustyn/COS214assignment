#ifndef _ORDER_H
#define _ORDER_H

#include "OrderComponent.h"
#include "GroupIterator.h"

class Group;
class OrderItem;
class Waiter;

#include <vector>

using namespace std;

class Order : public OrderComponent {
private:
    Group* group_;
    vector<OrderComponent*> components_;
    int currentComponentIndex_;
    friend class GroupIterator;
public:
    Order(Group* group);
    ~Order();
    double getPrice();
    void addComponent(OrderComponent* component);
    void removeComponent(OrderComponent* component);
    virtual vector<OrderComponent*> getItems();
    GroupIterator* createIterator();
    // Order* getNextComponent();
    // bool isDone();
    // Order* getCurrentComponent();
    int getGroupNumber();
    Group* getGroup();
    
};

#endif