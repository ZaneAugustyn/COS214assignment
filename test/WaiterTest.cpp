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

// Create global variables for testing
Order *global_Menu;
Pass *global_Pass;
Group *global_Group;
Order *global_Order;
Order *global_CustomerOrder1;
Order *global_CustomerOrder2;
string global_errorMessage;

void createMockPass()
{
    global_Pass = new Pass();
}

void createMockGroup()
{
    global_Group = new Group(new ReadyToOrder(), 1);
    global_Group->addCustomer(new Customer("John"));
    global_Group->addCustomer(new Customer("Jane"));
}

void createMockMenu()
{
    global_Menu = new Order(NULL);
    // meats
    Order *meats = new Order(NULL);
    meats->addComponent(new ChickenPatty(true));
    meats->addComponent(new BeefPatty());

    // sides
    Order *sides = new Order(NULL);
    sides->addComponent(new Chips());
    sides->addComponent(new Salad());

    // garnish
    Order *garnish = new Order(NULL);
    garnish->addComponent(new Lettuce());
    garnish->addComponent(new Tomato());

    // drinks
    Order *drinks = new Order(NULL);
    drinks->addComponent(new Milkshake());
    drinks->addComponent(new Soda());

    global_Menu->addComponent(meats);
    global_Menu->addComponent(sides);
    global_Menu->addComponent(garnish);
    global_Menu->addComponent(drinks);
}

Waiter *createMockWaiter()
{
    Waiter *w = new Waiter("John", global_Pass);
    return w;
}

// Mock update function
void update(Group *group, Waiter *w, char languageChoice, int inputChoices[])
{
    if (group->GetState()->ToString() == "WaitForTable")
    {
        return;
    }
    else if (group->GetState()->ToString() == "ReadyToOrder")
    {
        // display menu to customers and get order
        LanguageAdapter *la = new LanguageAdapter();

        // iterate over customers
        for (Customer *customer : group->getCustomers())
        {
            Order *customerOrder = new Order(group);

            customerOrder->addComponent(new Bun());

            GroupIterator *iterator = global_Menu->createIterator();
            int i = 0;

            while (!iterator->isDone())
            {
                int choice = inputChoices[i];
                i++;

                while (!cin.good() || (choice != 1 && choice != 2)) // check that input is of type int
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    global_errorMessage = "WARNING! You entered the wrong menu option. Please try again.";
                    return;
                }
                customerOrder->addComponent((iterator->currentItem())->getItems()[choice - 1]);
                iterator->next();
            }
            global_Order->addComponent(customerOrder);
        }
        // global_Pass->addOrder(global_Order);
    }
    else if (group->GetState()->ToString() == "ReadyForBill")
    {
        // the waiter will take the group bill and display it
        cout << "You have to pay R " << (group->getBill())->getTotal() << endl;
        cout << "How would you like to pay it? 'S' to split, 'F' to pay in full, 'T' to put it on a tab" << endl;
        char c;
        // TODO: need to check inputs
        cin >> c;

        while ((c != 'S') && (c != 'F') && (c != 'T'))
        {
            cout << "WARNING! You entered the wrong bill option. Please try again." << endl;
            cout << "How would you like to pay it? 'S' to split, 'F' to pay in full, 'T' to put it on a tab" << endl;
            cin >> c;
        }

        if (group != NULL)
        {
            (group->getBill())->Pay(group, c);
        }
        else
        {
            cout << "There are no customers in this group to pay for the bill" << endl;
        }
    }
    else if (group->GetState()->ToString() == "PayTab")
    {
    }
}

TEST(BasicTests, getName)
{ 
    createMockPass();
    Waiter *w = createMockWaiter();
    string name = "John";
    EXPECT_EQ(
        name,
        w->getName());
}

TEST(TestUpdate, update)
{
    createMockMenu();
    createMockPass();
    createMockGroup();

    Waiter *w = createMockWaiter();

    // with valid int inputs
    global_Order = new Order(global_Group);
    update(global_Group, w, 'E', new int[5]{1, 1, 1, 1, 1});

    // check if order is built properly
    GroupIterator *it = global_Order->createIterator();
    int numOrders = 0;
    vector<OrderComponent *> customerOrder;
    while (!it->isDone())
    {
        numOrders++;

        customerOrder = it->currentItem()->getItems();
        EXPECT_EQ(
            5,
            customerOrder.size())
            << "Each order should have 5 items";
        it->next();
    }

    EXPECT_EQ(
        2,
        numOrders);

    // check with invalid int inputs
    global_Order = new Order(global_Group);
    update(global_Group, w, 'E', new int[5]{9, 8, 1, 1, 1});

    EXPECT_EQ(
        "WARNING! You entered the wrong menu option. Please try again.",
        global_errorMessage);

    // test with invalid language input
    global_Order = new Order(global_Group);
    update(global_Group, w, 'Z', new int[5]{1, 1, 1, 1, 1});
    // should work fine - default to english
    // check if order is built properly
    GroupIterator *it3 = global_Order->createIterator();
    numOrders = 0;
    while (!it3->isDone())
    {
        numOrders++;

        customerOrder = it3->currentItem()->getItems();
        EXPECT_EQ(
            5,
            customerOrder.size())
            << "Each order should have 5 items";
        it3->next();
    }

    EXPECT_EQ(
        2,
        numOrders);

}
