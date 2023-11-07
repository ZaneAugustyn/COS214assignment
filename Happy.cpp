#include "Happy.h"
#include "Unhappy.h"
#include "Neutral.h"

Happy::Happy()
{
    stateName_ = "Happy";    
}

Happy::~Happy()
{
}

void Happy::MakeUnhappy(Group *group)
{
    group->setLastEmotion(new Unhappy());
    
}

void Happy::MakeHappy(Group *group)
{
    cout << "Already in Happy state." << endl;
}

void Happy::MakeNeutral(Group *group)
{
    group->setLastEmotion(new Neutral());
}

string Happy::ToString()
{
    return this->stateName_;
}