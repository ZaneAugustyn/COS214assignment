#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include "Tab.h"
#include <string>
using namespace std;

/**
 * @class Customer
 * @brief Represents a customer with a name and a tab.
 */
class Customer
{
private:
    Tab* tab_; 
    string name_; 

public:
    /**
     * @brief Constructor for the Customer class.
     * @param name The name of the customer.
     */
    Customer(string name);

    /**
     * @brief Destructor for the Customer class.
     */
    ~Customer();

    /**
     * @brief Get the customer's tab.
     * @return A pointer to the customer's tab.
     */
    Tab* getTab();

    /**
     * @brief Set the customer's tab.
     * @param tab A pointer to the tab to be associated with the customer.
     * @return void
     */
    void setTab(Tab* tab);

    /**
     * @brief Get the name of the customer.
     * @return The name of the customer.
     */
    string getName();
};

#endif
