#ifndef _BILL_H
#define _BILL_H

#include "Customer.h"
#include "Group.h"
#include "BillPayment.h"
#include "SplitBill.h"
#include "CustomerPays.h"
#include "MakeTab.h"
#include "PrintBill.h"
#include "OrderPrint.h"
#include "Marginals.h"
#include "FooterBill.h"
#include "HeaderBill.h"

// class PrintBill;
// class Marginals;
// class OrderPrint;
// class HeaderBill;
// class FooterBill;

/**
 * @class Bill
 * @brief Represents a bill for a group of customers.
 */
class Bill
{
private:
    float Total;

public:
    /**
     * @brief Constructor for the Bill class.
     * @param t The total amount to be paid for the bill.
     */
    Bill(float t);

    /**
     * @brief Destructor for the Bill class.
     */
    ~Bill();

    /**
     * @brief Pay the bill for a group of customers.
     * @param group The group of customers.
     * @param choice The payment choice ('S' for split, 'F' for full, 'T' for tab).
     * @return void
     */
    void Pay(Group* group, char choice);

    /**
     * @brief Get the total amount of the bill.
     * @return The total amount of the bill in float format.
     */
    float getTotal() { return Total; }

    /**
     * @brief Set the total amount of the bill.
     * @param t The new total amount for the bill.
     * @return void
     */
    void setTotal(float t) { Total = t; }

    /**
     * @brief Print the bill.
     * @return void
     */
    void Print();
};

#endif
