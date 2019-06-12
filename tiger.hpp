/***********************************************************
** Program name: Project 2
** Author: Brandon Mai
** Date: 4/26/2019
** Description: A zoo tycoon simulation game for one player.
**              Allows the user to play as the owner of a
**              zoo with up to 3 different animal types.
************************************************************/
#ifndef TIGER_HPP
#define TIGER_HPP
#include "animal.hpp"

//Tiger class contains information about tigers, inherits from animal class
class tiger : public animal
{
    public:
        tiger();
        tiger(int x);
        void setNumOfTigers(int x);
        int getNumOfTigers();

    protected:

    private:
        int numTigers;
};

#endif // TIGER_HPP
