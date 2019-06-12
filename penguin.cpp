/***********************************************************
** Program name: Project 2
** Author: Brandon Mai
** Date: 4/26/2019
** Description: A zoo tycoon simulation game for one player.
**              Allows the user to play as the owner of a
**              zoo with up to 3 different animal types.
************************************************************/
#include "penguin.hpp"

//Default constructor
penguin::penguin()
{
    Cost = 1000;
    BaseFoodCost = 10;
    PayOff = 100;
    NumberOfBabies = 5;
    numOfPenguins = 0;
    Age = 0;
}

//Initializing constructor
penguin::penguin(int x)
{
    Cost = 1000;
    BaseFoodCost = 10;
    PayOff = 100;
    NumberOfBabies = 5;
    numOfPenguins = x;
    Age = 0;
}

//Get number of penguins function
int penguin::getNumOfPenguins()
{
    return numOfPenguins;
}

//Set number of penguins function with parameter
void penguin::setNumOfPenguins(int x)
{
    numOfPenguins = x;
}
