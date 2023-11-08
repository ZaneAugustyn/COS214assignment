#ifndef _ORDERPRINT_H
#define _ORDERPRINT_H

#include "PrintBill.h"
#include <iostream>
using namespace std;

class PrintBill;

/**
 * @class OrderPrint
 * @brief Will print the order of the bill.
 */
class OrderPrint : public PrintBill
{
private:
    float total_;
public:
    /**
     * @brief Constructor for the OrderPrint class.
     * @param total the total amount of the bill
     */
    OrderPrint(float total);

    /**
     * @brief Virtual destructor for the OrderPrint class.
     */
    ~OrderPrint();

    /**
     * @brief Perform the printing of the order.
     */
    void Print();

};

#endif