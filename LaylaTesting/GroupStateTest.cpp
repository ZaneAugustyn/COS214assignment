
#include "../Group.h"
#include "../GroupState.h"
#include "../Waiter.h"
#include "../WaitForTable.h"
#include "../Happy.h"
#include "../PayTab.h"
#include "../ReadyForBill.h"
#include "../ReadyToOrder.h"
#include "../Unhappy.h"
#include "../Neutral.h"
#include "../Order.h"
#include "../Pass.h"

#include "gtest/gtest.h"

using namespace std;

// Create global variables for testing
Group *global_Group;
Pass *global_Pass;
string global_errorMessage;

void createMockGroup(GroupState *state)
{
    global_Group = new Group(state, 1);
}

void createMockPass()
{
    global_Pass = new Pass();
}

Waiter *createMockWaiter()
{
    Waiter *w = new Waiter("John", global_Pass);
    return w;
}

void mockHappyStateUpdate(Group* group) {
    group->MakeHappy();
    string state = group->GetState()->ToString();
}

TEST(TestStateUpdate, mockHappyStateUpdate)
{ 
    createMockPass();
    Waiter *w = createMockWaiter();
    createMockGroup(new ReadyToOrder());

    mockHappyStateUpdate(global_Group);

    string expected_state = "Happy";

    EXPECT_EQ(
        expected_state,
        global_Group->GetState()->ToString()
        );

}

void mockUnhappyStateUpdate(Group* group) {
    group->MakeUnhappy();
    string state = group->GetState()->ToString();
}

TEST(TestStateUpdate1, mockUnhappyStateUpdate)
{ 
    createMockPass();
    Waiter *w = createMockWaiter();
    createMockGroup(new ReadyToOrder());
    global_Group->addWaiter(w);

    mockUnhappyStateUpdate(global_Group);

    string expected_state = "Unhappy";

    EXPECT_EQ(
        expected_state,
        global_Group->GetState()->ToString()
        );

}

