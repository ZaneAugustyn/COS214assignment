#ifndef _BILLPAYMENT_H
#define _BILLPAYMENT_H

#include "Customer.h"
#include "Group.h"

class Group;
/**
 * @class BillPayment
 * @brief Represents a method of payment for a bill.
 */
class BillPayment
{
private:
    float Total; 

public:
    /**
     * @brief Constructor for the BillPayment class.
     * @param t The total amount to be paid for the bill payment.
     */
    BillPayment(float t);

    /**
     * @brief Virtual destructor for the BillPayment class.
     */
    virtual ~BillPayment();

    /**
     * @brief Perform the bill payment for a group of customers.
     * @param group The group of customers for which the bill is being paid.
     */
    virtual void Pay(Group* group) = 0;

    /**
     * @brief Get the total amount of the bill payment.
     * @return The total amount of the bill payment.
     */
    float GetTotal() { return Total; }

    /**
     * @brief Set the total amount of the bill payment.
     * @param t The new total amount for the bill payment.
     */
    void SetTotal(float t) { Total = t; }
};

#endif
