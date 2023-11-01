#ifndef _GARNISHCHEF_H
#define _GARNISHCHEF_H

#include "Chef.h"

class Plate;
class OrderItem;

class GarnishChef : public Chef
{
private:
    /* data */
public:
    GarnishChef(/* args */);
    virtual ~GarnishChef();
    void handleOrder(Plate* plate, vector<OrderComponent*> orderComp);
};

#endif
