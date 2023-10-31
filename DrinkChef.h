#ifndef _DRINKCHEF_H
#define _DRINKCHEF_H

#include "Chef.h"

class DrinkChef : public Chef
{
public:
    DrinkChef();
    virtual ~DrinkChef();
    void HandleOrder(Plate* plate);
};

#endif
