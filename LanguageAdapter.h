#ifndef _LANGUAGEADAPTER_H
#define _LANGUAGEADAPTER_H

#include "LanguageTarget.h"

class OrderItem;

/**
 * @class LanguageAdapter
 * @brief Adapter class for translating order items into different languages.
 */
class LanguageAdapter : public LanguageTarget {
private:
    OrderItem* orderItem_; 

public:
    /**
     * @brief Set the order item to be translated.
     * @param orderItem The order item to be translated.
     * @return void
     */
    void SetOrderItems(OrderItem* orderItem);

    /**
     * @brief Get the translated order item in the specified language.
     * @param language The language code 
     * @return The translated order item.
     */
    string GetOrderItemInLanguage(char language);
};

#endif
