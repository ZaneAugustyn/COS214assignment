#include "Facade.h"
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
    InitBasic();
}

Facade::~Facade()
{

}

void Facade::Run()
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
        if(maitreD_->GetAwaitingGroup().size() > 0)
        {
            cout<<YELLOW<<"2. Let a group inside the restaurant"<<RESET<<endl;
        }
        if(maitreD_->GetFloor()->GetGroups().size() > 0)
        {
            cout<<YELLOW<<"3. Let a group order"<<RESET<<endl;
        }
        if(maitreD_->GetFloor()->GetGroups().size() > 0)
        {
            cout<<YELLOW<<"4. Let a group pay the bill"<<RESET<<endl;
        }
        if(maitreD_->GetFloor()->GetGroups().size() > 0)
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
                Option1();
                break;
            case 2:
                if (maitreD_->GetAwaitingGroup().size() > 0)
                {
                    Option2();
                }
                else
                {
                    cout <<RED<< "Option 2 is not available yet. Please select a valid option." <<RESET<< endl;
                }
                break;
            case 3:
                if (maitreD_->GetFloor()->GetGroups().size() > 0)
                {
                    Option3();
                }
                else
                {
                    cout <<RED<< "Option 3 is not available yet. Please select a valid option." <<RESET<< endl;
                }
                break;
            case 4:
                if (maitreD_->GetFloor()->GetGroups().size() > 0)
                {
                    Option4();
                }
                else
                {
                    cout <<RED<< "Option 4 is not available yet. Please select a valid option." <<RESET<< endl;
                }
                break;
            case 5:
                if (maitreD_->GetFloor()->GetGroups().size() > 0)
                {   
                    Option5();
                }
                else
                {
                    cout <<RED<< "Option 5 is not available yet. Please select a valid option." <<RESET<< endl;
                }
                break;
            case 6:
                Option6();
                loop = false;
                break;
            default:
                cout <<RED<< "Invalid option. Please select a valid option." <<RESET<< endl;
        }
    }

}

void Facade::Option1()
{
    string names[] = {"John", "Jane", "Bob", "Alice", "Joe", "Jill", "Bill", "Sally", "Jack", "Jill", "Tom", "Tim", "Tina", "Terry", "Trevor", "Tiffany", "Tina", "Terry", "Trevor", "Tiffany"};
    numGroups_++;
    Group* newGroup = new Group(new WaitForTable(), numGroups_);
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
        newGroup->AddCustomer(newCustomer);
    }
    // print group
    cout << LIGHT_GREEN << "Group " << numGroups_ << " :";
    for (int i = 0; i < numCustomers; i++)
    {
        cout << " " << newGroup->GetCustomers()[i]->GetName();
    }
    cout << RESET << endl;

    //add the group to the maitre'd's queue
    maitreD_->AddGroupToWaitingGroups(newGroup);

    // print the queue

}

void Facade::Option2()
{
    maitreD_->AddGroupToFloor();
}

void Facade::Option3()
{
    cout <<YELLOW<< "List of group numbers: "<<RESET<<endl;
    
    int numGroups = floor_->GetGroups().size();
    std::vector<Group*> g = floor_->GetGroups();
    int c;
    for (int i = 0; i < numGroups; i++)
    {
        cout<<"Group number: "<<g[i]->GetGroupNumber()<<endl;
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
            if (group->GetGroupNumber() == selectedGroupNumber) {
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

void Facade::Option4()
{
    cout <<YELLOW<< "List of group numbers: "<<RESET<<endl;
    
    int numGroups = floor_->GetGroups().size();
    std::vector<Group*> g = floor_->GetGroups();
    int c;
    for (int i = 0; i < numGroups; i++)
    {

        cout<<"Group number: "<<g[i]->GetGroupNumber()<<endl;
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
            if (group->GetGroupNumber() == selectedGroupNumber) {
                selectedGroup = group;
                break;
            }
        }
        if (selectedGroup) {
            selectedGroup->RequestBill();
            break;
        } else {
            cout <<RED<< "Group with the selected number does not exist." <<RESET<< endl;
            continue;
        }
    }
    
    
}

void Facade::Option5()
{
    cout << YELLOW << "Please select the group you would like to excuse from the floor: " << RESET << endl;
    int numGroups = floor_->GetGroups().size();
    std::vector<Group*> g = floor_->GetGroups();
    int c;

    for (int i = 0; i < numGroups; i++)
    {
        cout << "Group number: " << g[i]->GetGroupNumber() << endl;
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
            if (g[i]->GetGroupNumber() == c)
            {
                auto it = g.begin() + i;
                // g.erase(it);
                // floor->setGroups(g);
                Group* group = g[i];
                int t = maitreD_->GetFloor()->GetGroups().size();
                maitreD_->RemoveGroupFromFloor(group);
                if(t == maitreD_->GetFloor()->GetGroups().size())
                {
                    l = false;
                    break;
                }

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

void Facade::Option6()
{
    cout << PINK << endl << "Thank you for using the Le McDonalds simulation! We hope to see you again soon :)" << RESET << endl << endl;
}

void Facade::InitBasic()
{
    cout << PINK << endl << "Welcome to the Le McDonalds restaurant simulation" << RESET << endl << endl;
    floor_ = new Floor();

    // create the pass
    kitchenPass_ = new Pass();

    // build chain
    chef_ = new Chef(kitchenPass_);
    headChef_ = new HeadChef(kitchenPass_);
    kitchenPass_->AddChef(chef_);
    chef_->Add(headChef_);
    chef_->Add(new MeatChef());
    chef_->Add(new DrinkChef());
    chef_->Add(new SidesChef());
    chef_->Add(new GarnishChef());
    chef_->Add(headChef_);

    maitreD_ = new MaitreD(floor_,20);

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

        waiters.push_back(new Waiter(wName, kitchenPass_));
    }

    //add the waiters to the maitre'd
    maitreD_->SetWaiterList(waiters);
}