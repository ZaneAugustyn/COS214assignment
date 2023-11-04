#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include "Tab.h"
#include <string>
using namespace std;

class Customer
{
private:
    Tab* tab_;
    string name_;
public:
    Customer(string name);
    ~Customer();
    Tab* getTab();
    void setTab(Tab* tab);
    string getName();
};


#endif
