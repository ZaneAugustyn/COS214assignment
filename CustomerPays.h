#ifndef _CUSTOMERPAYS_H
#define _CUSTOMERPAYS_H

#include <Bill.h>
#include <iostream>
using namespace std;

class CustomerPays: public Bill
{
private:
    /* data */
public:
    CustomerPays(float t);
    ~CustomerPays();
    void Pay(Customer* customer);
};


#endif
