#include "CustomerPays.h"

CustomerPays::CustomerPays(float t) : Bill(t)
{
}

CustomerPays::~CustomerPays()
{
}

void CustomerPays::Pay(Customer* customer)
{
    float paid = 0;
    while(paid < getTotal()){
        cout << "Please pay the bill of R" << getTotal() << endl;
        cout << "Please enter the amount you would like to pay." << endl;
        cin >> paid;
        if (paid > getTotal())
            cout << "Thank you fot the Tip!" << endl;
    }
    cout << "Thank you for the support" << endl;
}
