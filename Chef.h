#ifndef _CHEF_H
#define _CHEF_H

class Pass;
class Plate;
#include "Colleague.h"

class Chef : public Colleague
{
private:
    Chef* nextChef_;
protected:
    vector<Plate*> tray_;
public:
    Chef(); 
    virtual ~Chef();
    virtual void handleOrder(Plate* plate);
    void add(Chef* nextChef);
    void createGroupOrder();
    Pass* get();
    void set(Pass* pass);
    void changed();
};

#endif
