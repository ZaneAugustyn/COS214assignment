#ifndef _MAKETAB_H
#define _MAKETAB_H

#include <iostream>
#include <Bill.h>
#include <Tab.h>
using namespace std;

class MakeTab: public Bill
{
private:
    
public:
    MakeTab(float t);
    ~MakeTab();
    Tab* createTab(float t);
    void setTab(Tab* tab);
};

#endif
