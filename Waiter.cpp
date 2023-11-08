#include "Waiter.h"
#include "Pass.h"
#include "Group.h"
#include "BillPayment.h"
#include "Order.h"
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
#include "Bill.h"
#include "Bun.h"
#include <iostream>
#include <string>
#include <limits> 

#define RED     "\033[31m"      /* Red */
#define RESET   "\033[0m"

Waiter::Waiter(std::string n, Pass* pass):Colleague(pass)
{
    this->name_ = n;

    this->menu_ = new Order(NULL);

    //meats
    Order* meats = new Order(NULL);
    meats->AddComponent(new ChickenPatty(true));
    meats->AddComponent(new BeefPatty());

    //sides
    Order* sides = new Order(NULL);
    sides->AddComponent(new Chips());
    sides->AddComponent(new Salad());

    //garnish
    Order* garnish = new Order(NULL);
    garnish->AddComponent(new Lettuce());
    garnish->AddComponent(new Tomato());

    //drinks
    Order* drinks = new Order(NULL);
    drinks->AddComponent(new Milkshake());
    drinks->AddComponent(new Soda());

    this->menu_->AddComponent(meats);
    this->menu_->AddComponent(sides);
    this->menu_->AddComponent(garnish);
    this->menu_->AddComponent(drinks);

}

void Waiter::Changed()
{
    this->pass_->NotifyHeadChef(this);
}

Waiter::~Waiter()
{

}

std::string Waiter::GetName()
{
    return name_;
}

void Waiter::Update(Group* group)
{
    std::cout<<GetName()<<" has been notified"<<std::endl;

    if(group->GetState()->ToString() == "WaitForTable"){
        return;
    }
    else if(group->GetState()->ToString() == "ReadyToOrder"){
        //display menu to customers and get order
        LanguageAdapter* la = new LanguageAdapter();
        Order* groupOrder = new Order(group);

        //iterate over customers
        for(Customer* customer : group->GetCustomers()){
            Order* customerOrder = new Order(group);

            customerOrder->AddComponent(new Bun());

            char languageChoice;
            cout << customer->GetName() << ", in which language would you like your menu? ('A' for Afrikaans, 'E' for English)" << endl;
            cin >> languageChoice;
            
            GroupIterator* iterator = menu_->CreateIterator();
            string messages[] = {"Please select a meat", "Please select a side", "Please select a garnish", "Please select a drink"};
            int i = 0;

            while (!iterator->IsDone()) {
                cout << messages[i] << endl;
               
                cout << (iterator->CurrentItem())->FormatOrder(la, languageChoice);
                int choice;
                cin >> choice;                

                while (!cin.good() || (choice != 1 && choice != 2)) // check that input is of type int
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    cout<<"WARNING! You entered the wrong menu option. Please try again."<<endl;
                    cout << messages[i] << endl;
                    cout << (iterator->CurrentItem())->FormatOrder(la, languageChoice);

                    cin >> choice;
                }

                if (i==0 && choice==1)
                {
                    char chicOption;
                    cout<<"Would you like your chicken patty fried or grilled? (F/G)"<<endl;
                    cin>>chicOption;

                    while ((chicOption != 'F' && chicOption != 'G')) // check that input is of type int
                    {
                        cout<<"Please enter a valid option: ";
                        cin>>chicOption;
                    }

                    if (chicOption == 'F')
                    {
                        customerOrder->AddComponent(new ChickenPatty(0));
                    }
                    else
                    {
                        customerOrder->AddComponent(new ChickenPatty(1));
                    }
                    
                }
                else
                {
                    customerOrder->AddComponent((iterator->CurrentItem())->GetItems()[choice - 1]);
                }

                i++;
                iterator->Next(); 
            }

            groupOrder->AddComponent(customerOrder);

        }
        pass_->AddOrder(groupOrder);
    }
    else if(group->GetState()->ToString() == "ReadyForBill"){
        //the waiter will take the group bill and display it
        
        char status;
        cout <<"Are you happy/unhappy with the service? (H/U) ";
        cin>>status;
        while (status != 'H' && status != 'U')
        {
            cout << RED << "Please enter a valid choice (H/U) " << RESET;
            cin>>status;
        }
        if (status =='H')
            group->MakeHappy();
        else if (status =='U')
            group->MakeUnhappy();

        cout << "You have to pay R " << group->GetBill()->GetTotal() << endl;
        cout << "How would you like to pay it? 'S' to split, 'F' to pay in full, 'T' to put it on a tab" << endl;
        char c;
        cin >> c;

        while ((c != 'S') && (c != 'F') && (c != 'T') && (c != 's') && (c != 'f') && (c != 't'))
        {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"WARNING! You entered the wrong bill option. Please try again."<<endl;
            cout << "How would you like to pay it? 'S' to split, 'F' to pay in full, 'T' to put it on a tab" << endl;
            cin >> c;
        }
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        
        if(group != NULL)
        {
            group->GetBill()->Pay(group,c);
        }
        else
        {
            cout << "There are no customers in this group to pay for the bill" << endl;
        }
    }
    else if(group->GetState()->ToString() == "PayTab"){

    }
    
}
