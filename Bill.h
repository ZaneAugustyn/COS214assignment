#ifndef _BILL_H
#define _BILL_H

#include "Customer.h"
#include "BillPayment.h"
#include "SplitBill.h"
#include "CustomerPays.h"
#include "MakeTab.h"

class Bill
{
private:
    /* data */
    float Total; // total amount to be paid for a bill
public:

    /**
     * @brief parameterized constructor for Bill to initialise a group
     * @param total the total amount to pay for a bill
    */
    Bill(float total);

    /**
     * @brief destructor
    */
    ~Bill();

    /**
     * @brief the function to pay a bill
     * @param customer the customer that will pay the bill
     * @param choice the payment method choice
     * @return void
    */
    void Pay(Customer* customer, char choice);

    /**
     * @brief the function to return the Total Amount of the bill
     * @return float
    */
    float getTotal() { return Total; };

    /**
     * @brief the function to set the total amount of the bill
     * @param total the amount to set the total amount of the bill to
     * @return void
    */
    void setTotal(float total) { Total = total; };
};

#endif
