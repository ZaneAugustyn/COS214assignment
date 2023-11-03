#include "Bill.h"

Bill::Bill(float t): Total(t)
{
}

Bill::~Bill()
{
}

void Bill::Pay(Customer* customer, char choice)
{
    BillPayment* payment;
    switch (choice)
    {
    case 'S': // Split bill
        payment = new SplitBill(getTotal());
        break;

    case 'F': // Full payment
        payment = new CustomerPays(getTotal());
        break;

    case 'T': // Tab payment
        payment = new MakeTab(getTotal());
        break;
    }

    if(payment != NULL){
        payment->Pay(customer);
        delete payment;
    }
}
