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
    while(paid < getTotal()){
        cout << "Please pay the bill of R" << getTotal() << endl;
        cout << "Please enter the amount you would like to pay." << endl;
        cin >> paid;
        if (paid > getTotal())
            cout << "Thank you fot the Tip!" << endl;
        else if(paid < getTotal())
            cout << "Payment failed! Please pay the full amount as R" << paid << " is less than R" << getTotal() << endl;
    }
    cout << "Thank you for the support" << endl;
}
