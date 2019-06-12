/***********************************************************
** Program name: Project 2
** Author: Brandon Mai
** Date: 4/26/2019
** Description: A zoo tycoon simulation game for one player.
**              Allows the user to play as the owner of a
**              zoo with up to 3 different animal types.
************************************************************/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

//Animal class contains protected member values such as age, cost, number of babies, base food cost, and pay off for all the animals
//Also contains get and set functions as needed
class animal
{
    public:
        animal();
        int getCost();
        int getBaseFoodCost();
        int getPayOff();
        int getNumberOfBabies();
        void ageAnimal();
        int getAge();
        void setAge(int x);

    protected:
        int Age;
        int Cost;
        int NumberOfBabies;
        int BaseFoodCost;
        int PayOff;

    private:
};

#endif // ANIMAL_HPP
