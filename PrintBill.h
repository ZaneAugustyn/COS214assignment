#ifndef _PRINTBILL_H
#define _PRINTBILL_H

#include <iostream>

/**
 * @class PrintBill
 * @brief Will be the representation and printing of a bill.
 */
class PrintBill
{
public:
    /**
     * @brief Constructor for the PrintBill class.
     */
    PrintBill();

    /**
     * @brief Virtual destructor for the PrintBill class.
     */
    virtual ~PrintBill();

    /**
     * @brief Perform the printing of a bill.
     */
    virtual void Print() = 0;

};

#endif
