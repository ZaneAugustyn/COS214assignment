#include "Bill.h"

Bill::Bill(float t): Total(t)
{
}

Bill::~Bill()
{
}

void Bill::Pay(Group* group, char choice)
{
    BillPayment* payment;
    switch (choice)
    {
    case 'S': // Split bill
        payment = new SplitBill(this->getTotal());
        break;

    case 'F': // Full payment
        payment = new CustomerPays(this->getTotal());
        break;

    case 'T': // Tab payment
        payment = new MakeTab(this->getTotal());
        break;
    }

    if(payment != NULL){
        payment->Pay(group);
        delete payment;
    }
}
