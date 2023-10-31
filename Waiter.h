#ifndef _WAITER_H
#define _WAITER_H

// #include "Pass.h"
#include "Colleague.h"

class Pass;

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
