#ifndef _CHEF_H
#define _CHEF_H

#include "Plate.h"

class Chef
{
private:
    Chef* nextChef_;
public:
    Chef(); 
    virtual ~Chef();
    virtual void HandleOrder(Plate* plate);
    void setNextChef(Chef* nextChef);
};

#endif
