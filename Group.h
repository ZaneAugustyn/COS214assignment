#ifndef _GROUP_H
#define _GROUP_H

#include <vector>

using namespace std;

class Waiter;

class Group
{
  private:
    Waiter* waiter_;
    int groupNumber_;

  public:
    Group(int groupNumber);
    void addWaiter(Waiter* waiter);
    Waiter* getWaiter();
    ~Group();
    int getGroupNumber();
};

#endif
