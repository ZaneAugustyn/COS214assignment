#include "facade.h"

facade::facade(/* args */)
{
}

facade::~facade()
{
}

void facade::run()
{
    bool loop = true;
    int mostRecent = 0;
    while (loop)
    {
        int choice;
        cout<<"Welcome Le McDonalds please select on of the following options to begin: "<<endl;
        cout<<"1. Add a group to the queue outside"<<endl;
        if(mostRecent >= 1)
        {
            cout<<"2. Let a group inside the restaurant"<<endl;
        }
        if(mostRecent >= 2)
        {
            cout<<"3. Let a group order"<<endl;
        }
        if(mostRecent >= 3)
        {
            cout<<"4. Let a group pay the bill"<<endl;
        }
        if(mostRecent >= 4)
        {
            cout<<"5. Remove group from restaurant"<<endl;
        }
        if(mostRecent >= 5)
        {
            cout<<"6. Exit Simulation"<<endl;
        }
        cout<<"Please select an option : ";
        cin>>choice;
        if(choice > mostRecent)
        {
            mostRecent = choice;
        }


    }
    
}

void facade::option1()
{
    numGroups++;
    Group* newGroup = new Group(new WaitForTable(), numGroups);

    //create customers
    bool loop = true;
    while (loop)
    {
        string name;
        cout<<"Please enter customers name: ";
        cin>>name;
        Customer* newCustomer = new Customer(name);
        newGroup->addCustomer(newCustomer);

        while (true)
        {
            cout<<"Would you like to add another customer? (Y/N): ";
            char c;
            cin>>c;
            if(c == 'Y' || c == 'y')
            {
                break;
            }
            else if(c == 'N' || c == 'n')
            {
                loop = false;
                break;
            }
            else
            {
                continue;
            }
        }  
    }

    //add the group to the maitre'd's queue
    maitreD->addGroupToWaitingGroups(newGroup);
}



void facade::option2()
{
    maitreD->addGroupToFloor();
}



void facade::option3()
{


}



void facade::option4()
{


}



void facade::option5()
{
    cout<<"Please select the group you would like to excuse from the floor: ";
    int numGroups = floor->getGroups().size();
    std::vector<Group*> g = floor->getGroups();
    int c;
    for (int i = 0; i < numGroups; i++)
    {
        cout<<get
    }
    

}



void facade::option6()
{
    
}

void facade::initBasic()
{
    floor = new Floor();

    // create the pass
    kitchenPass = new Pass();

    // build chain
    chef2 = new Chef(kitchenPass);
    headChef = new HeadChef(kitchenPass);
    kitchenPass->addChef(chef2);
    chef2->add(headChef);
    chef2->add(new MeatChef());
    chef2->add(new DrinkChef());
    chef2->add(new SidesChef());
    chef2->add(new GarnishChef());
    chef2->add(headChef);

    //set the floor state to empty
    floor->setSpaceAvailable();

    maitreD = new MaitreD(floor);

    vector<Waiter*> waiters;
    int numWaiters;
    cout<<"Please select number of waiters: ";
    cin>>numWaiters;
    for (int i = 0; i < numWaiters; i++)
    {
        std::string wName;
        cout<<"Please enter a name for waiter number "<<i<<": ";
        cin>>wName;

        waiters.push_back(new Waiter(wName, kitchenPass));
    }

    //add the waiters to the maitre'd
    maitreD->setWaiterList(waiters);
}

