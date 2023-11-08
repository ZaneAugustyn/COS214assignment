#include "Unhappy.h"
#include "Happy.h"
#include "Neutral.h"

Unhappy::Unhappy()
{
    stateName_ = "Unhappy";
}

Unhappy::~Unhappy()
{
}

void Unhappy::MakeUnhappy(Group *group)
{
    cout << "Currently in the Unhappy state" << endl;
}

void Unhappy::MakeHappy(Group *group)
{
    group->SetLastEmotion(new Happy());
}

void Unhappy::MakeNeutral(Group *group)
{
    group->SetLastEmotion(new Neutral());
}

string Unhappy::ToString()
{
    return this->stateName_;
}
