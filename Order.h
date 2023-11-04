#ifndef _ORDER_H
#define _ORDER_H

#include "OrderComponent.h"
#include "GroupIterator.h"
#include "LanguageTarget.h"

class Group;
class OrderItem;
class Waiter;
class ItemIterator;

#include <vector>

using namespace std;

/**
 * @class Order
 * @brief Represents an order containing a list of order components.
 */
class Order : public OrderComponent {
private:
    Group* group_;
    vector<OrderComponent*> components_; 
    int currentComponentIndex_;
    friend class GroupIterator;

public:
    /**
     * @brief Constructor for an Order.
     * @param group The group to which this order belongs.
     */
    Order(Group* group);

    /**
     * @brief Destructor for an Order.
     */
    ~Order();

    /**
     * @brief Calculate and return the total price of the order.
     * @return The total price of the order.
     */
    double getPrice();

    /**
     * @brief Add an order component to this order.
     * @param component The order component to add.
     * @return void
     */
    void addComponent(OrderComponent* component);

    /**
     * @brief Remove an order component from this order.
     * @param component The order component to remove.
     * @return void
     */
    void removeComponent(OrderComponent* component);

    /**
     * @brief Get a vector of all order components within this order.
     * @return A vector of order components.
     */
    virtual vector<OrderComponent*> getItems();

    /**
     * @brief Create an iterator for traversing the order components.
     * @return A GroupIterator for this order.
     */
    GroupIterator* createIterator();
    
    /**
     * @brief Get the group number associated with this order.
     * @return The group number.
     */
    int getGroupNumber();

    /**
     * @brief Get the group associated with this order.
     * @return A pointer to the associated group.
     */
    Group* getGroup();

    /**
     * @brief Format the order in the specified language.
     * @param lt The language target for formatting.
     * @param lang The language code.
     * @return The formatted order as a string.
     */
    string formatOrder(LanguageTarget* lt, char lang);
};

#endif
