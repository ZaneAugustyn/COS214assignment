#ifndef _WAITER_H
#define _WAITER_H

#include "Colleague.h"

class Pass;

class Waiter : public Colleague
{
  private:
    
  public:
    Waiter(/* args */);
    void changed();
    virtual ~Waiter();
};

#endif
