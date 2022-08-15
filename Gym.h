#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//did not end up using

class Gym
{
    // defining public functions
    public:
        Gym();
        void setlocation(char Linput1, char Linput2);
        int getlocationYi();
        int getlocationXj();
        void randomize();
        int getpokemonNum();
        void setTrainerName();
        int getTrainerName();
        
    // defining private variables
    private:
       int locationXj = 0;
       int locationYi = 0;
       int pokemonNum;
       int name = 0;
};