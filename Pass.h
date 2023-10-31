#ifndef _PASS_H
#define _PASS_H

#include <vector>
#include <Order.h>

// code here
class Pass
{
  private:
    vector<Order*> orders;
    
  public:
    Pass(/* args */);
    ~Pass();
};

#endif
