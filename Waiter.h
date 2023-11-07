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

using namespace std;

/**
 * @class Waiter
 * @brief This class is a concrete colleague of the Mediator design and the Handler participant of the Chain of Responsibility Pattern
*/
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
    Waiter(std::string n, Pass* pass);

    /**
     * @brief part of the mediator design pattern to delegate the appropriate notify method
     * @return void
    */
    void Changed();

    /**
     * @brief virtual destructor
     * @return none
    */
    virtual ~Waiter();

    /**
     * @brief Get the name of the waiter.
     * @return The name of the waiter.
     */
    string GetName();

    /**
     * @brief Update the waiter with changes in the group's state.
     * @param group The group whose state has changed.
     * @return void
     */
    void Update(Group* group);
};

#endif