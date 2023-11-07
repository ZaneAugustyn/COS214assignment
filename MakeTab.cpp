#include "MakeTab.h"
#include "PayTab.h"

MakeTab::MakeTab(float t) : BillPayment(t)
{
}

MakeTab::~MakeTab()
{
}

void MakeTab::Pay(Group* group)
{
    bool TabAllocated = false;
    int count = 0;
    char choice;
    string complaint;
    Customer* customer;
    while(!TabAllocated)
    {
        if(count == group->GetCustomers().size()){
            count = 0;
        }
        customer = (group->GetCustomers())[count];
        cout << customer->GetName() << ", would you like to take the tab? (Y/N)" << endl;
        bool invalid = true;
        while(invalid){
            if(cin >> choice)
            {
                if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
                {
                    invalid = false;
                    if (choice == 'y' || choice == 'Y')
                    {
                        Tab* t1 = CreateTab(GetTotal());    
                        customer->SetTab(t1);    
                        TabAllocated = true;
                        group->SetState(new PayTab());
                    }
                }
                else{
                    cout << "Please enter a valid choice." << endl;
                }
            }
            else 
            {
                cout << "Please enter a valid choice." << endl;
            }
        }
        
        ++count;
    }
    if (group->GetLastEmotion()->ToString() == "Unhappy")
    {
        cout << "Would you like to leave a complaint (Y/N)" << endl;
        cin >> choice;

        bool invalid = true;
        while (invalid)
        {
            if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
            {
                invalid = false;
                if (choice == 'y' || choice == 'Y')
                {
                    cout << "Please enter your complaint" << endl;
                    cin >> complaint;
                    cout << "Your complaint is noted, the management will be notified :(" << endl;
                }
            }
            else
            {
                cout << "Please enter a valid choice" << endl;
                cin >> choice;
            }
        }
    }
}

Tab* MakeTab::CreateTab(float t)
{
    Tab* tab = new Tab(t);
    return tab;
}

void MakeTab::SetTab(Tab* tab)
{
    // Set total amount owed to total for the bill
    SetTotal(tab->GetAmount());
}
