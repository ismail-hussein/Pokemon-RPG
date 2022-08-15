#include <iostream>
#include <fstream>
#include <sstream>
#include "Gym.h"
using namespace std;

//did not end up using

Gym::Gym()
{
    int name = 0;
    int loactionXj = 0;
    int locationYi = 0;
    for (int i = 0; i < 6; i++)
    {
        pokemonNum = 0;
    }
}

 int Gym::getpokemonNum()
 {
     return pokemonNum;
 }

void Gym::setlocation(char Linput1, char Linput2)
{
    //saving the coordinates of each gym to each "gym" in the gym class
    locationXj = Linput2;
    locationYi = Linput1;
}

void Gym::randomize()
{
    /*assigning 1 to 6 pokemon in each gym then randomly selecting a number 1 to 150 for each pokemon
    each number (1 to 150) cooresponds to a pokemon that will be found later*/
    pokemonNum = rand() % 150 + 1;
    ///cout << pokemonNum;
}

int Gym::getlocationYi()
{
    return locationYi;
}

int Gym::getlocationXj()
{
    return locationXj;
}

void Gym::setTrainerName()
{
    name = rand() % 1000 + 1;
}

int Gym::getTrainerName()
{
    return name;
}