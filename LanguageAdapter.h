#ifndef _LANGUAGEADAPTER_H
#define _LANGUAGEADAPTER_H

#include "LanguageTarget.h"
class OrderItem;

class LanguageAdapter : public LanguageTarget
{
  private:
    OrderItem* orderItem_;
  public:
    string getOrderItemInLanguage(string language, string wordToTranslate);
};

#endif