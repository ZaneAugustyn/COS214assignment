#include <iostream>
#include <string>
#include "Chef.h"
#include "HeadChef.h"
#include "MeatChef.h"
#include "DrinkChef.h"
#include "SidesChef.h"
#include "GarnishChef.h"
#include "OrderComponent.h"
#include <vector>
#include "Order.h"
#include "OrderItem.h"
#include "Group.h"
#include "Bun.h"
#include "ChickenPatty.h"
#include "BeefPatty.h"
#include "Chips.h"
#include "Salad.h"
#include "Soda.h"
#include "Milkshake.h"
#include "Tomato.h"
#include "Lettuce.h"
#include "ItemIterator.h"
#include "GroupIterator.h"
#include "Plate.h"
#include "Waiter.h"
#include "Pass.h"
#include "Colleague.h"
#include "Happy.h"
#include "facade.h"

using namespace std;

int main()
{
  facade instance;
  instance.run();  
    return 0;
}