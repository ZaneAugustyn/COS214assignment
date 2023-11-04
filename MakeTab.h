#ifndef _MAKETAB_H
#define _MAKETAB_H

#include <iostream>
#include "BillPayment.h"
#include "Group.h"
#include "Tab.h"
using namespace std;

class Group;

class MakeTab: public BillPayment
{
private:
    
public:
    MakeTab(float t);
    ~MakeTab();
    Tab* createTab(float t);
    void Pay(Group* group);
    void setTab(Tab* tab);
};

#endif
