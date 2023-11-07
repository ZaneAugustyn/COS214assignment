#ifndef _CUSTOMERPAYS_H
#define _CUSTOMERPAYS_H

#include "BillPayment.h"
#include "Group.h"
#include <iostream>
#include <limits>
using namespace std;

class Group;
/**
 * @class CustomerPays
 * @brief Represents a bill payment method where a customer pays their bill in the group.
 */
class CustomerPays : public BillPayment
{
public:
    /**
     * @brief Constructor for the CustomerPays class.
     * @param t The total amount to be paid by the customer.
     */
    CustomerPays(float t);

    /**
     * @brief Destructor for the CustomerPays class.
     */
    ~CustomerPays();

    /**
     * @brief Perform the bill payment where a customer pays their share.
     * @param group The group of customers for which the bill is being paid.
     * @return void
     */
    void Pay(Group* group);
};

#endif
