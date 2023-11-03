#ifndef _CUSTOMERPAYS_H
#define _CUSTOMERPAYS_H

#include <BillPayment.h>
#include <iostream>
using namespace std;

class CustomerPays: public BillPayment
{
private:
    /* data */
public:
    CustomerPays(float t);
    ~CustomerPays();
    void Pay(Customer* customer);
};

#endif
