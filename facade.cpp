#include "facade.h"

facade::facade(/* args */)
{
    initBasic();
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
        cout<<"6. Exit Simulation"<<endl;
        
        cout<<"Please select an option : ";
        cin>>choice;
    

        switch (choice)
        {
            case 1:
                option1();
                break;
            case 2:
                if (mostRecent >= 1)
                {
                    option2();
                }
                else
                {
                    cout << "Option 2 is not available yet. Please select a valid option." << endl;
                }
                break;
            case 3:
                if (mostRecent >= 2)
                {
                    option3();
                }
                else
                {
                    cout << "Option 3 is not available yet. Please select a valid option." << endl;
                }
                break;
            case 4:
                if (mostRecent >= 3)
                {
                    option4();
                }
                else
                {
                    cout << "Option 4 is not available yet. Please select a valid option." << endl;
                }
                break;
            case 5:
                if (mostRecent >= 4)
                {
                    option5();
                }
                else
                {
                    cout << "Option 5 is not available yet. Please select a valid option." << endl;
                }
                break;
            case 6:
                option6();
                loop = false;
                break;
            default:
                cout << "Invalid option. Please select a valid option." << endl;
        }

        if (choice > mostRecent)
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
    cout << "List of group numbers: "<<endl;
    
    int numGroups = floor->getGroups().size();
    std::vector<Group*> g = floor->getGroups();
    int c;
    for (int i = 0; i < numGroups; i++)
    {
        cout<<i+1<<". Group number: "<<g[i]->getGroupNumber()<<endl;
    }

    int selectedGroupNumber;
    cout << "Enter the group number that wants to order: ";
    cin >> selectedGroupNumber;

    Group* selectedGroup = nullptr;
    for (auto& group : g) {
        if (group->getGroupNumber() == selectedGroupNumber) {
            selectedGroup = group;
            break;
        }
    }
    if (selectedGroup) {
        selectedGroup->RequestToOrder();
        cout << "Ordering process initiated for group " << selectedGroupNumber << endl;
    } else {
        cout << "Group with the selected number does not exist." << endl;
    }

}


void facade::option4()
{
    cout << "List of group numbers: "<<endl;
    
    int numGroups = floor->getGroups().size();
    std::vector<Group*> g = floor->getGroups();
    int c;
    for (int i = 0; i < numGroups; i++)
    {

        cout<<i+1<<". Group number: "<<g[i]->getGroupNumber()<<endl;
    }

    int selectedGroupNumber;
    cout << "Enter the group number that wants to pay their bill: ";
    cin >> selectedGroupNumber;

    Group* selectedGroup = nullptr;
    for (auto& group : g) {
        if (group->getGroupNumber() == selectedGroupNumber) {
            selectedGroup = group;
            break;
        }
    }
    if (selectedGroup) {
        selectedGroup->RequestBill();
        // cout << "Bill process initiated for group " << selectedGroupNumber << endl;
    } else {
        cout << "Group with the selected number does not exist." << endl;
    }
    
}


void facade::option5()
{
    cout<<"Please select the group you would like to excuse from the floor: ";
    int numGroups = floor->getGroups().size();
    std::vector<Group*> g = floor->getGroups();
    int c;
    for (int i = 0; i < numGroups; i++)
    {
        cout<<i+1<<". Group number: "<<g[i]->getGroupNumber()<<endl;
    }
    while (true)
    {
        cout<<"Please choose a number :";
        cin>>c;
        //code to remove the specific group chosen from vector
        if (c >= 1 && c <= numGroups)
        {
            // Remove the selected group from the vector
            delete g[c - 1]; // Assuming you need to deallocate the memory if it was dynamically allocated
            g.erase(g.begin() + c - 1);
            floor->setGroups(g);

            cout << "Group " << c << " has been excused from the floor." << endl;
            break;
        }
        else
        {
            cout << "Invalid group number. Please choose a valid number." << endl;
            continue;
        }
    }

}



void facade::option6()
{
    cout<<"Option6 done";
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
void facade::askForHappiness(Group* selectedGroup)
{
    char Status;
    cout <<"Are you happy/unhappy with the service? (H/U) ";
    cin>>Status;
    if (Status ='H')
        selectedGroup->MakeHappy();
    else if (Status ='U')
        selectedGroup->MakeUnhappy();
    else selectedGroup->MakeNeutral();
}