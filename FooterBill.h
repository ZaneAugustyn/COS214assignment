#ifndef _FOOTERBILL_H
#define _FOOTERBILL_H

#include "Marginals.h"
#include <iostream>
using namespace std;

/**
 * @class FooterBill
 * @brief Will print the Marginals of the bill.
 */
class FooterBill : public Marginals
{
public:
    /**
     * @brief Constructor for the FooterBill class.
     * @param component the component to add to the printing of the bill.
     */
    FooterBill(PrintBill* component);

    /**
     * @brief Perform the printing of the marginals.
     */
    void Print();

};

#endif