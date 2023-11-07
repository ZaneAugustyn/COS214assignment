#ifndef _MAKETAB_H
#define _MAKETAB_H

#include <iostream>
#include "BillPayment.h"
#include "Group.h"
#include "Tab.h"

class Group;

using namespace std;

/**
 * @class MakeTab
 * @brief A class for handling tab payments in a group.
 */
class MakeTab : public BillPayment {
public:
    /**
     * @brief Constructor for creating a MakeTab instance.
     * @param t The total amount for the tab.
     */
    MakeTab(float t);

    /**
     * @brief Destructor for the MakeTab instance.
     */
    ~MakeTab();

    /**
     * @brief Create a tab with the specified total amount.
     * @param t The total amount for the tab.
     * @return The created Tab instance.
     */
    Tab* CreateTab(float t);

    /**
     * @brief Handle the tab payment for a group.
     * @param group The group for which the tab is being created.
     * @return void
     */
    void Pay(Group* group);

    /**
     * @brief Set the tab amount to a specified Tab instance.
     * @param tab The Tab instance to set the total amount for the tab.
     * @return void
     */
    void SetTab(Tab* tab);
};

#endif
