#include "facade.h"
#include <iostream>
#include <limits>
#include <string>

#define YELLOW  "\033[93m"      /* Yellow */
#define RED     "\033[31m"      /* Red */
#define RESET   "\033[0m"
#define LIGHT_GREEN "\033[92m"  /* Light Green */
#define PINK    "\033[38;5;206m"  /* Pink */

Facade::Facade(/* args */)
{
    initBasic();
}

Facade::~Facade()
{

}

void Facade::run()
{
    bool loop = true;
    cout<<endl;
    cout<<endl;
    cout<<PINK<<"Welcome to Le McDonalds please select one of the following options to begin: "<<RESET<<endl;
    while (loop)
    {
        int choice;
        cout<<endl;
        cout<<YELLOW<<"1. Add a group to the queue outside"<<RESET<<endl;
        if(maitreD->getAwaitingGroup().size() > 0)
        {
            cout<<YELLOW<<"2. Let a group inside the restaurant"<<RESET<<endl;
        }
        if(maitreD->getFloor()->getGroups().size() > 0)
        {
            cout<<YELLOW<<"3. Let a group order"<<RESET<<endl;
        }
        if(maitreD->getFloor()->getGroups().size() > 0)
        {
            cout<<YELLOW<<"4. Let a group pay the bill"<<RESET<<endl;
        }
        if(maitreD->getFloor()->getGroups().size() > 0)
        {
            cout<<YELLOW<<"5. Remove group from restaurant"<<RESET<<endl;
        }
        cout<<YELLOW<<"6. Exit Simulation"<<RESET<<endl;
        
        cout<<YELLOW<<"Please select an option : "<<RESET;
        cin>>choice;

        while(!cin.good())
        {
            cout<<RED<<"Please enter a valid number: "<<RESET;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin>>choice;
        }
    

        switch (choice)
        {
            case 1:
                option1();
                break;
            case 2:
                if (maitreD->getAwaitingGroup().size() > 0)
                {
                    option2();
                }
                else
                {
                    cout <<RED<< "Option 2 is not available yet. Please select a valid option." <<RESET<< endl;
                }
                break;
            case 3:
                if (maitreD->getFloor()->getGroups().size() > 0)
                {
                    option3();
                }
                else
                {
                    cout <<RED<< "Option 3 is not available yet. Please select a valid option." <<RESET<< endl;
                }
                break;
            case 4:
                if (maitreD->getFloor()->getGroups().size() > 0)
                {
                    option4();
                }
                else
                {
                    cout <<RED<< "Option 4 is not available yet. Please select a valid option." <<RESET<< endl;
                }
                break;
            case 5:
                if (maitreD->getFloor()->getGroups().size() > 0)
                {   
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

void Facade::option1()
{
    string names[] = {"John", "Jane", "Bob", "Alice", "Joe", "Jill", "Bill", "Sally", "Jack", "Jill", "Tom", "Tim", "Tina", "Terry", "Trevor", "Tiffany", "Tina", "Terry", "Trevor", "Tiffany"};
    numGroups++;
    Group* newGroup = new Group(new WaitForTable(), numGroups);
    cout << YELLOW << "How many customers are in the group? " << RESET;
    int numCustomers;
    cin >> numCustomers;

    while (!cin.good() || numCustomers <= 0)
    {
        cout << RED << "Please enter a valid number: " << RESET;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> numCustomers;
    }
    
    //create customers
    for (int i = 0; i < numCustomers; i++)
    {
        int randomName = rand() % 20;
        Customer* newCustomer = new Customer(names[randomName]);
        newGroup->addCustomer(newCustomer);
    }
    // print group
    cout << LIGHT_GREEN << "Group " << numGroups << " :";
    for (int i = 0; i < numCustomers; i++)
    {
        cout << " " << newGroup->getCustomers()[i]->getName();
    }
    cout << RESET << endl;

    //add the group to the maitre'd's queue
    maitreD->addGroupToWaitingGroups(newGroup);
    // print the queue
}

void Facade::option2()
{
    maitreD->addGroupToFloor();
}

void Facade::option3()
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

        while(!cin.good())
        {
            cout<<RED<<"Please enter a valid number: "<<RESET;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin>>selectedGroupNumber;
        }

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

void Facade::option4()
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

        while(!cin.good()){
            cout<<RED<<"Please enter a valid number: "<<RESET;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin>>selectedGroupNumber;
        }
        Group* selectedGroup = nullptr;

        for (auto& group : g) {
            if (group->getGroupNumber() == selectedGroupNumber) {
                selectedGroup = group;
                break;
            }
        }
        if (selectedGroup) {
            askForHappiness(selectedGroup);
            selectedGroup->RequestBill();
            break;
        } else {
            cout <<RED<< "Group with the selected number does not exist." <<RESET<< endl;
            continue;
        }
    }
    
    
}

void Facade::option5()
{
    cout << YELLOW << "Please select the group you would like to excuse from the floor: " << RESET << endl;
    int numGroups = floor->getGroups().size();
    std::vector<Group*> g = floor->getGroups();
    int c;

    for (int i = 0; i < numGroups; i++)
    {
        cout << "Group number: " << g[i]->getGroupNumber() << endl;
    }


    bool l = true;
    while (l)
    {
        cout << YELLOW << "Please choose a number: " << RESET;
        cin >> c;
        while (!cin.good()){
            cout<<RED<<"Please enter a valid number: "<<RESET;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin>>c;
        }

        for (int i = 0; i < numGroups; i++)
        {
            if (g[i]->getGroupNumber() == c)
            {
                auto it = g.begin() + i;
                // g.erase(it);
                // floor->setGroups(g);
                Group* group = g[i];
                maitreD->removeGroupFromFloor(group);

                cout << LIGHT_GREEN << "Group " << c << " has been excused from the floor." << RESET << endl;
                l = false;
                break;
            }
        }

        if (l) // Only execute if the loop did not break
        {
            cout << RED << "Invalid group number. Please choose a valid number." << RESET << endl;
        }
    }
}

void Facade::option6()
{
    cout << PINK << endl << "Thank you for visiting Le McDonalds! We hope to see you again soon :)" << RESET << endl << endl;
}

void Facade::initBasic()
{
    cout << PINK << endl << "Welcome to Le McDonalds resaurant simulation" << RESET << endl << endl;
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

    maitreD = new MaitreD(floor,20);

    vector<Waiter*> waiters;
    int numWaiters;
    cout<<YELLOW<<"Please select number of waiters: "<<RESET;
    cin>>numWaiters;
    while (!cin.good() || numWaiters <= 0)
    {
        cout<<RED<<"Please enter a valid number: "<<RESET;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin>>numWaiters;
    }
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

void Facade::askForHappiness(Group* selectedGroup)
{
    char status;
    cout <<"Are you happy/unhappy with the service? (H/U) ";
    cin>>status;
    while (status != 'H' && status != 'U')
    {
        cout << RED << "Please enter a valid choice (H/U) " << RESET;
        cin>>status;
    }
    if (status =='H')
        selectedGroup->MakeHappy();
    else if (status =='U')
        selectedGroup->MakeUnhappy();
}