#ifndef _CHEF_H
#define _CHEF_H

#include <vector>
using namespace std;
#include "Colleague.h"

class Pass;
class Plate; 

class Chef : public Colleague
{
    private:
        Chef* nextChef_;
        vector<Plate*> tray_;
    public:
        Chef(); 
        virtual ~Chef();
        void changed();
        Pass* get();
        void set(Pass* pass);
        virtual void handleOrder(Plate* plate);
        void setNextChef(Chef* nextChef);
        void createGroupOrder();
};

#endif