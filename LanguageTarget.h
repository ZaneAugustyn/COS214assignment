#ifndef _LANGUAGETARGET_H
#define _LANGUAGETARGET_H

#include <string>
#include <map>
#include "OrderItem.h"

using namespace std;

class LanguageTarget
{
  private:

  public:
    virtual void setOrderItems(OrderItem* orderitem) = 0;
    virtual string getOrderItemInLanguage(char language) = 0;
};


#endif