#ifndef _WAITER_H
#define _WAITER_H

#include <Pass.h>

class Waiter
{
  private:
    
  public:
    Waiter(/* args */);
    virtual void changed() = 0;
    virtual Pass* get() = 0;
    virtual void set(Pass* pass) = 0;
    virtual ~Waiter();
};

#endif
