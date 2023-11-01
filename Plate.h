#ifndef _PLATE_H
#define _PLATE_H

#include <vector>
#include "OrderItem.h"
#include "Order.h"

class Plate
{
  private:
    Order* order_;
    vector<OrderItem*> burger_;
  public:
    Plate();
    void printPlate();
    virtual ~Plate();
};

#endif