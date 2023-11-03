#include "MakeTab.h"

MakeTab::MakeTab(float t) : BillPayment(t)
{
}

MakeTab::~MakeTab()
{
}

void MakeTab::Pay(Customer* customer)
{
    Tab* t1 = createTab(getTotal());
    customer->setTab(t1);
}

Tab* MakeTab::createTab(float t)
{
    Tab* tab = new Tab(t);
    return tab;
}

void MakeTab::setTab(Tab* tab)
{
    // set total amount owed to total for the bill
    setTotal(tab->getAmount());
}