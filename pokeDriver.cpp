#include <iostream>
#include <iomanip>
#include "Player.h"
using namespace std;





int main()
{
    
    Map green;
    Player blue;
    string inputname;
    int initial;
    int choice = 0;
    
    cout << "Please state your name" << endl;
    cin >> inputname;
    blue.setPlayerName(inputname);
    cout << endl << "Welcome, " << inputname << "! " << "Before you can begin your" << endl; 
    cout << "Pokemon adventure, you must choose a starting" << endl; 
    cout << "Pokemon, courtesy of the Professor. Please" << endl;
    cout << "choose from the following Pokemon:" << endl;
    cout << "1. Bulbasaur" << endl;
    cout << "2. Charmander" << endl;
    cout << "3. Squirtle" << endl;
    cout << "4. Pikachu" << endl;
    cin >> initial;
    initial = initial + 6;
    //make option for each starter
    green.setBoard("mapPoke.txt");
    green.scatterPokemon();
    blue.setPokemon("pokemon.txt");
    green.initializeGyms();
    green.initialSpawn(initial);
    if (initial == 7)
    {
        blue.addPokemonToParty(1);
    }
    if (initial == 8)
    {
        blue.addPokemonToParty(4);
    }
    if (initial == 9)
    {
        blue.addPokemonToParty(7);
    }
    else
    {
        blue.addPokemonToParty(25);
    }
    green.displayMap();
    blue.displayPokemon();
    // end intro begin loop

    while ((choice != 4) && (blue.getGameover() < 1) && (blue.getnumBadges() < 4))
    {
        cout << endl << "Please choose from the following options:" << endl;
        cout << "1. Travel" << endl;
        cout << "2. Rest" << endl;
        cout << "3. Try Your Luck" << endl;
        cout << "4. Quit the game" << endl;
        cin >> choice;

        if (choice == 1) //travel
        {
            int command = 0;
            cout << endl << "Please pick a direction:" << endl;
            cout << "1. North" << endl;
            cout << "2. South" << endl;
            cout << "3. East" << endl;
            cout << "4. West" << endl;
            cin >> command;

            green.movePlayer(command);
            green.displayMap();
            blue.displayPokemon();
            green.shuffleWild();
            if (green.getonCenter() > 0)//pokemon center
            {

                cout << "You are at a pokemon center your party has been healed" << endl;
                blue.atCenter();
            }
            else if ((green.getonGymY() > 0) || (green.getonGymX() > 0))//pokemon gym
            {
                //cout << "on gym" << endl;
                //int xcoor = green.getonGymX();
                //int ycoor = green.getonGymY();
                //int gymmonhold = green.getGymExtract(ycoor, xcoor);
                int gymmonhold = rand() % 151;
                cout << gymmonhold << endl;
                blue.fightGym(gymmonhold);
            }
            else if (green.wildEncounter() > 0)//wild pokemon
                {
                    //cout << "not gym" << endl;
                    int fightmon = green.wildEncounter();
                    blue.wildFight(fightmon);
                    green.removeWild();
                    //if (blue.getCenterTele() = 1)
                    //{
                    //      green.goCenter();
                    //}
                }
        }
        else if (choice == 2) //rest
        {
            blue.rest();
            blue.usePokeball();
            green.displayMap();
            blue.displayPokemon();
            green.shuffleWild();
            if (green.wildEncounter() > 0)
                {
                    int fightmon = green.wildEncounter();
                    blue.wildFight(fightmon);
                    green.removeWild();
                }

        }
        else if (choice == 3)// try luck
        {
            if (green.checkWild() > 0)
            {
                //cout << "check0" << endl;
                int pokehold = green.checkWild();
                //cout << "check1" << pokehold << endl;
                if ((rand() % 2) == 1)
                {
                    blue.addPokemonToParty(pokehold);
                    green.removeWild();
                    green.shuffleWild();
                    if (green.wildEncounter() > 0)
                    {
                        int fightmon = green.wildEncounter();
                        blue.wildFight(fightmon);
                        green.removeWild();
                    }
                }
                //cout << "check2" << endl;
                green.displayMap();
                blue.displayPokemon();
                green.removeWild();
                green.shuffleWild();
            }
        }
        else if (choice == 4) //quit
        {
            cout << "Have a nice day" << endl;
        }
        else
        {
            cout << "Invalid option try again" << endl;
        }
        

    }

    if (blue.getnumBadges() > 2)
    {
        cout << "congratulations you and your pokemon have conquered the pokemon league" << endl;
    }
    
    
    
}