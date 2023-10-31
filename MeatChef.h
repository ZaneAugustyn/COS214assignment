#ifndef _MEATCHEF_H
#define _MEATCHEF_H

#include "Chef.h"

class MeatChef : public Chef
{
public:
    MeatChef();
    ~MeatChef();
    void HandleOrder(Plate* plate);
    void CookMeal();
protected:
    void Cook();

};

#endif
