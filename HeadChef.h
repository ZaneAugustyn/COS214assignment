#ifndef _HEADCHEF_H
#define _HEADCHEF_H

#include <vector>
#include <Plate.h>
#include <Pass.h>
#include <Chef.h>

class HeadChef : public Chef
{
  private:
    vector<Plate*> tray_;
  public:
    HeadChef(/* args */);
    void handleOrder(Plate* plate);
    void addToTray(Plate* plate);
    virtual ~HeadChef();
};

#endif
