#include "../Floor.h"
#include "../FloorState.h"
#include "../Full.h"
#include "../SpaceAvailable.h"
#include "../MaitreD.h"
#include "../OrderComponent.h"
#include "../OrderItem.h"
#include "../Group.h"
#include "../GroupState.h"
#include "../Bun.h"
#include "../Patty.h"
#include "../BeefPatty.h"
#include "../ChickenPatty.h"
#include "../Side.h"
#include "../Salad.h"
#include "../Chips.h"
#include "../Drink.h"
#include "../Milkshake.h"
#include "../Soda.h"
#include "../Garnish.h"
#include "../Lettuce.h"
#include "../Tomato.h"
#include "../Chef.h"
#include "../HeadChef.h"
#include "../MeatChef.h"
#include "../DrinkChef.h"
#include "../SidesChef.h"
#include "../GarnishChef.h"
#include "../Pass.h"
#include "../Colleague.h"
#include "../Waiter.h"
#include "../WaitForTable.h"
#include "../Bill.h"
#include "../BillPayment.h"
#include "../Customer.h"
#include "../CustomerPays.h"
#include "../Happy.h"
#include "../MakeTab.h"
#include "../PayTab.h"
#include "../ReadyForBill.h"
#include "../ReadyToOrder.h"
#include "../SplitBill.h"
#include "../Tab.h"
#include "../Unhappy.h"
#include "../Neutral.h"
#include "../Order.h"

#include "gtest/gtest.h"

using namespace std;

TEST(AdapterTestAfrikaans, getOrderItemInLanguage)
{
  string name = "Tamatie";
  LanguageTarget* target = new LanguageAdapter();
  target->setOrderItems(new Tomato());
  EXPECT_EQ(
    name,     
    target->getOrderItemInLanguage('A')
  );
}

TEST(AdapterTestEnglish, getOrderItemInLanguage)
{
  string name = "Lettuce";
  LanguageTarget* target = new LanguageAdapter();
  target->setOrderItems(new Lettuce());
  EXPECT_EQ(
    name,     
    target->getOrderItemInLanguage('E')
  );
}