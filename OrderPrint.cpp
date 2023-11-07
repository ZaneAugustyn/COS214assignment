#include "OrderPrint.h"
#include "PrintBill.h"


OrderPrint::OrderPrint(float total):PrintBill(),total_(total)
{

}

OrderPrint::~OrderPrint()
{

}

void OrderPrint::Print()
{
    cout << endl << "----------------------------" << endl;
    cout << "Total: R" << total_ << endl;
    cout << "----------------------------" << endl;
}