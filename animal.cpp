/***********************************************************
** Program name: Project 2
** Author: Brandon Mai
** Date: 4/26/2019
** Description: A zoo tycoon simulation game for one player.
**              Allows the user to play as the owner of a
**              zoo with up to 3 different animal types.
************************************************************/
#include "animal.hpp"

//Default constructor
animal::animal()
{
}

//Get cost function
int animal::getCost()
{
    return Cost;
}

//Get base food cost function
int animal::getBaseFoodCost()
{
    return BaseFoodCost;
}

//Get number of babies function
int animal::getNumberOfBabies()
{
    return NumberOfBabies;
}

//Get pay off function
int animal::getPayOff()
{
    return PayOff;
}

//Age animal function
void animal::ageAnimal()
{
    Age++;
}

//Get animal age function
int animal::getAge()
{
    return Age;
}

//Set animal age function
void animal::setAge(int x)
{
    Age = x;
}
