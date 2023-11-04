#ifndef _BILL_H
#define _BILL_H

#include "Customer.h"
#include "Group.h"
#include "BillPayment.h"
#include "SplitBill.h"
#include "CustomerPays.h"
#include "MakeTab.h"

class Bill
{
private:
    /* data */
    float Total; // total amount to be paid for a bill
public:
    Bill(float t);
    ~Bill();
    void Pay(Group* group, char choice);
    float getTotal() { return Total; };
    void setTotal(float t) { Total = t; };
};

#endif
