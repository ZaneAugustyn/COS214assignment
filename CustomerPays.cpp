#include "CustomerPays.h"

CustomerPays::CustomerPays(float t) : BillPayment(t)
{
}

CustomerPays::~CustomerPays()
{
}

void CustomerPays::Pay(Group* group)
{
    float paid = 0;
    string complaint;
    char choice;
    bool invalid;
    while(paid < GetTotal()){
        cout << "Please pay the bill of R" << GetTotal() << endl;
        cout << "Please enter the amount you would like to pay including tip" << endl;
        invalid = true;
        while (invalid)
        {
            if(cin >> paid)
            {
                
                if (paid > GetTotal())
                {
                    cout << "Thank you, and thank you for the Tip!" << endl;
                    invalid = false;
                }
                else if(paid == GetTotal())
                {
                    cout << "Thank you!" << endl;
                    invalid = false;
                }
                else
                {
                    cout << "Payment failed! Please pay the full amount as R" << paid << " is less than R" << GetTotal() << endl;
                }
            }
            else
            {
                cout << "Please enter a valid number to pay!" << endl;
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        
    }
    if (group->GetLastEmotion()->ToString() == "Unhappy")
    {
        cout << "Would you like to leave a complaint (Y/N)" << endl;
        cin >> choice;

        invalid = true;
        while (invalid)
        {
            if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
            {
                invalid = false;
                if (choice == 'y' || choice == 'Y')
                {
                    cout << "Please enter your complaint " << endl;
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
    else {
        cout << "Thank you for the support" << endl;
    }
}
