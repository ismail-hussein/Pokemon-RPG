#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Wild
{
    // defining public functions
    public:
        Wild();
        void setLocation(int Linput1, int Linput2);
        int getLocationYi();
        int getLocationXj();
        int getNum();
        void random();
        
    // defining private variables
    private:
       int locationXj = 0;
       int locationYi = 0;
       int wildpokemon = 0;
};