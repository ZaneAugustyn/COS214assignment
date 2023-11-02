#ifndef _HEADCHEF_H
#define _HEADCHEF_H

#include <vector>

#include "Chef.h"
class Plate;
class OrderItem;
class Pass;

using namespace std;

class HeadChef : public Chef
{
  public:
    HeadChef();
    HeadChef(Pass* p);
    void handleOrder(Plate* plate, vector<OrderComponent*> orderComp) override;
    virtual ~HeadChef();
  private:
    void addToTray(Plate* plate);
};

#endif
