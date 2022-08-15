#include <iostream>
#include <fstream>
#include <sstream>
#include "Wild.h"
#include "Gym.h"
using namespace std;

class Map
{
    // defining public functions
    public:
        Map();
        void setBoard(string input0_file);
        //void setPokemon(string input1_file);
        //string getFullPokemon(int input_which0);
        void initializeGyms();
        int getGymExtract(int Y, int X);
        void getBoard() const;
        void initializeCenters();
        void scatterPokemon();
        int checkWild();
        void removeWild();
        void shuffleWild();
        int wildEncounter();
        void initialSpawn(int xcoord);
        void movePlayer(int direction);
        //void goCenter();
        void displayMap();
        int getonGymY();
        int getonGymX();
        int getonCenter();
    // defining private variables
    private:
       string holdspot;
       string board[25][16];
       //string fullpokemon[150];
       Gym gyms[15];
       Wild wilds[20];
       int playery;
       int playerx;
       int onCenter;
       int onGymX;
       int onGymY;
};