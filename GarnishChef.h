#ifndef _GARNISHCHEF_H
#define _GARNISHCHEF_H

#include "Chef.h"

class GarnishChef : public Chef
{
private:
    /* data */
public:
    GarnishChef(/* args */);
    virtual ~GarnishChef();
    void HandleOrder(Plate* plate);
};

#endif
