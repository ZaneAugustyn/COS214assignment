#include "Floor.h"
#include "FloorState.h"
#include "Full.h"
#include "SpaceAvailable.h"
#include "MaitreD.h"
#include "OrderComponent.h"
#include "OrderItem.h"
#include "Group.h"
#include "GroupState.h"
#include "Bun.h"
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
#include "Chef.h"
#include "HeadChef.h"
#include "MeatChef.h"
#include "DrinkChef.h"
#include "SidesChef.h"
#include "GarnishChef.h"
#include "Pass.h"
#include "Colleague.h"
#include "Waiter.h"
#include "WaitForTable.h"
#include "Bill.h"
#include "BillPayment.h"
#include "Customer.h"
#include "CustomerPays.h"
#include "Happy.h"
#include "MakeTab.h"
#include "PayTab.h"
#include "ReadyForBill.h"
#include "ReadyToOrder.h"
#include "SplitBill.h"
#include "Tab.h"
#include "Unhappy.h"

#include <array>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    //create the restaurant floor
    Floor* floor = new Floor();

    //set the floor state to empty
    floor->setSpaceAvailable();

    //create the maitre'd
    MaitreD* maitred = new MaitreD(floor);

    //create some waiters for the restaurant
    vector<Waiter*> waiters;
    int numWaiters;
    cout<<"Please select number of waiters: ";
    cin>>numWaiters;
    for (int i = 0; i < numWaiters; i++)
    {
        std::string wName;
        cout<<"Please enter a name for waiter number "<<i<<": ";
        cin>>wName;

        waiters.push_back(new Waiter(wName));
    }

    //add the waiters to the maitre'd
    maitred->setWaiterList(waiters);
    

    //create a group
    bool loop = true;
    while (loop)
    {
        char choice;
        cout<<"Would you like to add a group to the Queue? (Y/N) : ";
        cin>>choice;
        if(choice=='Y' || choice=='y')
        {
            int size = 0;
            cout<<"Please enter a group size: ";
            cin>>size;
            Group* newGroup = new Group(new WaitForTable(), size);

            for (int i = 0; i < size; i++)
            {
                string newCName;
                cout<<"Please enter group member "<<i<<"'s name: ";
                cin>>newCName;
                Customer* newCustomer = new Customer(/*newCName*/);
                newGroup->addCustomer(newCustomer);
            }

            //add the group to the maitre'd's queue
            maitred->addGroupToWaitingGroups(newGroup);

        }
        else if(choice=='N' || choice=='n')
        {
            break;
        }
        else
        {
            cout<<"Incorrect input please try again."<<endl;
        }
    }

    //add the group to the floor
    //a waiter will be assigned to the group by the maitre'd
    cout<<"Would you like to allow a group to enter the floor? (Y/N): ";
    char c;
    cin>>c;

    bool l = true;
    while (l)
    {
        if(c=='Y' || c=='y')
        {
            maitred->addGroupToFloor();
        }
        else if(c=='N' || c=='n')
        {
            cout<<"Maybe later"<<endl;
            break;
        }
        else
        {
            cout<<"Incorrect input please try again."<<endl;
        }
    }
    

    //the group is now ready to order
    bobsBirthdayGroup->RequestToOrder();

    //KITCHEN INTEGRATED HERE TOMORROW
    //THE KITCHEN WILL GENERATE THE BILL AND ADD IT TO THE GROUP
    //DUMMY BILL FOR TEST PURPOSES:


    Bill* dummyBill = new Bill(200);
    bobsBirthdayGroup->setBill(dummyBill);
    
    //the group requests to pay
    bobsBirthdayGroup->RequestBill();
    cout << bobsBirthdayGroup->GetState()->ToString() << endl;

    // just need to test the tab was made for the first person
    Customer* c1 = bobsBirthdayGroup->getFirstCustomer();
    Tab* checkTab = c1->getTab();
    if (checkTab == NULL) 
    {
        cout << "No tab available" << endl;
    }
    else{
        cout << "the tab amount to be paid is " << checkTab->getAmount() << endl;
    } 
}