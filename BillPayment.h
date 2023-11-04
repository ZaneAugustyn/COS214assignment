#ifndef _BILLPAYMENT_H
#define _BILLPAYMENT_H

#include "Customer.h"
#include "Group.h"

class Group;

class BillPayment
{
private:
    /* data */
    float Total; // total amount to be paid for a bill
public:
    BillPayment(float t);
    virtual ~BillPayment();
    virtual void Pay(Group* group);
    float getTotal() { return Total; };
    void setTotal(float t) { Total = t; };
};

#endif
