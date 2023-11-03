#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include "Tab.h"

class Customer
{
private:
    Tab* tab;
public:
    Customer(/* args */);
    ~Customer();
    Tab* getTab();
    void setTab(Tab* tab);
};


#endif
