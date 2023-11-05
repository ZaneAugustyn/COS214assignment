#include "facade.h"

#define YELLOW  "\033[93m"      /* Yellow */
#define RED     "\033[31m"      /* Red */
#define RESET   "\033[0m"
#define LIGHT_GREEN "\033[92m"  /* Light Green */
#define PINK    "\033[38;5;206m"  /* Pink */

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
    cout<<endl;
    cout<<endl;
    cout<<YELLOW<<"Welcome Le McDonalds please select on of the following options to begin: "<<RESET<<endl;
    while (loop)
    {
        int choice;
        cout<<endl;
        cout<<YELLOW<<"1. Add a group to the queue outside"<<RESET<<endl;
        if(mostRecent >= 1)
        {
            cout<<YELLOW<<"2. Let a group inside the restaurant"<<RESET<<endl;
        }
        if(mostRecent >= 2)
        {
            cout<<YELLOW<<"3. Let a group order"<<RESET<<endl;
        }
        if(mostRecent >= 3)
        {
            cout<<YELLOW<<"4. Let a group pay the bill"<<RESET<<endl;
        }
        if(mostRecent >= 4)
        {
            cout<<YELLOW<<"5. Remove group from restaurant"<<RESET<<endl;
        }
        cout<<YELLOW<<"6. Exit Simulation"<<RESET<<endl;
        
        cout<<YELLOW<<"Please select an option : "<<RESET;
        cin>>choice;
    

        switch (choice)
        {
            case 1:
                if (choice > mostRecent)
                        {
                            mostRecent = choice;
                        }
                option1();
                break;
            case 2:
                if (mostRecent >= 1)
                {
                    if (choice > mostRecent)
                        {
                            mostRecent = choice;
                        }
                    option2();
                }
                else
                {
                    cout <<RED<< "Option 2 is not available yet. Please select a valid option." <<RESET<< endl;
                }
                break;
            case 3:
                if (mostRecent >= 2)
                {
                    if (choice > mostRecent)
                        {
                            mostRecent = choice;
                        }
                    option3();
                }
                else
                {
                    cout <<RED<< "Option 3 is not available yet. Please select a valid option." <<RESET<< endl;
                }
                break;
            case 4:
                if (mostRecent >= 3)
                {
                    if (choice > mostRecent)
                        {
                            mostRecent = choice;
                        }
                    option4();
                }
                else
                {
                    cout <<RED<< "Option 4 is not available yet. Please select a valid option." <<RESET<< endl;
                }
                break;
            case 5:
                if (mostRecent >= 4)
                {   
                    if (choice > mostRecent)
                        {
                            mostRecent = choice;
                        }
                    option5();
                }
                else
                {
                    cout <<RED<< "Option 5 is not available yet. Please select a valid option." <<RESET<< endl;
                }
                break;
            case 6:
                option6();
                loop = false;
                break;
            default:
                cout <<RED<< "Invalid option. Please select a valid option." <<RESET<< endl;
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
        cout<<YELLOW<<"Please enter customers name: "<<RESET;
        cin>>name;
        Customer* newCustomer = new Customer(name);
        newGroup->addCustomer(newCustomer);

        while (true)
        {
            cout<<YELLOW<<"Would you like to add another customer? (Y/N): "<<RESET;
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
    cout <<YELLOW<< "List of group numbers: "<<RESET<<endl;
    
    int numGroups = floor->getGroups().size();
    std::vector<Group*> g = floor->getGroups();
    int c;
    for (int i = 0; i < numGroups; i++)
    {
        cout<<"Group number: "<<g[i]->getGroupNumber()<<endl;
    }


    while (true)
    {
        int selectedGroupNumber;
        cout <<YELLOW<< "Enter the group number that wants to order: "<<RESET;
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
            break;
            // cout << "Ordering process initiated for group " << selectedGroupNumber << endl;
        } else {
            cout <<RED<< "Group with the selected number does not exist." <<RESET<< endl;
            continue;
        }
    }

}


void facade::option4()
{
    cout <<YELLOW<< "List of group numbers: "<<RESET<<endl;
    
    int numGroups = floor->getGroups().size();
    std::vector<Group*> g = floor->getGroups();
    int c;
    for (int i = 0; i < numGroups; i++)
    {

        cout<<"Group number: "<<g[i]->getGroupNumber()<<endl;
    }


    while (true)
    {
        int selectedGroupNumber;
        cout <<YELLOW<< "Enter the group number that wants to pay their bill: "<<RESET;
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
            break;
            // cout << "Bill process initiated for group " << selectedGroupNumber << endl;
        } else {
            cout <<RED<< "Group with the selected number does not exist." <<RESET<< endl;
            continue;
        }
    }
    
    
}


void facade::option5()
{
    cout<<YELLOW<<"Please select the group you would like to excuse from the floor: "<<RESET<<endl;
    int numGroups = floor->getGroups().size();
    std::vector<Group*> g = floor->getGroups();
    int c;
    for (int i = 0; i < numGroups; i++)
    {
        cout<<"Group number: "<<g[i]->getGroupNumber()<<endl;
    }
    while (true)
    {
        cout<<YELLOW<<"Please choose a Group number :"<<RESET;
        cin>>c;
        if (c >= 1 && c <= numGroups)
        {

            delete g[c - 1];
            g.erase(g.begin() + c - 1);
            floor->setGroups(g);

            cout<<LIGHT_GREEN<< "Group " << c << " has been excused from the floor." <<RESET<< endl;
            break;
        }
        else
        {
            cout <<RED<< "Invalid group number. Please choose a valid number." <<RESET<< endl;
            continue;
        }
        numGroups = floor->getGroups().size();
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
    //floor->setSpaceAvailable();
    //IS AVAILABLE AS STANDARD

    maitreD = new MaitreD(floor,20);

    vector<Waiter*> waiters;
    int numWaiters;
    cout<<YELLOW<<"Please select number of waiters: "<<RESET;
    cin>>numWaiters;
    for (int i = 0; i < numWaiters; i++)
    {
        std::string wName;
        cout<<YELLOW<<"Please enter a name for waiter number "<<i+1<<": "<<RESET;
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