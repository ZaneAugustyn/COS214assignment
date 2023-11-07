#include "LanguageAdapter.h"
#include "OrderItem.h"

void LanguageAdapter::SetOrderItems(OrderItem* orderitem)
{
  orderItem_ = orderitem;
}

string LanguageAdapter::GetOrderItemInLanguage(char language)
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
    return dictionary[orderItem_->GetName()];    
  }
  else // english is the default language
  {
    return orderItem_->GetName();
  }
}
