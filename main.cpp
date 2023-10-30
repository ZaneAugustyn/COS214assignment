#include "OrderComponent.h"
#include "Order.h"
#include "OrderItem.h"
#include "Group.h"

#include <iostream>

using namespace std;

int main(){

    //Create a group for Bob's Birthday
    Group* bobsBirthday = new Group();

    //Create an order for the group
    Order* bobsBirthdayOrder = new Order(bobsBirthday);

    //First get Bob's order
    Order* bobsOrder = new Order(bobsBirthday);
    bobsOrder->addComponent(new OrderItem(10));

    //Then get Alice's order
    Order* alicesOrder = new Order(bobsBirthday);
    alicesOrder->addComponent(new OrderItem(20));

    //Add both orders to the group's order
    bobsBirthdayOrder->addComponent(bobsOrder);
    bobsBirthdayOrder->addComponent(alicesOrder);

    //Print out the total cost of the order, should be 30
    cout << bobsBirthdayOrder->getPrice() << endl;

    //Remove alicesOrder
    bobsBirthdayOrder->removeComponent(alicesOrder);

    //Print out the total cost of the order, should be 10
    cout << bobsBirthdayOrder->getPrice() << endl;

    delete bobsBirthdayOrder;
    delete alicesOrder;
    delete bobsBirthday;

}