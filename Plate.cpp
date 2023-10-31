#ifndef _PLATE_H
#define _PLATE_H

#include <vector>
#include <Order.h>
#include <OrderItem.h>

class Plate
{
  private:
    Order* order;
    vector<OrderItem*> burger;
  public:
    Plate();
    void printPlate();
    virtual ~Plate();
};

#endif