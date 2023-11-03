#include "Floor.h"
#include "FloorState.h"
#include "MaitreD.h"
#include "Group.h"
#include "Full.h"
#include "SpaceAvailable.h"

#include <array>
#include <iostream>
#include <string>
using namespace std;

#define YELLOW  "\033[33m"      /* Yellow */
#define RED     "\033[31m"      /* Red */
#define RESET   "\033[0m"
#define GREEN   "\033[32m"      /* Green */

void floorTest();

int main(){
    floorTest();
    return 0;
}

void floorTest()
{
    
    Floor* f1 = new Floor();
    cout<<"The current floor state is "<<f1->getCurrentState()->getName()<<endl;
    cout<<"Whould you like to set state to full(1) or SpaceAvailable(2): ";
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