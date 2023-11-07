#ifndef _SPLITBILL_H
#define _SPLITBILL_H

#include "BillPayment.h"
#include "Group.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Group;

/**
 * @class SplitBill
 * @brief Represents a bill payment method where the bill is split among customers.
 */
class SplitBill : public BillPayment
{
private:
    float TotalPaid = 0; 
    float TipAmount = 0; 

public:
    /**
     * @brief Constructor for the SplitBill class.
     * @param t The total amount to be paid for the bill.
     */
    SplitBill(float t);

    /**
     * @brief Destructor for the SplitBill class.
     */
    ~SplitBill();

    /**
     * @brief Perform the split bill payment among a group of customers.
     * @param group The group of customers for which the bill is being paid.
     * @return void
     */
    void Pay(Group* group);

    /**
     * @brief Add paid value to TotalPaid by the customer.
     * @param paid The amount paid by the customer.
     * @return void
     */
    void Paid(float paid);

    /**
     * @brief Record the tip amount paid to the waiter.
     * @param tip The tip amount paid to the waiter.
     * @return void
     */
    void TipWaiter(float tip);

    /**
     * @brief Check if the bill is fully paid.
     * @return boolean value -True if the bill is fully paid, otherwise false.
     */
    bool FullyPaid();
};

#endif
