#ifndef _PLATE_H
#define _PLATE_H

#include <vector>
class Order;
class OrderItem;

using namespace std;

/**
 * @class Plate
 * @brief A class representing a plate containing a list of order items.
 */
class Plate {
private:
    Order* order_; 
    vector<OrderItem*> burger_; 

public:
    /**
     * @brief Constructor for creating a Plate instance.
     */
    Plate();

    /**
     * @brief Print the contents of the plate to the console.
     * @return void
     */
    void printPlate();

    /**
     * @brief Add an order item to the plate.
     * @param item The order item to add to the plate.
     * @return void
     */
    void addToPlate(OrderItem* item);

    /**
     * @brief Destructor for the Plate instance.
     */
    virtual ~Plate();
};

#endif
