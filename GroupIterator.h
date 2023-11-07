#ifndef _GROUPITERATOR_H
#define _GROUPITERATOR_H

#include "OrderComponent.h"
#include <vector>

class Order;   // Forward declaration of Order class


using namespace std;

/**
 * @class GroupIterator
 * @brief A class for iterating through the components of an Order.
 */
class GroupIterator {
private:
    Order* order_; /**< The Order for which components are being iterated. */
    int current_position_;
public:
    /**
     * @brief Default constructor for GroupIterator.
     */
    GroupIterator();

    /**
     * @brief Parameterized constructor for GroupIterator.
     * @param order The Order for which components will be iterated.
     */
    GroupIterator(Order* order);

    /**
     * @brief Destructor for GroupIterator.
     */
    ~GroupIterator();

    /**
     * @brief Get the next component in the iteration.
     * @return A pointer to the next OrderComponent, or nullptr if the iteration is complete.
     */
    Order* Next();

    /**
     * @brief Check if the iteration is complete.
     * @return True if the iteration is complete, false otherwise.
     */
    bool IsDone();

    /**
     * @brief Get the current component in the iteration.
     * @return A pointer to the current OrderComponent, or nullptr if the iteration is complete.
     */
    Order* CurrentItem();

    /**
     * @brief Set the Order for which components will be iterated.
     * @param o The new Order to set for iteration.
     */
    void SetOrder(Order* o);
};

#endif
