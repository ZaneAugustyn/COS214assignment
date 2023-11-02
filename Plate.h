#ifndef _PLATE_H
#define _PLATE_H

#include <vector>
class Order;
class OrderItem;

using namespace std;

class Plate
{
  private:
    Order* order_;
    vector<OrderItem*> burger_;
  public:
    Plate();
    void printPlate();
    void addToPlate(OrderItem*);
    virtual ~Plate();
};

#endif