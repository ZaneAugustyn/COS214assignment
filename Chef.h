#ifndef _CHEF_H
#define _CHEF_H

#include <vector>
using namespace std;

#include "Colleague.h"
#include "ItemIterator.h"

class Pass;
class Plate; 
class Order;
class OrderItem;
class OrderComponent;

class Chef : public Colleague
{
    private:
        Chef* nextChef_;
    protected:
        vector<Plate*> tray_;
    public:
        Chef(); 
        Chef(Pass*);
        virtual ~Chef();
        void changed();
        virtual void handleOrder(Plate* plate, vector<OrderComponent*> orderComp);
        void add(Chef* nextChef);
        void createGroupOrder(Order* order);
};

#endif