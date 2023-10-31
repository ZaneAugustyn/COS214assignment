#include <iostream>
using namespace std;

#include "Waiter.h"
#include "Group.h"
#include "Chef.h"
#include "Pass.h"

#include <vector>

int main() {
  cout<<"Hello world - this is my first commit!"<<endl;

  cout<<"Create waiters"<<endl;
  Waiter* waiterOne = new Waiter();
  Waiter* waiterTwo = new Waiter();
  Waiter* waiterThree = new Waiter();

  cout<<"Create waiter list"<<endl;
  vector<Waiter*> waiterList;
  waiterList.push_back(waiterOne);
  waiterList.push_back(waiterTwo);
  waiterList.push_back(waiterThree);

  cout<<"Create a group and assign waiter to a group"<<endl;
  Group* groupOne = new Group();
  groupOne->addWaiter(waiterOne);

  cout<<"Create the chef"<<endl;
  Chef* chef = new Chef();

  cout<<"Create the pass:"<<endl;
  Pass* passMediator = new Pass(waiterList, chef);

}