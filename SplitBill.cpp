#include "SplitBill.h"

SplitBill::SplitBill(float t): Bill(t)
{
}

SplitBill::~SplitBill()
{
}

void SplitBill::Pay(Customer* customer)
{
    float pay = 0;
    float tip = 0;
    char choice = 0;
    while (fullyPaid())
    {
        cout << "Please pass the terminal to the customer." << endl;
        cout << "The bill is chosen to be paid in split payment." << endl;
        cout << "Please enter the amount you'd like to pay (excluding the tip amount)." << endl;
        cin >> pay;
        cout << "Would you like to add a tip? (y/n)" << endl;
        cin >> choice;
        if (choice == 'y')
        {
            cout << "Please enter the amount you'd like to tip the waiter." << endl;
            cin >> tip;
        }

        paid(pay);
        tipWaiter(tip);
        cout << "Thank you" << endl;
    }
    
    cout << "Thank you for the full payment of " << this->TotalPaid + this->TipAmount;
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