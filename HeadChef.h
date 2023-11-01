#ifndef _HEADCHEF_H
#define _HEADCHEF_H

#include <vector>

#include "Chef.h"
class Plate;

class HeadChef : public Chef
{
  public:
    HeadChef();
    void handleOrder(Plate* plate);
    virtual ~HeadChef();
  private:
    void addToTray(Plate* plate);
};

#endif
