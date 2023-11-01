#ifndef _CHEF_H
#define _CHEF_H

#include <vector>
using namespace std;
#include "Colleague.h"

class Pass;
class Plate; 
class Order;

class Chef : public Colleague
{
    private:
        Chef* nextChef_;
    protected:
        vector<Plate*> tray_;
    public:
        Chef(); 
        virtual ~Chef();
        void changed();
        virtual void handleOrder(Plate* plate);
        void add(Chef* nextChef);
        void createGroupOrder(Order* order);
};

#endif