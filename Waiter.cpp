#include "Waiter.h"
#include "Pass.h"
#include "Group.h"
#include "BillPayment.h"
#include <iostream>

Waiter::Waiter(std::string n)
{
    this->name_ = n;
}

void Waiter::changed()
{
  // TO DO: mediator
  //this->pass_->notifyHeadChef(this);
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
    else if(group->GetState()->ToString() == "Happy"){//*************************************************

    }
    else if(group->GetState()->ToString() == "Unhappy"){//*************************************************

    }
    else if(group->GetState()->ToString() == "ReadyForBill"){
        //the waiter will take the group bill and display it
        cout << "You have to pay R " << group->getBill()->getTotal() << endl;
        cout << "How would you like to pay it? 'S' to split, 'F' to pay in full, 'T' to put it on a tab" << endl;
        char c;
        // TODO: need to check inputs
        cin >> c;
        // Assume we take the first customer in the group if they want to make a bill
        Customer* customer = group->getFirstCustomer();
        if(customer != NULL)
        {
            group->getBill()->Pay(customer,c);
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
