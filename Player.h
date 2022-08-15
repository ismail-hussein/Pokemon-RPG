#include <iostream>
#include <fstream>
#include <sstream>
#include "Map.h"
#include "Pokemon.h"
using namespace std;

class Player
{
    // defining public functions
    public:
        Player();
        void setPlayerName(string input_PN0);
        void setPokemon(string input1_file);
        void displayPokemon();
        void displayIndiv(Pokemon input);
        // void switchActivePokemon();
        void addPokemonToParty(int input_which);
        void rest();
        void usePokeball();
        void wildFight(int monID);
        void fightGym(int mon2ID);
        int getGameover();
        int getCenterTele();
        void atCenter();
        int getnumBadges();
        // void addPokemonToPokedex();
        // void switchBetweenPartyPokedex();
        // string getParty(int partyNumber);
        // string getPokedex(int dexNumber);
        // void setParty(string input0_party, int partyNumber1);
        // void setDex(string input0_dex, int dexNumber1);
    // defining private variables
    private:
        int numBadges = 0;
        int enCounter = 0;
        int crazy = 10;
        string playerNamed;
        string fullpokemon[150];
        int martballs;
        Map storage;
        Pokemon currentWild;
        Pokemon activeParty[6];
        Pokemon pokedex[150];
        int GameoverCheck = 0;
        int CenterTele = 0;
};