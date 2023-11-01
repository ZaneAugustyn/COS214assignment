#ifndef _SPLIT_H
#define _SPLIT_H
// code here
#include <SplitBill.h>

class Split: public SplitBill
{
private:
    /* data */
    SplitBill* next;
public:
    Split(float t);
    virtual ~Split();
    virtual void Pay(Customer* customer);
};

#endif
