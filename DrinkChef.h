#ifndef _DRINKCHEF_H
#define _DRINKCHEF_H

#include "Chef.h"

class Plate;
class OrderItem;

class DrinkChef : public Chef
{
public:
    DrinkChef();
    virtual ~DrinkChef();
    void handleOrder(Plate* plate, vector<OrderComponent*> orderComp);
};

#endif
