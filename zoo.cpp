/***********************************************************
** Program name: Project 2
** Author: Brandon Mai
** Date: 4/26/2019
** Description: A zoo tycoon simulation game for one player.
**              Allows the user to play as the owner of a
**              zoo with up to 3 different animal types.
************************************************************/
#include "zoo.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>

//Default constructor
zoo::zoo()
{
    bank = 100000;
    numOfTigers = 0;
    numOfPenguins = 0;
    numOfTurtles = 0;
    tigerCapacity = 10;
    penguinCapacity = 10;
    turtleCapacity = 10;
    profitForDay = 0;
    totalTigers = 0;
    totalPenguins = 0;
    totalTurtles = 0;
}

//Starts the game and runs it through all the way until the end of the game
void zoo::start()
{
    //Initial display screen
    std::cout << "Welcome to the Zoo Tycoon Game!" << std::endl;
    std::cout << "You will start off with $100,00 and the game will end when you run out of money." << std::endl;
    std::cout << "You must purchase at least one of every animal and at most two of the same type." << std::endl;

    //Dynamic arrays for animals is set up
    tiger *tigerArray = new tiger[tigerCapacity];
    penguin *penguinArray = new penguin[penguinCapacity];
    turtle *turtleArray = new turtle[turtleCapacity];


    //Ask user to buy starting tigers with input validation
    std::cout << "How many Tigers would you like to purchase? Tigers are $10,000 each. Enter 1 or 2." << std::endl;
    int counter = 0;
    while(counter < 1)
    {
        std::cin >> numOfTigers;
        //Adapted from: http://www.cplusplus.com/forum/beginner/58833/
        //Checks if integer is entered or not
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "That is not a valid option. Please enter a valid option." << std::endl;
            std::cout << "How many Tigers would you like to purchase? Tigers are $10,000 each. Enter 1 or 2." << std::endl;
        }
        //If integer is entered checks if it matches options
        else
        {
            //If integer entered matches possible choices end the loop
            if(numOfTigers == 1 || numOfTigers == 2)
            {
                counter++;
                if(numOfTigers == 1)
                {
                    //Buy tiger and subtract money from bank
                    buyTiger();
                    //Adds 1 to number of tigers for object 1
                    tigerArray[0].setNumOfTigers(1);
                    //Add 1 to total tiger counter
                    totalTigers++;
                }
                else
                {
                    //Buy tiger twice
                    buyTiger();
                    buyTiger();
                    //Add 1 to number of tigers for object 1+2
                    tigerArray[0].setNumOfTigers(1);
                    tigerArray[1].setNumOfTigers(1);
                    //Add 2 to total tiger counter
                    totalTigers++;
                    totalTigers++;
                }
            }
            //Repeat the loop if integer does not match possible choices
            else
            {
                std::cout << "That is not a valid option. Please enter a valid option." << std::endl;
                std::cout << "How many Tigers would you like to purchase? Tigers are $10,000 each. Enter 1 or 2." << std::endl;
            }
        }
    }

    //Ask user to buy starting penguins with input validation
    std::cout << "How many penguins would you like to purchase? Penguins are $1,000 each. Enter 1 or 2." << std::endl;
    counter = 0;
    while(counter < 1)
    {
        std::cin >> numOfPenguins;
        //Adapted from: http://www.cplusplus.com/forum/beginner/58833/
        //Checks if integer is entered or not
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "That is not a valid option. Please enter a valid option." << std::endl;
            std::cout << "How many Penguins would you like to purchase? Penguins are $1,000 each. Enter 1 or 2." << std::endl;
        }
        //If integer is entered checks if it matches options
        else
        {
            //If integer entered matches possible choices end the loop
            if(numOfPenguins == 1 || numOfPenguins == 2)
            {
                counter++;
                if(numOfPenguins == 1)
                {
                    buyPenguin();
                    penguinArray[0].setNumOfPenguins(1);
                    totalPenguins++;
                }
                else
                {
                    buyPenguin();
                    buyPenguin();
                    penguinArray[0].setNumOfPenguins(1);
                    penguinArray[1].setNumOfPenguins(1);
                    totalPenguins++;
                    totalPenguins++;
                }
            }
            //Repeat the loop if integer does not match possible choices
            else
            {
                std::cout << "That is not a valid option. Please enter a valid option." << std::endl;
                std::cout << "How many Penguins would you like to purchase? Penguins are $1,000 each. Enter 1 or 2." << std::endl;
            }
        }
    }


    //Ask user to buy starting turtles with input validation
    std::cout << "How many Turtles would you like to purchase? Turtles are $100 each. Enter 1 or 2." << std::endl;
    counter = 0;
    while(counter < 1)
    {
        std::cin >> numOfTurtles;
        //Adapted from: http://www.cplusplus.com/forum/beginner/58833/
        //Checks if integer is entered or not
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "That is not a valid option. Please enter a valid option." << std::endl;
            std::cout << "How many Turtles would you like to purchase? Turtles are $100 each. Enter 1 or 2." << std::endl;
        }
        //If integer is entered checks if it matches options
        else
        {
            //If integer entered matches possible choices end the loop
            if(numOfTurtles == 1 || numOfTurtles == 2)
            {
                counter++;
                if(numOfTurtles == 1)
                {
                    buyTurtle();
                    turtleArray[0].setNumOfTurtles(1);
                    totalTurtles++;
                }
                else
                {
                    buyTurtle();
                    buyTurtle();
                    turtleArray[0].setNumOfTurtles(1);
                    turtleArray[1].setNumOfTurtles(1);
                    totalTurtles++;
                    totalTurtles++;
                }
            }
            //Repeat the loop if integer does not match possible choices
            else
            {
                std::cout << "That is not a valid option. Please enter a valid option." << std::endl;
                std::cout << "How many Turtles would you like to purchase? Turtles are $100 each. Enter 1 or 2." << std::endl;
            }
        }
    }

    //Get ready to start the game
    int endGameCounter = 0;
    while(endGameCounter < 1)
    {
        //Game officially starts, add one to day counter and Feed animals
        days++;
        int tigerFeed = 0;
        int totalFeed = 0;
        //Loop through tigers and feed tigers that are in the array
        for(int i = 0; i < tigerCapacity; i++)
        {
            if(tigerArray[i].getNumOfTigers() == 1)
            {
                tigerFeed++;
            }
        }
        totalFeed = (tigerFeed * 50);
        //Loop through penguins and feed them if they are in the array
        int penguinFeed = 0;
        for(int i = 0; i < penguinCapacity; i++)
        {
            if(penguinArray[i].getNumOfPenguins() == 1)
            {
                penguinFeed++;
            }
        }
        totalFeed = totalFeed + (penguinFeed * 10);
        //Loop through turtles and feed them if they are in the array
        int turtleFeed = 0;
        for(int i = 0; i < turtleCapacity; i++)
        {
            if(turtleArray[i].getNumOfTurtles() == 1)
            {
                turtleFeed++;
            }
        }
        //Calculate how much it cost to feed all animals
        totalFeed = totalFeed + (turtleFeed * 5);
        //Calculate total cost of feeding all animals from bank
        bank = bank - totalFeed;

        //Age all animals by 1
        for(int i = 0; i < tigerCapacity; i++)
        {
            if(tigerArray[i].getNumOfTigers() == 1)
            {
                tigerArray[i].ageAnimal();
            }
        }
        for(int i = 0; i < penguinCapacity; i++)
        {
            if(penguinArray[i].getNumOfPenguins() == 1)
            {
                penguinArray[i].ageAnimal();
            }
        }
        for(int i = 0; i < turtleCapacity; i++)
        {
            if(turtleArray[i].getNumOfTurtles() == 1)
            {
                turtleArray[i].ageAnimal();
            }
        }

        //Random event starts
        srand(time(0));
        int bonus = 0;
        //Random event is picked
        int random = rand() % 4 + 1;
        //Sickness event
        if(random == 1)
        {
            //randomly pick an animal type
            int deadAnimal = rand() % 3 + 1;
            //If tiger is picked
            if(deadAnimal == 1)
            {
                //Check if there are any tigers to kill
                if(totalTigers > 0)
                {
                    //Pick a random tiger
                    int deadTiger = rand() % --tigerCapacity + 0;
                    //If random tiger is not selected loop until it is or nothing happens if there are no tigers
                    while(tigerArray[deadTiger].getNumOfTigers() == 0)
                    {
                        deadTiger = rand() % --tigerCapacity + 0;
                    }
                    //Kill the tiger
                    tigerArray[deadTiger].setNumOfTigers(0);
                    //Subtract 1 from total tigers
                    totalTigers--;
                    std::cout << "A tiger died." << std::endl;
                }
                else
                {
                    std::cout << "There are no tigers to die from sickness." << std::endl;
                }
            }
            //If penguin is picked
            else if(deadAnimal == 2)
            {
                //Check if there are penguins to kill
                if(totalPenguins > 0)
                {
                    //Pick a random penguin
                    int deadPenguin = rand() % --penguinCapacity + 0;
                    //If random penguin is not selected loop until it is or nothing happens if there are no penguins
                    while(penguinArray[deadPenguin].getNumOfPenguins() == 0)
                    {
                        deadPenguin = rand() % --penguinCapacity + 0;
                    }
                    //Kill penguin
                    penguinArray[deadPenguin].setNumOfPenguins(0);
                    totalPenguins--;
                    std::cout << "A penguin died." << std::endl;
                }
                else
                {
                    std::cout << "There are no penguins to die from sickness." << std::endl;
                }
            }
            //If turtle is picked
            else if(deadAnimal == 3)
            {
                //Check if there are turtles to kill
                if(totalTurtles > 0)
                {
                    //pick a random turtle
                    int deadTurtle = rand() % --turtleCapacity + 0;
                    //Loop until random turtle is selected
                    while(turtleArray[deadTurtle].getNumOfTurtles() == 0)
                    {
                        deadTurtle = rand() % --turtleCapacity + 0;
                    }
                    //Kill turtle
                    turtleArray[deadTurtle].setNumOfTurtles(0);
                    totalTurtles--;
                    std::cout << "A turtle died." << std::endl;
                }
                else
                {
                    std::cout << "There are no turtles to die from sickness." << std::endl;
                }
            }
        }
        //Attendance event
        else if(random == 2)
        {
            //Bonus is randomly generated
            bonus = rand() % 500 + 250;
            int tigerCounter = 0;
            //Count how many tigers
            for(int i = 0; i < tigerCapacity; i++)
            {
                if(tigerArray[i].getNumOfTigers() == 1)
                {
                    tigerCounter++;
                }
            }
            //Calculate bonus
            bonus = bonus * tigerCounter;
            //Add to bank
            bank = bank + bonus;
            std::cout << "Tigers attracted more people today, a bonus of " << bonus << " was added to your bank." << std::endl;
        }
        //Baby animal event
        else if(random == 3)
        {
            //Pick random animal type
            int babyAnimal = rand() % 3 + 1;
            //If tiger
            if(babyAnimal == 1)
            {
                int babyTiger = 0;
                //Loop through tigers to see if there is tiger older than 3
                for(int i = 0; i < tigerCapacity; i++)
                {
                    //If tiger is older than 3
                    if(tigerArray[i].getAge() >= 3)
                    {
                        babyTiger++;
                    }
                }
                if(babyTiger > 0)
                {
                    //resize array before adding new tigers
                    tigerCapacity = tigerCapacity * 2;
                    tiger *newArr = new tiger[tigerCapacity];
                    for(int i = 0; i < tigerCapacity; i++)
                    {
                        newArr[i] = tigerArray[i];
                    }
                    delete[] tigerArray;
                    tigerArray = newArr;

                    //Add a tiger to empty slot in array
                    int j = 0;
                    while(tigerArray[j].getNumOfTigers() == 1)
                    {
                        j++;
                    }
                    tigerArray[j].setNumOfTigers(1);
                    totalTigers++;
                    std::cout << "A baby tiger is born!" << std::endl;
                }
                else
                {
                    std::cout << "No baby tiger is born." << std::endl;
                }
            }
            //If penguin
            else if(babyAnimal == 2)
            {
                int babyPenguin = 0;
                //Loop through penguins to find penguin age > 3
                for(int i = 0; i < penguinCapacity; i++)
                {
                    //If penguin is older than 3
                    if(penguinArray[i].getAge() >= 3)
                    {
                        babyPenguin++;
                    }
                }
                if(babyPenguin > 0)
                {
                    //resize array before adding penguins
                    penguinCapacity = penguinCapacity * 2;
                    penguin *newArr = new penguin[penguinCapacity];
                    for(int i = 0; i < penguinCapacity; i++)
                    {
                        newArr[i] = penguinArray[i];
                    }
                    delete[] penguinArray;
                    penguinArray = newArr;

                    //Add 5 penguins to array
                    for(int i = 0; i < 5; i++)
                    {
                        int j = 0;
                        while(penguinArray[j].getNumOfPenguins() == 1)
                        {
                            j++;
                        }
                        totalPenguins++;
                        penguinArray[j].setNumOfPenguins(1);
                    }
                    std::cout << "5 baby penguins were born!" << std::endl;
                }
                else
                {
                    std::cout << "No baby penguin is born." << std::endl;
                }
            }
            //If turtle
            else if(babyAnimal == 3)
            {
                int babyTurtle = 0;
                //Loop through turtles to find turtle age > 3
                for(int i = 0; i < turtleCapacity; i++)
                {
                    //If turtle is found
                    if(turtleArray[i].getAge() >= 3)
                    {
                        babyTurtle++;
                    }
                }
                if(babyTurtle > 0)
                {
                    //Resize array before adding turtles
                    turtleCapacity = turtleCapacity * 2;
                    turtle *newArr = new turtle[turtleCapacity];
                    for(int i = 0; i < turtleCapacity; i++)
                    {
                        newArr[i] = turtleArray[i];
                    }
                    delete[] turtleArray;
                    turtleArray = newArr;

                    //Add 10 turtles to array
                    for(int i = 0; i < 10; i++)
                    {
                        int j = 0;
                        while(turtleArray[j].getNumOfTurtles() == 1)
                        {
                            j++;
                        }
                        totalTurtles++;
                        turtleArray[j].setNumOfTurtles(1);
                    }
                    std::cout <<  "10 baby turtles were born!" << std::endl;
                }
                else
                {
                    std::cout << "No baby turtle is born." << std::endl;
                }
            }
        }
        //No event happens
        else
        {
            std::cout << "No event." << std::endl;
        }

        //End turn and calculate profits
        //Set up class objects
        tiger tig;
        penguin pen;
        turtle tur;
        //Integers for counting number of tigers
        int tigerCounter = 0;
        int penguinCounter = 0;
        int turtleCounter = 0;
        //Profit for day reset to 0 every new turn
        profitForDay = 0;
        //Find number of tigers
        for(int i = 0; i < tigerCapacity; i++)
        {
            if(tigerArray[i].getNumOfTigers() == 1)
            {
                tigerCounter++;
            }
        }
        //Calculate tiger profits
        profitForDay = profitForDay + (tigerCounter * tig.getPayOff());
        //Find number of penguins
        for(int i = 0; i < penguinCapacity; i++)
        {
            if(penguinArray[i].getNumOfPenguins() == 1)
            {
                penguinCounter++;
            }
        }
        //Calculate penguin profits
        profitForDay = profitForDay + (penguinCounter * pen.getPayOff());
        //Find number of turtles
        for(int i = 0; i < turtleCapacity; i++)
        {
            if(turtleArray[i].getNumOfTurtles() == 1)
            {
                turtleCounter++;
            }
        }
        //Calculate turtle profits
        profitForDay = profitForDay + (turtleCounter * tur.getPayOff());
        //Add totals to bank
        bank = profitForDay + bank;

        //Ask if user would like to buy a new animal
        int buyNewAnimal;
        std::cout << "Animal payoff today: " << profitForDay << std::endl;
        std::cout << "Animal feed cost today: " << totalFeed << std::endl;
        std::cout << "Net profit today: " << profitForDay - totalFeed << std::endl;
        std::cout << "Current money: " << bank << std::endl;
        std::cout << "Current number of Tigers: " << totalTigers << std::endl;
        std::cout << "Current number of Penguins: " << totalPenguins << std::endl;
        std::cout << "Current number of Turtles: " << totalTurtles << std::endl;
        std::cout << "Would you like to buy a new animal?" << std::endl;
        std::cout << "Press 1 if you do, and press 2 if you don't." << std::endl;
        std::cin >> buyNewAnimal;
        counter = 0;
        int counter2 = 0;
        //Input validation loop
        while(counter < 1)
        {
            //input validation
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "That is not a valid option. Please enter a valid option." << std::endl;
                std::cout << "Press 1 if you do, and press 2 if you don't." << std::endl;
                std::cin >> buyNewAnimal;
            }
            //If integer is entered checks if it matches options
            else
            {
                //If 1 is entered buy new animal
                if(buyNewAnimal == 1)
                {
                    int pickAnimal;
                    counter++;
                    std::cout << "What kind of animal would you like to buy? Enter 1, 2, or 3" << std::endl;
                    std::cout << "1. Tiger for $10,000." << std::endl;
                    std::cout << "2. Penguin for $1,000." << std::endl;
                    std::cout << "3. Turtle for $100." << std::endl;
                    std::cin >> pickAnimal;
                    counter = 0;
                    //Input validation
                    while(counter2 < 1)
                    {
                        if(std::cin.fail())
                        {
                            std::cin.clear();
                            std::cin.ignore();
                            std::cout << "That is not a valid option. Please enter a valid option." << std::endl;
                            std::cout << "1. Tiger for $10,000." << std::endl;
                            std::cout << "2. Penguin for $1,000." << std::endl;
                            std::cout << "3. Turtle for $100." << std::endl;
                            std::cin >> pickAnimal;
                        }
                        else
                        {
                            //If tiger
                            if(pickAnimal == 1)
                            {
                                //Check if tigers are almost at max capacity
                                if(totalTigers >= tigerCapacity - 2)
                                {
                                    //Resize array
                                    tigerCapacity = tigerCapacity * 2;
                                    tiger *newArr = new tiger[tigerCapacity];
                                    for(int i = 0; i < tigerCapacity; i++)
                                    {
                                        newArr[i] = tigerArray[i];
                                    }
                                    delete[] tigerArray;
                                    tigerArray = newArr;
                                }
                                //Find empty slot for new tiger
                                int tigerBuy = 0;
                                while(tigerArray[tigerBuy].getNumOfTigers() == 1)
                                {
                                    tigerBuy++;
                                }
                                //Buy the tiger and set age to 3
                                tigerArray[tigerBuy].setNumOfTigers(1);
                                tigerArray[tigerBuy].setAge(3);
                                buyTiger();
                                //Add one to total tiger count
                                totalTigers++;
                                counter++;
                                counter2++;
                            }
                            //If penguin
                            else if(pickAnimal == 2)
                            {
                                //Check if penguin is almost at max capacity
                                if(totalPenguins >= penguinCapacity - 5)
                                {
                                    //Resize array
                                    penguinCapacity = penguinCapacity * 2;
                                    penguin *newArr = new penguin[penguinCapacity];
                                    for(int i = 0; i < penguinCapacity; i++)
                                    {
                                        newArr[i] = penguinArray[i];
                                    }
                                    delete[] penguinArray;
                                    penguinArray = newArr;
                                }
                                //Find empty slot for new penguin
                                int penguinBuy = 0;
                                while(penguinArray[penguinBuy].getNumOfPenguins() == 1)
                                {
                                    penguinBuy++;
                                }
                                //Buy the penguin and set age to 3
                                penguinArray[penguinBuy].setNumOfPenguins(1);
                                penguinArray[penguinBuy].setAge(3);
                                buyPenguin();
                                totalPenguins++;
                                counter++;
                                counter2++;
                            }
                            //If turtle
                            else if(pickAnimal == 3)
                            {
                                //Resize array
                                turtleCapacity = turtleCapacity * 2;
                                turtle *newArr = new turtle[turtleCapacity];
                                for(int i = 0; i < turtleCapacity; i++)
                                {
                                    newArr[i] = turtleArray[i];
                                }
                                delete[] turtleArray;
                                turtleArray = newArr;
                                //Find empty slot for new turtle
                                int turtleBuy = 0;
                                while(turtleArray[turtleBuy].getNumOfTurtles() == 1)
                                {
                                    turtleBuy++;
                                }
                                //Buy the turtle and set age to 3
                                turtleArray[turtleBuy].setNumOfTurtles(1);
                                turtleArray[turtleBuy].setAge(3);
                                buyTurtle();
                                totalTurtles++;
                                counter++;
                                counter2++;
                            }
                            //Repeat
                            else
                            {
                                std::cout << "That is not a valid option. Please enter a valid option." << std::endl;
                                std::cout << "1. Tiger for $10,000." << std::endl;
                                std::cout << "2. Penguin for $1,000." << std::endl;
                                std::cout << "3. Turtle for $100." << std::endl;
                                std::cin >> pickAnimal;
                                counter++;
                            }
                        }
                    }
                }
                else if(buyNewAnimal == 2)
                {
                    //End loop
                    counter++;
                }
                //Repeat the loop if integer does not match possible choices
                else
                {
                    std::cout << "That is not a valid option. Please enter 1 to buy a new animal or 2 to not buy." << std::endl;
                    std::cin >> buyNewAnimal;
                }
            }
        }

        //Check if bank is negative or not
        if(bank < 0)
        {
            endGameCounter++;
            std::cout << "You have run out of money. Game Over!" << std::endl;
        }
        //If bank still has money
        else
        {
            //Ask player if they would like to end the game or not
            int endGame;
            std::cout << "Would you like to quit the game?" << std::endl;
            std::cout << "Press 1 to quit, and press 2 to continue playing." << std::endl;
            std::cin >> endGame;
            counter = 0;
            //input validation loop
            while(counter < 1)
            {
                //input validation
                if(std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "That is not a valid option. Please enter a valid option." << std::endl;
                    std::cout << "Press 1 if you do, and press 2 if you don't." << std::endl;
                    std::cin >> endGame;
                }
                else
                {
                    //If user chooses to end
                    if(endGame == 1)
                    {
                        counter++;
                        endGameCounter++;
                    }
                    //If user choose to continue, loop starts next day
                    else if(endGame == 2)
                    {
                        counter++;
                    }
                    //If invalid answer
                    else
                    {
                        std::cout << "That is not a valid option. Please enter a valid option." << std::endl;
                        std::cout << "Press 1 if you do, and press 2 if you don't." << std::endl;
                        std::cin >> endGame;
                    }
                }
            }
        }
    }
    //Delete dynamic arrays
    delete[] tigerArray;
    delete[] penguinArray;
    delete[] turtleArray;
}

//Get function for bank
int zoo::getBank()
{
    return bank;
}

//Buy tiger function, subtract form bank
void zoo::buyTiger()
{
    tiger tig;
    bank = bank - tig.getCost();
}

//Buy penguin function, subtract from bank
void zoo::buyPenguin()
{
    penguin pen;
    bank = bank - pen.getCost();
}

//Buy turtle function, subtract from bank
void zoo::buyTurtle()
{
    turtle tur;
    bank = bank - tur.getCost();
}




