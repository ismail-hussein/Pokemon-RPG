#include <iostream>
#include <fstream>
#include <sstream>
#include "Wild.h"
using namespace std;

Wild::Wild()
{
    int loactionXj = 0;
    int locationYi = 0;
}

void Wild::setLocation(int Linput1, int Linput2)
{
    //saving the coordinates of each geach wild pokemon
    locationXj = Linput2;
    locationYi = Linput1;
}

int Wild::getLocationYi()
{
    return locationYi;
}

int Wild::getLocationXj()
{
    return locationXj;
}

int Wild::getNum()
{
    //pokemon ID of this wild pokemon
    return wildpokemon;
}

void Wild::random()
{
    //randomly generates pokemon ID 
    wildpokemon = rand() % 150 + 1;
    //cout << wildpokemon << endl;
}