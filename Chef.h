#ifndef _CHEF_H
#define _CHEF_H

#include "Plate.h"
#include "Colleague.h"
#include "Pass.h"

class Chef : public Colleague
{
private:
    Chef* nextChef_;
public:
    vector<Plate*> tray_;
    
    Chef(); 
    virtual ~Chef();
    virtual void handleOrder(Plate* plate);
    void setNextChef(Chef* nextChef);
    void createGroupOrder();
    Pass* get();
    void set(Pass* pass);
    void changed();

};

#endif
