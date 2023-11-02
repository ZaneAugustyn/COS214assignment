#include <iostream>
using namespace std;
#include "Plate.h"
#include "Order.h"
#include "OrderItem.h"

Plate::Plate()
{

}

void Plate::printPlate()
{
  vector<OrderItem*>::iterator it;
  string output = "PLATE: ";
  for (it = this->burger_.begin(); it!=this->burger_.end(); ++it)
  {
    output += (*it)->getName();
    if (it + 1 != this->burger_.end())
    {
        output += ", ";
    }
  }

  cout<<output<<endl;
}

void Plate::addToPlate(OrderItem* item)
{
  this->burger_.push_back(item);
}

Plate::~Plate()
{

}
