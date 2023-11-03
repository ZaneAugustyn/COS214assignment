#ifndef _TAB_H
#define _TAB_H
// code here
class Tab
{
private:
    float TotalAmountOwed;
public:
    Tab(float amount);
    ~Tab();
    float getAmount() const;
};

#endif
