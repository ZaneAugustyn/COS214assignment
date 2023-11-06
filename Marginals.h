#ifndef _MARGINALS_H
#define _MARGINALS_H

#include "PrintBill.h"
#include <iostream>
using namespace std;

/**
 * @class Marginals
 * @brief Will print the Marginals of the bill.
 */
class Marginals : public PrintBill
{
private:
    PrintBill* component_;
public:
    /**
     * @brief Constructor for the PrintBill class.
     * @param component the component to add to the printing of the bill.
     */
    Marginals(PrintBill* component);

    /**
     * @brief Virtual destructor for the OrderPrint class.
     */
    virtual ~Marginals();

    /**
     * @brief Perform the printing of the marginals.
     */
    virtual void Print();

};

#endif