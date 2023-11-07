#include "Chef.h"
#include "Plate.h"
#include "Pass.h"
#include "Order.h"
#include "OrderComponent.h"
#include "OrderItem.h"
#include "Group.h"
#include "Waiter.h"

#include <iostream>
using namespace std;

Chef::Chef()
{
  cout << "Chef Created" << endl;
}

Chef::Chef(Pass* p)
{
  this->pass_ = p;
}

Chef::~Chef()
{
}

void Chef::Add(Chef* nextChef)
{
    if(nextChef_)
    {
        nextChef_->Add(nextChef);
    }
    else
    {
        nextChef_ = nextChef;
    }
}

void Chef::HandleOrder(Plate* plate, vector<OrderComponent*> orderComp)
{
    if(nextChef_)
    {
        nextChef_->HandleOrder(plate, orderComp);
    }
}

void Chef::CreateGroupOrder(Order* order)
{
    GroupIterator* iterator = order->CreateIterator();
    iterator->SetOrder(order);

    while (!iterator->IsDone()) {
        Order* currentComponent = iterator->CurrentItem();
        cout << "The kitchen is preparing an order for group " << currentComponent->GetGroupNumber() << endl;
        if (currentComponent) {
            HandleOrder(new Plate(), currentComponent->GetItems());
        }
        cout<<endl;
        iterator->Next();
    }
    
    if (iterator->IsDone())
    {
        cout << "The kitchen is done preparing all orders for group " << order->GetGroupNumber() << endl;
        pass_->AddToListOfTrays(tray_); // add tray to list of trays
        tray_.clear();  // clear tray
        cout<<"Waiter name: "<<order->GetGroup()->GetWaiter()->GetName()<<endl;
        Changed();
    }
}

void Chef::Changed()
{
    pass_->NotifyWaiter(this);
}
