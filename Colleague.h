#ifndef _COLLEAGUE_H
#define _COLLEAGUE_H

#include "Pass.h"

class Colleague
{
  private:

  protected:
    Pass* pass_;

  public:
    Colleague(/* args */);
    virtual void changed() = 0;
    virtual ~Colleague();
};


#endif
