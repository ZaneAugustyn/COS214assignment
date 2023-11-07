#include "FooterBill.h"

FooterBill::FooterBill(PrintBill* component) :Marginals(component)
{

}

void FooterBill::Print()
{
    Marginals::Print();
    cout << endl << "Thank you for your support!" << endl;
    cout << "See you soon!" << endl;
    cout << "For more information please visit http://leMcdonaldsBurgers.com" << endl;
    cout << endl << "==========================================="<<endl << endl;

}