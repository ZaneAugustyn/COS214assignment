#ifndef _ORDERITEM_H
#define _ORDERITEM_H

#include "OrderComponent.h"

#include <string>

using namespace std;

/**
 * @class OrderItem
 * @brief This class acts as the (concrete) Leaf of the Composite design pattern and represents an actual food item in an Order
*/

class OrderItem : public OrderComponent
{
private:
    double price_;
    string name_;
public:

    /**
     * @brief Constructor
     * @param price takes in the price of the OrderItem
     * @param name takes in a name for the OrderItem
     * @return none
    */
    OrderItem(double price, string name);

    /**
     * @brief destructor
     * @return none
    */
    ~OrderItem();

    /**
     * @brief getter for price
     * @return the price of the OrderItem
    */
    float getPrice();

    /**
     * @brief getter for name
     * @return the name of the OrderItem
    */
    string getName(); 
};

#endif

