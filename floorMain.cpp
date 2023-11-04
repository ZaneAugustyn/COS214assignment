#include "Floor.h"
#include "FloorState.h"
#include "Full.h"
#include "SpaceAvailable.h"
#include "MaitreD.h"
#include "WaitForTable.h"
#include "Customer.h"
#include "Waiter.h"

int main(){

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
    Group* bobsBirthdayGroup = new Group(new WaitForTable(), 2);

    //create two customers
    Customer* alice = new Customer();
    Customer* bob = new Customer();

    //add the customers to the group
    bobsBirthdayGroup->addCustomer(alice);
    bobsBirthdayGroup->addCustomer(bob);

    //add the group to the maitre'd's queue
    maitred->addGroupToWaitingGroups(bobsBirthdayGroup);

    //add the group to the floor
    //a waiter will be assigned to the group by the maitre'd
    maitred->addGroupToFloor();

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

}