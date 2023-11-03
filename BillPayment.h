#ifndef _BILLPAYMENT_H
#define _BILLPAYMENT_H

#include "Customer.h"

class BillPayment
{
private:
    /* data */
    float Total; // total amount to be paid for a bill
public:
    BillPayment(float t);
    virtual ~BillPayment();
    virtual void Pay(Customer* customer);
    float getTotal() { return Total; };
    void setTotal(float t) { Total = t; };
};

#endif
