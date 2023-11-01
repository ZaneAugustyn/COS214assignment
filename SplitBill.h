#ifndef _SPLITBILL_H
#define _SPLITBILL_H
// code here
#include <Bill.h>
class SplitBill: public Bill
{
private:
    /* data */
    SplitBill* next;
public:
    SplitBill(float t);
    virtual ~SplitBill();
    virtual void Pay(Customer* customer);
};

#endif
