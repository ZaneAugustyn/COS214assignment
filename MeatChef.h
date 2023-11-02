#ifndef _MEATCHEF_H
#define _MEATCHEF_H

#include "Chef.h"
#include "ChickenPatty.h"
class Plate;
class OrderItem;

class MeatChef : public Chef
{
public:
    MeatChef();
    ~MeatChef();
    void handleOrder(Plate* plate, vector<OrderComponent*> orderComp);
};

#endif
