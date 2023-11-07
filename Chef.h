#ifndef _CHEF_H
#define _CHEF_H

#include <vector>
using namespace std;

#include "Colleague.h"
#include "ItemIterator.h"

class Pass;
class Plate; 
class Order;
class Group;
class Waiter;
class OrderItem;
class OrderComponent;

/**
 * @class Chef
 * @brief This class is a concrete colleague of the Mediator design and the Handler participant of the Chain of Responsibility Pattern
*/

class Chef : public Colleague
{
    private:
      Chef* nextChef_;
    protected:
      vector<Plate*> tray_;
    public:
      /**
       * @brief default constructor
       * @return none
      */
      Chef(); 

      /**
       * @brief constructor
       * @param p the shared pass member variable
       * @return none
      */
      Chef(Pass* p);

      /**
       * @brief virtual destructor
       * @return none
      */
      virtual ~Chef();

      /**
       * @brief part of the mediator design pattern to delegate the appropriate notify method
       * @return void
      */
      void changed();

      /**
       * @brief part of the chain of responsibility design pattern to delegate to handle the order
       * @param plate pass the plate object to which the food will be added
       * @param orderComp hold one of the group member's group order
       * @return void
      */
      virtual void handleOrder(Plate* plate, vector<OrderComponent*> orderComp);
      
      /**
       * @brief part of the mediator design pattern to add a specific chef to the chain of responsibility
       * @param nextChef pointer to the next chef in the chain of responsibility
       * @return void
      */
      void add(Chef* nextChef);

      /**
       * @brief is being used as the start and the end of the chain of responsibility
       * @param order holds the pointer to the group order
       * @return void
      */      
      void createGroupOrder(Order* order);
};

#endif