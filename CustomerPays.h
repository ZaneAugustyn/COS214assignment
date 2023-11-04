#ifndef _CUSTOMERPAYS_H
#define _CUSTOMERPAYS_H

#include "BillPayment.h"
#include "Group.h"
#include <iostream>
using namespace std;

class Group;


class CustomerPays: public BillPayment
{
private:
    /* data */
public:
    CustomerPays(float t);
    ~CustomerPays();
    void Pay(Group* group);
};

#endif
