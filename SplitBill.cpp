#include "SplitBill.h"

SplitBill::SplitBill(float t): BillPayment(t)
{
}

SplitBill::~SplitBill()
{
}

void SplitBill::Pay(Group* group)
{
    float pay;
    float tip;
    char choice;
    int count = 0;
    while (!fullyPaid())
    {
        if(count == group->getCustomers().size()){
            count = 0;
        }
        pay = 0;
        tip = 0;
        cout << "Please pass the terminal to " << (group->getCustomers())[count]->getName() << endl;
        cout << "The bill is chosen to be paid in split payment." << endl;
        cout << "The total amount to be paid is " << this->getTotal() << endl;
        cout << "The total amount paid for the bill so far is " << this->TotalPaid << endl;
        cout << "The total amount paid as tip so far is " << this->TipAmount << endl;
        cout << "Please enter the amount you'd like to pay (excluding the tip amount)." << endl;
        bool invalid = true; 
        while(invalid) {
            if (cin >> pay){
                invalid = false;
            }
            else{
                cout << "Please enter a valid amount." << endl;
            }
        }
        
        cout << "Would you like to add a tip? (y/n)" << endl;
        cin >> choice;

        invalid = true;
        while(invalid){
            if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
            {
                invalid = false;
                cout << "Please enter the amount you'd like to tip the waiter." << endl;
                cin >> tip;
            }
            else{
                cout << "Please enter a valid choice for the tip." << endl;
            }
        }

        

        paid(pay);
        tipWaiter(tip);
        count++;
    }
    
    cout << "Thank you for the full payment of " << this->TotalPaid + this->TipAmount << endl;
    if (this->TipAmount > 0)
    {
        cout << "Thank you fot the tip" << endl;
    }
}

void SplitBill::paid(float paid)
{
    this->TotalPaid += paid;
}

void SplitBill::tipWaiter(float tip)
{
    this->TipAmount += tip; 
}

bool SplitBill::fullyPaid()
{
    return getTotal() <= TotalPaid;
}