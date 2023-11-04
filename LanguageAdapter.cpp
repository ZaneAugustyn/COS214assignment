#include "LanguageAdapter.h"
#include "OrderItem.h"

void LanguageAdapter::setOrderItems(OrderItem* orderitem)
{
  orderItem_ = orderitem;
}

string LanguageAdapter::getOrderItemInLanguage(char language)
{
  map<string, string> dictionary;
  dictionary["Beef Patty"] = "Beesvleis patty";
  dictionary["Bun"] = "Broodjie";
  dictionary["Chicken Patty"] = "Hoender patty";
  dictionary["Chips"] = "Skyfies";
  dictionary["Lettuce"] = "Blaarslaai";
  dictionary["Milkshake"] = "Melkskommel";
  dictionary["Chicken Patty"] = "Hoender patty";
  dictionary["Salad"] = "Slaai";
  dictionary["Soda"] = "Koeldrank";
  dictionary["Tomato"] = "Tamatie";

  if (language == 'A')
  {
    return dictionary[orderItem_->getName()];    
  }
  else // english is the default language
  {
    return orderItem_->getName();
  }
}
