#ifndef _BILL_H
#define _BILL_H

#include <Customer.h>

class Bill
{
private:
    /* data */
    float Total; // total amount to be paid for a bill
public:
    Bill(float t);
    virtual ~Bill();
    virtual void Pay(Customer* customer);
    float getTotal() { return Total; };
    void setTotal(float t) { Total = t; };
};

#endif
