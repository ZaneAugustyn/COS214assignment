cmake_minimum_required(VERSION 3.16)

set(This UnitTesting) # set project name

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing() # enable unit testing

add_subdirectory(googletest) # add googletest library

set(Headers
    Floor.h
    FloorState.h
    Full.h
    SpaceAvailable.h
    MaitreD.h
    OrderComponent.h
    OrderItem.h
    Group.h
    Order.h
    GroupState.h
    Bun.h
    Patty.h
    Lettuce.h
    Tomato.h
    BeefPatty.h
    ChickenPatty.h
    Side.h
    Salad.h
    Chips.h
    Drink.h
    Soda.h
    Milkshake.h
    Garnish.h
    Chef.h
    HeadChef.h
    MeatChef.h
    DrinkChef.h
    SidesChef.h
    GarnishChef.h
    Pass.h
    Colleague.h
    Waiter.h
    WaitForTable.h
    Bill.h
    BillPayment.h
    Customer.h
    CustomerPays.h
    Happy.h
    MakeTab.h
    PayTab.h
    ReadyForBill.h
    ReadyToOrder.h
    SplitBill.h
    Tab.h
    Unhappy.h
    ItemIterator.h
    GroupIterator.h
    LanguageAdapter.h
    LanguageTarget.h
    Plate.h
    Neutral.h
    PrintBill.h
    Marginals.h
    OrderPrint.h
    HeaderBill.h
    FooterBill.h
)
set(Sources
    Floor.cpp
    FloorState.cpp
    Full.cpp
    SpaceAvailable.cpp
    MaitreD.cpp
    OrderComponent.cpp
    OrderItem.cpp
    Group.cpp
    Order.cpp
    GroupState.cpp
    Bun.cpp
    Patty.cpp
    Lettuce.cpp
    Tomato.cpp
    BeefPatty.cpp
    ChickenPatty.cpp
    Side.cpp
    Salad.cpp
    Chips.cpp
    Drink.cpp
    Soda.cpp
    Milkshake.cpp
    Garnish.cpp
    Chef.cpp
    HeadChef.cpp
    MeatChef.cpp
    DrinkChef.cpp
    SidesChef.cpp
    GarnishChef.cpp
    Pass.cpp
    Colleague.cpp
    Waiter.cpp
    WaitForTable.cpp
    Bill.cpp
    BillPayment.cpp
    Customer.cpp
    CustomerPays.cpp
    Happy.cpp
    MakeTab.cpp
    PayTab.cpp
    ReadyForBill.cpp
    ReadyToOrder.cpp
    SplitBill.cpp
    Tab.cpp
    Unhappy.cpp
    ItemIterator.cpp
    GroupIterator.cpp
    LanguageAdapter.cpp
    LanguageTarget.cpp
    Plate.cpp
    Neutral.cpp
    PrintBill.cpp
    Marginals.cpp
    OrderPrint.cpp
    HeaderBill.cpp
    FooterBill.cpp
)

add_library(${This} STATIC ${Sources} ${Headers}) # create static library

add_subdirectory(XadrianTesting) # add test directory
