#include "Bill.h"
#include "PayTab.h"


Bill::Bill(float t): total_(t)
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
            payment = new SplitBill(this->GetTotal());
            break;

        case 'F': // Full payment
            payment = new CustomerPays(this->GetTotal());
            break;

        case 'T': // Tab payment
            payment = new MakeTab(this->GetTotal());
            break;
        case 's': // Split bill
            payment = new SplitBill(this->GetTotal());
            break;

        case 'f': // Full payment
            payment = new CustomerPays(this->GetTotal());
            break;

        case 't': // Tab payment
            payment = new MakeTab(this->GetTotal());
            break;
    }

    Print();

    if(payment != NULL){
        payment->Pay(group);
        delete payment;
    }
}

void Bill::Print()
{
    PrintBill* bill = new FooterBill(new HeaderBill(new OrderPrint(this->GetTotal())));
    bill->Print();
    delete bill;
}
