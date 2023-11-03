#include "Floor.h"
#include "FloorState.h"
#include "MaitreD.h"
#include "Group.h"
#include "Full.h"
#include "SpaceAvailable.h"
#include "WaitForTable.h"
#include "ReadyToOrder.h"
#include "Happy.h"
#include "Unhappy.h"
#include "PayTab.h"
#include "ReadyForBill.h"


#include <array>
#include <iostream>
#include <string>
using namespace std;

#define YELLOW  "\033[33m"      /* Yellow */
#define RED     "\033[31m"      /* Red */
#define RESET   "\033[0m"
#define GREEN   "\033[32m"      /* Green */

void floorTest();
void TestRandomStates();
void TestHappyState();
void TestUnhappyState();
void TestWaitForTableState();
void TestPayTabState();
void TestReadyForBillState();
void TestReadyToOrderState();

int main(){
    floorTest();
    TestRandomStates();
    TestHappyState();
    TestUnhappyState();
    TestWaitForTableState();
    TestPayTabState();
    TestReadyForBillState();
    TestReadyToOrderState();
    return 0;
}

void floorTest()
{
    
    Floor* f1 = new Floor();
    cout<<"The current floor state is "<<f1->getCurrentState()->getName()<<endl;
    cout<<"Would you like to set state to full(1) or SpaceAvailable(2): ";
    int in = 0;
    cin>>in;
    if(in == 1)
    {
        f1->setCurrentState(new Full());
    }
    else if(in == 2)
    {
        f1->setCurrentState(new SpaceAvailable());
    }

    MaitreD* m1 = new MaitreD(f1);
    int testVar = 0;
    cout<<YELLOW<<"-------------------TESTING calculateTablesNeeded()--------------------------------"<<RESET<<endl;
    cout<<"Please enter testVar: ";
    cin>>testVar; 
    int testCase = m1->calculateTablesNeeded(testVar);
    cout<<"When there are "<<testVar<<" people we need "<<testCase<<" table(s)"<<endl;
    cout<<YELLOW<<"-------------------TESTING checkAvailability()--------------------------------"<<RESET<<endl;
    int groupSize = 0;
    cout<<"Please enter a group size: ";
    cin>>groupSize;
    bool outp = m1->checkAvailability(groupSize);
    if(outp == true)
    {
        cout<<GREEN<<"TRUE"<<RESET<<endl;
    }
    else
    {
        cout<<RED<<"FALSE"<<RESET<<endl;
    }

    cout<<YELLOW<<"-------------------TESTING checkCurrentFloorState()--------------------------------"<<RESET<<endl;
    bool outs = m1->checkCurrentFloorState(f1->getCurrentState());
    if(outs == true)
    {
        cout<<GREEN<<"TRUE (STATE IS SPACEAVAILABLE)"<<RESET<<endl;
    }
    else
    {
        cout<<RED<<"FALSE (STATE IS FULL)"<<RESET<<endl;
    }
    cout<<YELLOW<<"-------------------TESTING BASIC add and remove--------------------------------"<<RESET<<endl;
    // Group* g1 = new Group();
    // m1->addGroupToFloor(g1);
    // m1->removeGroupFromFloor(g1);
    
}

void TestRandomStates() 
{
    cout << "-------------------- Testing random states ---------------------\n";
    Group * group_ = new Group(new WaitForTable(), 1);
    Waiter * Steve_ = new Waiter("Steve");

    cout << group_->CurrentState() << endl;

    cout << "Change to ReadyToOrder\n\t";
    group_->RequestToOrder();
    cout << group_->CurrentState() << endl;

    cout << "Change to Happy\n\t";
    group_->MakeHappy();
    cout << group_->CurrentState() << endl;

    cout << "Change to Unhappy\n\t";
    group_->MakeUnhappy();
    cout << group_->CurrentState() << endl;

    cout << "Change to ReadyForBill\n\t";
    group_->RequestBill();
    cout << group_->CurrentState() << endl;

    cout << "Change to PayTab\n\t";
    group_->RequestTab();
    cout << group_->CurrentState() << endl;

    cout << "Change to PayTab\n\t";
    group_->RequestTab();
    cout << group_->CurrentState() << endl;

    cout << "Change to ReadyToOrder\n\t";
    group_->RequestToOrder();
    cout << group_->CurrentState() << endl;

    // reset back to WaitForTable state
    group_->SetState(new WaitForTable());
    // add a waiter
    group_->SetWaiter(Steve_);

    cout << "\nChange to PayTab\n\t";
    group_->RequestTab();
    cout << group_->CurrentState() << endl;

    cout << "Change to ReadyToOrder\n\t";
    group_->RequestToOrder();
    cout << group_->CurrentState() << endl;

    cout << "Change to Happy\n\t";
    group_->MakeHappy();
    cout << group_->CurrentState() << endl;

    cout << "Change to Unhappy\n\t";
    group_->MakeUnhappy();
    cout << group_->CurrentState() << endl;

    cout << "Change to WaitForTable\n\t";
    group_->WaitInQueue();
    cout << group_->CurrentState() << endl;

    cout << "Change to ReadyForBill\n\t";
    group_->RequestBill();
    cout << group_->CurrentState() << endl;

};

void TestHappyState() 
{
    cout << "\n-------------------- Testing states with initial state being Happy ---------------------\n";
    Group * group_ = new Group(new Happy(), 1);
    Waiter * steve_ = new Waiter("Steve");

    // if in Unhappy state: waiter has to be set
    group_->SetWaiter(steve_);

    cout << "Change to WaitForTable\n\t";
    group_->WaitInQueue();
    cout << group_->CurrentState() << endl;

    cout << "Change to PayTab\n\t";
    group_->RequestTab();
    cout << group_->CurrentState() << endl;

    cout << "Change to ReadyToOrder\n\t";
    group_->RequestToOrder();
    cout << group_->CurrentState() << endl;

    cout << "Reset - ";
    group_->MakeHappy();
    // cout << group_->CurrentState() << endl;
    cout << endl;

    cout << "Change to Unhappy\n\t";
    group_->MakeUnhappy();
    cout << group_->CurrentState() << endl;

    cout << "Reset - ";
    group_->MakeHappy();
    // cout << group_->CurrentState() << endl;
    cout << endl;

    cout << "Change to ReadyForBill\n\t";
    group_->RequestBill();
    cout << group_->CurrentState() << endl;

    cout << "Reset - ";
    group_->MakeHappy();
    
};

void TestUnhappyState() 
{
    cout << "\n\n-------------------- Testing states with initial state being Unhappy ---------------------\n";
    Group * group_ = new Group(new Unhappy(), 1);
    Waiter * steve_ = new Waiter("Steve");

    // if in Unhappy state: waiter has to be set
    group_->SetWaiter(steve_);

    cout << "Change to WaitForTable\n\t";
    group_->WaitInQueue();
    cout << group_->CurrentState() << endl;

    cout << "Change to PayTab\n\t";
    group_->RequestTab();
    cout << group_->CurrentState() << endl;

    cout << "Change to ReadyToOrder\n\t";
    group_->RequestToOrder();
    cout << group_->CurrentState() << endl;

    cout << "Reset - ";
    group_->MakeUnhappy();
    // cout << group_->CurrentState() << endl;
    cout << endl;

    cout << "Change to Happy\n\t";
    group_->MakeHappy();
    cout << group_->CurrentState() << endl;

    cout << "Reset - ";
    group_->MakeUnhappy();
    // cout << group_->CurrentState() << endl;
    cout << endl;

    cout << "Change to ReadyForBill\n\t";
    group_->RequestBill();
    cout << group_->CurrentState() << endl;

    cout << "Reset - ";
    group_->MakeUnhappy();
    
};

void TestWaitForTableState() 
{
    cout << "\n\n-------------------- Testing states with initial state being WaitForTable ---------------------\n";
    Group * group1_ = new Group(new WaitForTable(), 1);
    Group * group2_ = new Group(new WaitForTable(), 2);
    Waiter * steve_ = new Waiter("Steve");

    // if in WaitForTable state: waiter must not be set
    // group_->SetWaiter(steve_);

    cout << "Change to WaitForTable\n\t";
    group1_->WaitInQueue();
    cout << group1_->CurrentState() << endl;

    cout << "Change to PayTab\n\t";
    group1_->RequestTab();
    cout << group1_->CurrentState() << endl;

    cout << "Change to Happy\n\t";
    group1_->MakeHappy();
    cout << group1_->CurrentState() << endl;

    cout << "Change to ReadyToOrder" << endl;
    cout << "\t";
    group2_->RequestToOrder();
    cout << group2_->CurrentState() << endl;

    // set the waiter
    group2_->SetWaiter(steve_);

    cout << "Change to Happy\n\t";
    group2_->MakeHappy();
    cout << group2_->CurrentState() << endl;

    cout << "Reset - ";
    group2_->RequestToOrder();
    cout << endl;

    cout << "Change to ReadyForBill\n\t";
    group2_->RequestBill();
    cout << group2_->CurrentState() << endl;

    cout << "Change to RequestToOrder\n\t ";
    group2_->RequestToOrder();
    cout << endl;

};

void TestPayTabState() 
{
    cout << "\n\n-------------------- Testing states with initial state being PayTab ---------------------\n";
    Group * group1_ = new Group(new PayTab(), 1);
    Waiter * steve_ = new Waiter("Steve");

    cout << "Change to WaitForTable\n\t";
    group1_->WaitInQueue();
    cout << group1_->CurrentState() << endl;

    cout << "Change to PayTab\n\t";
    group1_->RequestTab();
    cout << group1_->CurrentState() << endl;

    cout << "Change to Happy\n\t";
    group1_->MakeHappy();
    cout << group1_->CurrentState() << endl;

    cout << "Change to ReadyToOrder" << endl;
    cout << "\t";
    group1_->RequestToOrder();
    cout << group1_->CurrentState() << endl;

    // set the waiter
    group1_->SetWaiter(steve_);

    cout << "Change to Happy\n\t";
    group1_->MakeHappy();
    cout << group1_->CurrentState() << endl;

    cout << "Reset - ";
    group1_->RequestToOrder();
    cout << endl;

    cout << "Change to ReadyForBill\n\t";
    group1_->RequestBill();
    cout << group1_->CurrentState() << endl;

    cout << "Change to RequestToOrder\n\t ";
    group1_->RequestToOrder();
    cout << endl;

};

void TestReadyForBillState() 
{
    cout << "\n-------------------- Testing states with initial state being ReadyForBill ---------------------\n";
    Group * group_ = new Group(new ReadyForBill(), 1);
    Waiter * steve_ = new Waiter("Steve");

    // if in Unhappy state: waiter has to be set
    group_->SetWaiter(steve_);

    cout << "Change to WaitForTable\n\t";
    group_->WaitInQueue();
    cout << group_->CurrentState() << endl;

    cout << "Change to PayTab\n\t";
    group_->RequestTab();
    cout << group_->CurrentState() << endl;

    cout << "Change to ReadyToOrder\n\t";
    group_->RequestToOrder();
    cout << group_->CurrentState() << endl;

    cout << "Reset - ";
    group_->RequestBill();
    // cout << group_->CurrentState() << endl;
    cout << endl;

    cout << "Change to Unhappy\n\t";
    group_->MakeUnhappy();
    cout << group_->CurrentState() << endl;

    cout << "Reset - ";
    group_->RequestBill();
    // cout << group_->CurrentState() << endl;
    cout << endl;

    cout << "Change to ReadyForBill\n\t";
    group_->RequestBill();
    cout << group_->CurrentState() << endl;

    cout << "Change to ReadyToOrder\n\t";
    group_->RequestToOrder();
    cout << group_->CurrentState() << endl;

    cout << "Reset - ";
    group_->RequestBill();
    
};

void TestReadyToOrderState() 
{
    cout << "\n-------------------- Testing states with initial state being ReadyToOrder ---------------------\n";
    Group * group_ = new Group(new ReadyToOrder(), 1);
    Waiter * steve_ = new Waiter("Steve");

    // if in ReadyToOrder state: waiter has to be set
    group_->SetWaiter(steve_);

    cout << "Change to WaitForTable\n\t";
    group_->WaitInQueue();
    cout << group_->CurrentState() << endl;

    cout << "Change to PayTab\n\t";
    group_->RequestTab();
    cout << group_->CurrentState() << endl;

    cout << "Change to ReadyToOrder\n\t";
    group_->RequestToOrder();
    cout << group_->CurrentState() << endl;

    cout << "Reset - ";
    group_->RequestToOrder();
    // cout << group_->CurrentState() << endl;
    cout << endl;

    cout << "Change to Unhappy\n\t";
    group_->MakeUnhappy();
    cout << group_->CurrentState() << endl;

    cout << "Reset - ";
    group_->RequestToOrder();
    // cout << group_->CurrentState() << endl;
    cout << endl;

    cout << "Change to ReadyForBill\n\t";
    group_->RequestBill();
    cout << group_->CurrentState() << endl;

    cout << "Change to ReadyToOrder\n\t";
    group_->RequestToOrder();
    cout << group_->CurrentState() << endl;
    
};
