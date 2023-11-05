#include "facade.h"

facade::facade(/* args */)
{
}

facade::~facade()
{
}

void facade::run()
{
    bool loop = true;
    int mostRecent = 0;
    while (loop)
    {
        int choice;
        cout<<"Welcome Le McDonalds please select on of the following options to begin: "<<endl;
        cout<<"1. Add a group to the queue outside"<<endl;
        if(mostRecent >= 1)
        {
            cout<<"2. Let a group inside the restaurant"<<endl;
        }
        if(mostRecent >= 2)
        {
            cout<<"3. Let a group order"<<endl;
        }
        if(mostRecent >= 3)
        {
            cout<<"4. Let a group pay the bill"<<endl;
        }
        if(mostRecent >= 4)
        {
            cout<<"5. Remove group from restaurant"<<endl;
        }
        if(mostRecent >= 5)
        {
            cout<<"6. Exit Simulation"<<endl;
        }
        cout<<"Please select an option : ";
        cin>>choice;
        if(choice > mostRecent)
        {
            mostRecent = choice;
        }


    }
    
}

void facade::option1()
{


}



void facade::option2()
{


}



void facade::option3()
{


}



void facade::option4()
{


}



void facade::option5()
{


}



void facade::option6()
{
    
}


