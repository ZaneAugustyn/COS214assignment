#ifndef _HEADCHEF_H
#define _HEADCHEF_H

#include <vector>
#include <Plate.h>
#include <Pass.h>

class HeadChef
{
  private:
    vector<Plate*> tray_;
  public:
    HeadChef(/* args */);
    void changed();
    Pass* get();
    void set(Pass* pass);
    void handleOrder(Plate* plate);
    void addToTray(Plate* plate);
    virtual ~HeadChef();
};

#endif
