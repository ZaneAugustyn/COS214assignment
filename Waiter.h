#ifndef _WAITER_H
#define _WAITER_H

#include "Colleague.h"

class Waiter : public Colleague
{
  private:
    
  public:
    Waiter(/* args */);
    void changed();
    Pass* get();
    void set(Pass* pass);
    virtual ~Waiter();
};

#endif
