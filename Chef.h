#ifndef _CHEF_H
#define _CHEF_H

#include "Plate.h"
#include "Colleague.h"

class Chef : public Colleague
{
private:
    Chef* nextChef_;
public:
    Chef(); 
    virtual ~Chef();
    virtual void handleOrder(Plate* plate);
    void setNextChef(Chef* nextChef);
    void createGroupOrder();
};

#endif
