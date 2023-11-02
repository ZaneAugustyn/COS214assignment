#ifndef _GROUPITERATOR_H
#define _GROUPITERATOR_H

class Order;   // Forward declaration of Order class
#include "OrderComponent.h"
#include <vector>

using namespace std;

/**
 * @class GroupIterator
 * @brief A class for iterating through the components of an Order.
 */
class GroupIterator {
private:
    Order* order_; /**< The Order for which components are being iterated. */

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
    Order* next();

    /**
     * @brief Check if the iteration is complete.
     * @return True if the iteration is complete, false otherwise.
     */
    bool isDone();

    Order* currentItem();

    void setOrder(Order* o);
};

#endif
