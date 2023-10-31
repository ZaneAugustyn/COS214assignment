#ifndef _WAITER_H
#define _WAITER_H

#include <Pass.h>
#include <Colleague.h>

class Waiter : public Colleague
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
