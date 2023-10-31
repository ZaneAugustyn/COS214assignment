#ifndef _HEADCHEF_H
#define _HEADCHEF_H

#include <vector>
#include <Plate.h>
#include <Pass.h>
#include "Chef.h"

class HeadChef : public Chef
{
  public:
    HeadChef(/* args */);
    void handleOrder(Plate* plate);
    virtual ~HeadChef();
  private:
    void addToTray(Plate* plate);
};

#endif