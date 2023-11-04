#ifndef _LANGUAGETARGET_H
#define _LANGUAGETARGET_H

#include <string>
#include <map>
#include "OrderItem.h"

using namespace std;

/**
 * @class LanguageTarget
 * @brief Abstract class for translating order items into different languages.
 */
class LanguageTarget {
public:
    /**
     * @brief Set the order item to be translated.
     * @param orderItem The order item to be translated.
     */
    virtual void setOrderItems(OrderItem* orderItem) = 0;

    /**
     * @brief Get the translated order item in the specified language.
     * @param language The language code
     * @return The translated order item.
     */
    virtual string getOrderItemInLanguage(char language) = 0;
};

#endif
