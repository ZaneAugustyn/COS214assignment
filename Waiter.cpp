#include "Waiter.h"
#include "Pass.h"
#include "Group.h"
#include "BillPayment.h"
#include "Order.h"
#include "Patty.h"
#include "BeefPatty.h"
#include "ChickenPatty.h"
#include "Side.h"
#include "Salad.h"
#include "Chips.h"
#include "Drink.h"
#include "Milkshake.h"
#include "Soda.h"
#include "Garnish.h"
#include "Lettuce.h"
#include "Tomato.h"
#include <iostream>

Waiter::Waiter(std::string n)
{
    this->name_ = n;

        this->menu_ = new Order(NULL);

    //meats
    Order* meats = new Order(NULL);
    meats->addComponent(new ChickenPatty(true));
    meats->addComponent(new BeefPatty());

    //sides
    Order* sides = new Order(NULL);
    sides->addComponent(new Chips());
    sides->addComponent(new Salad());

    //garnish
    Order* garnish = new Order(NULL);
    garnish->addComponent(new Lettuce());
    garnish->addComponent(new Tomato());

    //drinks
    Order* drinks = new Order(NULL);
    drinks->addComponent(new Milkshake());
    drinks->addComponent(new Soda());

    this->menu_->addComponent(meats);
    this->menu_->addComponent(sides);
    this->menu_->addComponent(garnish);
    this->menu_->addComponent(drinks);

}

void Waiter::changed()
{
    this->pass_->notifyHeadChef(this);
}

Waiter::~Waiter()
{

}

std::string Waiter::getName()
{
    return name_;
}

void Waiter::update(Group* group)
{
    std::cout<<getName()<<" has been notified"<<std::endl;

    if(group->GetState()->ToString() == "WaitForTable"){
        return;
    }
    else if(group->GetState()->ToString() == "ReadyToOrder"){
        //display menu to customers and get order
        //create an order with the group pointer 
        //Iterate over all customers so that each gives an order
        //and take it to the kitchen
    }
    else if(group->GetState()->ToString() == "ReadyForBill"){
        //the waiter will take the group bill and display it
        cout << "You have to pay R " << group->getBill()->getTotal() << endl;
        cout << "How would you like to pay it? 'S' to split, 'F' to pay in full, 'T' to put it on a tab" << endl;
        char c;
        // TODO: need to check inputs
        cin >> c;
        // Assume we take the first customer in the group if they want to make a bill
        //**********Check group last emotion for tip.*********************
        
        if(group != NULL)
        {
            group->getBill()->Pay(group,c);
        }
        else
        {
            cout << "There are no customers in this group to pay for the bill" << endl;
        }
        //**********Xadrian please help here.
        //and ask the group how they want to pay it
        //the waiter will then initiate the payment process
    }
    else if(group->GetState()->ToString() == "PayTab"){

    }
    
}

// void Waiter::addGroup(Group* group)
// {
//   if(group == nullptr)
//     {
//         return;
//     }

//     myGroups.push_back(group);
// }

// void Waiter::removeGroup(Group* group)
// {
//   if(group != nullptr)
//     {
//         for (auto it = myGroups.begin(); it != myGroups.end(); ++it) {
//                 if (*it == group) {
//                     // Remove the element from the vector
//                     myGroups.erase(it);
//                     break;  // Break to avoid further unnecessary iterations
//                 }
//             }
//     }
// }
