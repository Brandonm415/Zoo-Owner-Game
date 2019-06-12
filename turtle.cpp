/***********************************************************
** Program name: Project 2
** Author: Brandon Mai
** Date: 4/26/2019
** Description: A zoo tycoon simulation game for one player.
**              Allows the user to play as the owner of a
**              zoo with up to 3 different animal types.
************************************************************/
#include "turtle.hpp"

//Default constructor
turtle::turtle()
{
    Cost = 100;
    BaseFoodCost = 5;
    PayOff = 5;
    NumberOfBabies = 10;
    numOfTurtles = 0;
    Age = 0;
}

//Initializing constructor
turtle::turtle(int x)
{
    Cost = 100;
    BaseFoodCost = 5;
    PayOff = 5;
    NumberOfBabies = 10;
    numOfTurtles = x;
    Age = 0;
}

//Get number of turtles function
int turtle::getNumOfTurtles()
{
    return numOfTurtles;
}

//Set number of turtles function with parameters
void turtle::setNumOfTurtles(int x)
{
    numOfTurtles = x;
}
