#ifndef _TAB_H
#define _TAB_H

/**
 * @class Tab
 * @brief Represents a tab for tracking the total amount owed.
 */
class Tab
{
private:
    float TotalAmountOwed_; 
public:
    /**
     * @brief Constructor for the Tab class.
     * @param amount The initial total amount owed in the tab.
     */
    Tab(float amount);

    /**
     * @brief Destructor for the Tab class.
     */
    ~Tab();

    /**
     * @brief Get the current total amount owed in the tab.
     * @return The total amount owed in the tab.
     */
    float getAmount() const;
};

#endif
