#ifndef _WAITER_H
#define _WAITER_H

#include "Colleague.h"

class Pass;

/**
 * @class Waiter
 * @brief This class is a concrete colleague of the Mediator design and the Handler participant of the Chain of Responsibility Pattern
*/

class Waiter : public Colleague
{
  private:
    
  public:
    /**
     * @brief default constructor
     * @return none
    */
    Waiter(/* args */);

    /**
     * @brief part of the mediator design pattern to delegate the appropriate notify method
     * @return void
    */
    void changed();

    /**
     * @brief virtual destructor
     * @return none
    */
    virtual ~Waiter();
};

#endif
