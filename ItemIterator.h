#ifndef _ITEMITERATOR_H
#define _ITEMITERATOR_H

class Order;   // Forward declaration of Order class 
class OrderComponent;   // Forward declaration of OrderComponent class
#include <vector>

using namespace std;

/**
 * @class ItemIterator
 * @brief A class for iterating through a collection of OrderComponent objects.
 */
class ItemIterator 
{
private:
    vector<OrderComponent*> items_; /**< The collection of OrderComponent items. */
    int currentIndex_; /**< The current index within the collection. */

public:
    /**
     * @brief Default constructor for ItemIterator.
     */
    ItemIterator();

    /**
     * @brief Parameterized constructor for ItemIterator.
     * @param items_ The collection of OrderComponent items to iterate.
     */
    ItemIterator(vector<OrderComponent*> items_);

    /**
     * @brief Set the collection of OrderComponent items to iterate.
     * @param items_ The new collection of OrderComponent items.
     */
    void setOrderComponents(vector<OrderComponent*> items_);

    /**
     * @brief Get the next OrderComponent in the iteration.
     * @return A pointer to the next OrderComponent, or nullptr if the iteration is complete.
     */
    OrderComponent* next();

    /**
     * @brief Check if the iteration is complete.
     * @return True if the iteration is complete, false otherwise.
     */
    bool isDone();

    /**
     * @brief Get the current OrderComponent in the iteration.
     * @return A pointer to the current OrderComponent, or nullptr if the iteration is complete.
     */
    OrderComponent* currentItem();
};

#endif
