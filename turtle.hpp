/***********************************************************
** Program name: Project 2
** Author: Brandon Mai
** Date: 4/26/2019
** Description: A zoo tycoon simulation game for one player.
**              Allows the user to play as the owner of a
**              zoo with up to 3 different animal types.
************************************************************/
#ifndef TURTLE_HPP
#define TURTLE_HPP
#include "animal.hpp"

//Turtle class contains information about turtles, inherits from animal class
class turtle : public animal
{
    public:
        turtle();
        turtle(int x);
        int getNumOfTurtles();
        void setNumOfTurtles(int x);

    protected:

    private:
        int numOfTurtles;
};

#endif // TURTLE_HPP
