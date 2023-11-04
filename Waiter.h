#ifndef _WAITER_H
#define _WAITER_H

#include "Colleague.h"
#include "Group.h"
#include "LanguageAdapter.h"
#include <string>
#include <vector>

class Pass;
class Bill;
class Order;

/**
 * @class Waiter
 * @brief This class is a concrete colleague of the Mediator design and the Handler participant of the Chain of Responsibility Pattern
*/

//class Group;

class Waiter : public Colleague
{
  private:
    std::string name_;
    Order* menu_;

  public:
    /**
     * @brief default constructor
     * @return none
    */
    Waiter(std::string n);

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

    std::string getName();

    // void addGroup(Group* group);
    // void removeGroup(Group* group);

    void update(Group* group);
};

#endif