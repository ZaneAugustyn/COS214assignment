#ifndef _HEADERBILL_H
#define _HEADERBILL_H

#include "Marginals.h"
#include <iostream>
using namespace std;

/**
 * @class HeaderBill
 * @brief Will print the Marginals of the bill.
 */
class HeaderBill : public Marginals
{
public:
    /**
     * @brief Constructor for the HeaderBill class.
     * @param component the component to add to the printing of the bill.
     */
    HeaderBill(PrintBill* component);

    /**
     * @brief Perform the printing of the marginals.
     */
    void Print();

};

#endif