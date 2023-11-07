#ifndef _COLLEAGUE_H
#define _COLLEAGUE_H

#include "Pass.h"

/**
 * @class Colleague
 * @brief This class is a abstract colleague of the Mediator design
*/

class Colleague
{
  private:

  protected:
    Pass* pass_;

  public:
    /**
     * @brief default constructor
     * @return none
    */
    Colleague(/* args */);

    /**
     * @brief Constructor
     * @param p the shared pass member variable
     * @return none
    */    
    Colleague(Pass* p);

    /**
     * @brief part of the mediator design pattern to delegate the appropriate notify method (abstract)
     * @return void
    */
    virtual void changed() = 0;

    /**
     * @brief virtual destructor
     * @return none
    */
    virtual ~Colleague();
};


#endif
