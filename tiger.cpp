/***********************************************************
** Program name: Project 2
** Author: Brandon Mai
** Date: 4/26/2019
** Description: A zoo tycoon simulation game for one player.
**              Allows the user to play as the owner of a
**              zoo with up to 3 different animal types.
************************************************************/
#include "tiger.hpp"

//Default constructor
tiger::tiger()
{
    Cost = 10000;
    numTigers = 0;
    BaseFoodCost = 50;
    PayOff = 2000;
    NumberOfBabies = 1;
    Age = 0;
}

//Initializing constructor
tiger::tiger(int x)
{
    Cost = 10000;
    numTigers = x;
    BaseFoodCost = 50;
    PayOff = 2000;
    NumberOfBabies = 1;
    Age = 0;
}

//Set number of tigers function with parameter
void tiger::setNumOfTigers(int x)
{
    numTigers = x;
}

//Get number of tigers function
int tiger::getNumOfTigers()
{
    return numTigers;
}


