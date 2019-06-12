/***********************************************************
** Program name: Project 2
** Author: Brandon Mai
** Date: 4/26/2019
** Description: A zoo tycoon simulation game for one player.
**              Allows the user to play as the owner of a
**              zoo with up to 3 different animal types.
************************************************************/
#ifndef PENGUIN_HPP
#define PENGUIN_HPP
#include "animal.hpp"

//Penguins class contains information about penguins, inherits from animal class
class penguin : public animal
{
    public:
        penguin();
        penguin(int x);
        int getNumOfPenguins();
        void setNumOfPenguins(int x);

    protected:

    private:
        int numOfPenguins;
};

#endif // PENGUIN_HPP
