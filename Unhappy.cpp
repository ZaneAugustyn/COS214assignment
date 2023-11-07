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
    group->setLastEmotion(new Happy());
}

void Unhappy::MakeNeutral(Group *group)
{
    group->setLastEmotion(new Neutral());
}

string Unhappy::ToString()
{
    return this->stateName_;
}
