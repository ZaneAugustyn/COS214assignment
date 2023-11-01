#ifndef _SPLITBILL_H
#define _SPLITBILL_H
// code here
#include <Bill.h>
#include <iostream>
using namespace std;

class SplitBill: public Bill
{
private:
    /* data */
    SplitBill* next;
    float TotalPaid = 0;
    float TipAmount = 0;
public:
    SplitBill(float t);
    ~SplitBill();
    void Pay(Customer* customer);
    void paid(float paid);
    void tipWaiter(float tip);
    bool fullyPaid();
};

#endif
