#ifndef _HEADCHEF_H
#define _HEADCHEF_H

#include "Plate.h"
#include "Chef.h"

class HeadChef : public Chef
{
  private:
  public:
    HeadChef(/* args */);
    void handleOrder(Plate* plate);
    void addToTray(Plate* plate);
    virtual ~HeadChef();
};

#endif
