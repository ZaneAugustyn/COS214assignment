#ifndef _CHEF_H
#define _CHEF_H

#include "../Plate.h"


class Chef
{
private:
    Chef* nextChef_;
public:
    Chef(/* args */); 
    ~Chef();
    void HandleOrder(Plate* plate);
};

#endif
