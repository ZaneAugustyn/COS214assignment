#ifndef _SPLITBILL_H
#define _SPLITBILL_H

#include "BillPayment.h"
#include "Group.h"
#include <iostream>
using namespace std;

class SplitBill: public BillPayment
{
private:
    /* data */
    float TotalPaid = 0;
    float TipAmount = 0;
public:
    SplitBill(float t);
    ~SplitBill();
    void Pay(Group* group);
    void paid(float paid);
    void tipWaiter(float tip);
    bool fullyPaid();
};

#endif
