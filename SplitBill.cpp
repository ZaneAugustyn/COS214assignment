#include "SplitBill.h"

SplitBill::SplitBill(float t) : BillPayment(t)
{
}

SplitBill::~SplitBill()
{
}

void SplitBill::Pay(Group *group)
{
    float pay;
    float tip;
    char choice;
    int count = 0;
    string complaint;
    while (!FullyPaid())
    {
        if (count == group->GetCustomers().size())
        {
            count = 0;
        }
        pay = 0;
        tip = 0;
        cout << "Please pass the terminal to " << (group->GetCustomers())[count]->GetName() << endl;
        cout << "The bill is chosen to be paid in split payment." << endl;
        cout << "The total amount to be paid is " << this->GetTotal() << endl;
        cout << "The total amount paid for the bill so far is " << this->TotalPaid << endl;
        cout << "The total amount paid as tip so far is " << this->TipAmount << endl;
        cout << "Please enter the amount you'd like to pay (excluding the tip amount)." << endl;
        bool invalid = true;
        while (invalid)
        {
            if (cin >> pay)
            {
                if(pay >= 0)
                {
                    invalid = false;
                }
                else
                {
                    cout << "Please enter a valid amount." << endl;
                }
            }
            else
            {
                cout << "Please enter a valid amount." << endl;
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        if (group->GetLastEmotion()->ToString() == "Happy")
        {
            cout << "Would you like to add a tip? (y/n)" << endl;

            invalid = true;
            while (invalid)
            {
                if(cin >> choice)
                {
                    if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
                    {
                        invalid = false;
                        if (choice == 'y' || choice == 'Y')
                        {
                            cout << "Please enter the amount you'd like to tip the waiter." << endl;
                            invalid = true;
                            while(invalid)
                            {
                                if(cin >> tip)
                                {
                                    if(tip > 0)
                                    {
                                        cout << "Thank you for the tip!" << endl;
                                        invalid = false;
                                    }
                                    else{
                                        cout << "Please enter a valid tip amount." << endl;
                                    }
                                }
                                else
                                {
                                    cout << "Please enter a valid tip amount." << endl;
                                    cin.clear(); // Clear error flags
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }
                            }
                        }
                    }
                    else
                    {
                        cout << "Please enter a valid choice for the tip." << endl;
                        cin.clear(); // Clear error flags
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                else
                {
                        cout << "Please enter a valid amount for the tip." << endl;
                }
                
            }
        }

        Paid(pay);
        TipWaiter(tip);
        count++;
    }

    cout << "Thank you for the full payment of " << this->TotalPaid + this->TipAmount << endl;
    if (this->TipAmount > 0)
    {
        cout << "Thank you for the tip" << endl;
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

void SplitBill::Paid(float paid)
{
    this->TotalPaid += paid;
}

void SplitBill::TipWaiter(float tip)
{
    this->TipAmount += tip;
}

bool SplitBill::FullyPaid()
{
    return GetTotal() <= TotalPaid;
}