#include "HeaderBill.h"

HeaderBill::HeaderBill(PrintBill* component) :Marginals(component)
{

}

void HeaderBill::Print()
{
    cout << endl << "==========================================="<<endl << endl;
    cout << "Le McDonalds" << endl;
    cout << "Serving Gourmet Burgers to all" << endl << endl;
    cout << "012 256 5000" << endl;
    Marginals::Print();
}