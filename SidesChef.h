#ifndef _SIDESCHEF_H
#define _SIDESCHEF_H

#include "Chef.h"

class SidesChef : public Chef
{
public:
    SidesChef();
    virtual ~SidesChef();
    void HandleOrder(Plate* plate);
};

#endif
