#include "MakeTab.h"

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
    Customer* customer;
    while(!TabAllocated)
    {
        if(count == group->getCustomers().size()){
            count = 0;
        }
        customer = (group->getCustomers())[count];
        cout << customer->getName() << ", would you like to take the tab? (y/n)" << endl;
        cin >> choice;
        bool invalid = true;
        while(invalid){
            if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
            {
                invalid = false;
                if (choice == 'y' || choice == 'Y')
                {
                    Tab* t1 = createTab(getTotal());    
                    customer->setTab(t1);    
                    TabAllocated = true;
                }
            }
            else{
                cout << "Please enter a valid choice." << endl;
            }
        }
        
        ++count;
    }
}

Tab* MakeTab::createTab(float t)
{
    Tab* tab = new Tab(t);
    return tab;
}

void MakeTab::setTab(Tab* tab)
{
    // set total amount owed to total for the bill
    setTotal(tab->getAmount());
}
