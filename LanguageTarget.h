#ifndef _LANGUAGETARGET_H
#define _LANGUAGETARGET_H

#include <string>

using namespace std;

class LanguageTarget
{
  private:

  public:
    virtual string getOrderItemInLanguage(string language, string wordToTranslate) = 0;
};


#endif