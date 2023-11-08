#include "Neutral.h"
#include "Happy.h"
#include "Unhappy.h"

Neutral::Neutral()
{
    stateName_ = "Neutral";
}

Neutral::~Neutral()
{
}

void Neutral::MakeUnhappy(Group *group)
{
    group->SetLastEmotion(new Unhappy());
}

void Neutral::MakeHappy(Group * group) 
{
    group->SetLastEmotion(new Happy());
}

void Neutral::MakeNeutral(Group *group)
{
    cout << "Already in Neutral state." << endl;
}

string Neutral::ToString()
{
    return this->stateName_;
}