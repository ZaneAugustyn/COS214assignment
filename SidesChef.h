#ifndef _SIDESCHEF_H
#define _SIDESCHEF_H

#include "Chef.h"

class Plate;
class OrderItem;

class SidesChef : public Chef
{
public:
    SidesChef();
    virtual ~SidesChef();
    void handleOrder(Plate* plate, vector<OrderComponent*> orderComp);
};

#endif
