#include "LanguageAdapter.h"
#include "OrderItem.h"

void LanguageAdapter::setOrderItems(OrderItem* orderitem)
{
  orderItem_ = orderitem;
}

string LanguageAdapter::getOrderItemInLanguage(string language)
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

  if (language == "E")
  {
    return orderItem_->getName();
  }
  else
  {
    return dictionary[orderItem_->getName()];
  }
}

