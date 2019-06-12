/***********************************************************
** Program name: Project 2
** Author: Brandon Mai
** Date: 4/26/2019
** Description: A zoo tycoon simulation game for one player.
**              Allows the user to play as the owner of a
**              zoo with up to 3 different animal types.
************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"

//Zoo class starts the game and continues the game until the user loses or quits
//Contains private members and functions that assist with running the game
class zoo
{
    public:
        zoo();
        void start();
        void buyTiger();
        void buyPenguin();
        void buyTurtle();
        int getBank();

    private:
        int bank;
        int days;
        int tigerCapacity;
        int penguinCapacity;
        int turtleCapacity;
        int numOfTigers;
        int numOfPenguins;
        int numOfTurtles;
        int profitForDay;
        int totalTigers;
        int totalPenguins;
        int totalTurtles;

};

#endif // ZOO_HPP
