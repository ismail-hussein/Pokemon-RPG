#include <iostream>
#include <fstream>
#include <sstream>
#include "Player.h"
using namespace std;

Player::Player()
{
    playerNamed = "";
    // initial constrctor
    // loop through making party and pokedex array empty everywhere
}



void Player::setPlayerName(string input_PN0)
{
    playerNamed = input_PN0;
}




void Player::setPokemon(string input1_file)
{
    //load all the pokemon stats from a file
    int i = 0;
    string line;
    string dummy0;
    //opening the file
        ifstream myFile;
        myFile.open(input1_file);
        
        if (!myFile.is_open())
        {
            int ok;
        }
        else
        {
            while (getline(myFile, line) && i < 150)
            {
                
                
                istringstream streamline;
                streamline.str(line); 
                
                fullpokemon[i] = line;
                i++;
            }
        }
}
 


void Player::displayPokemon()
{
    //at the end of each turn this function displays all the users pokemon and their stats
    int i = 0;
    cout << "The sun is shining, " << playerNamed << "! It's a beautiful day, we have " << crazy << " pokeballs left and your Pokemon are strong." << endl;
    //printing pokemon stats at the start of each turn
    while (activeParty[i].getAttack() > 0)
    {
        cout << "Name: " << activeParty[i].getName() << ", ";
        cout << "HP: " << activeParty[i].getHP() << ", ";
        cout << "A: " << activeParty[i].getAttack() << ", ";
        cout << "D: " << activeParty[i].getDefense() << ", ";
        cout << "S: " << activeParty[i].getSpeed() << ", ";
        cout << "M: " << activeParty[i].getMax() << ", " << endl;
        i++;
    }
    // couts the number of remaining pokeballs
}

void Player::displayIndiv(Pokemon input)
{
    //like above for edge cases
    cout << "Name: " << input.getName() << ", ";
    cout << "HP: " << input.getHP() << ", ";
    cout << "A: " << input.getAttack() << ", ";
    cout << "D: " << input.getDefense() << ", ";
    cout << "S: " << input.getSpeed() << ", ";
    cout << "M: " << input.getMax() << ", " << endl;
}

// void Player::switchActivePokemon()
// {
//     //code to switch pokemon inside the active pokemon array
// }



void Player::addPokemonToParty(int input_which)
{
    //adds a pokemon to the activeParty[] array (if there is room)
    int i = 0;
    //cout << "pokemon" << input_which << endl;
    while (activeParty[i].getAttack() > 0)
    {
        i++;
    }

    if (i < 6)
    {
        //cout << "pokenumber" << i << endl;
        //parsing raw line of code holding all pokemon stats and putting them in type pokmeon variable active party
        string dummy0;
        string parsehold;
        parsehold = fullpokemon[input_which];
        //now holding line of raw pokemon code for pokemon number "input_which"
        
        istringstream streamline;
        streamline.str(parsehold); 
        getline(streamline, dummy0, ',');
        getline(streamline, dummy0, ',');
        activeParty[i].setName(dummy0);
        getline(streamline, dummy0, ',');
        activeParty[i].setHP(stoi(dummy0));
        activeParty[i].setMaxHP(stoi(dummy0));
        getline(streamline, dummy0, ',');
        activeParty[i].setAttack(stoi(dummy0));
        getline(streamline, dummy0, ',');
        activeParty[i].setDefense(stoi(dummy0));
        getline(streamline, dummy0, ',');
        activeParty[i].setSpeed(stoi(dummy0));
        getline(streamline, dummy0, ',');
        activeParty[i].setMax(stoi(dummy0));
        getline(streamline, dummy0);
        activeParty[i].setType(dummy0);

        cout << "You added " << activeParty[i].getName() << "!" << endl;
        
        //cout << "double check" << activeParty[i].getSpeed() << endl;
        //code to add pokemon to the party array
    }
}

void Player::rest()
{
    //user option to rest pokemon
    int i = 0;
    while (activeParty[i].getAttack() > 0)
    {
        int holdhp = activeParty[i].getHP();
        activeParty[i].setHP(holdhp + 30);
        i++;
    }
}

void Player::usePokeball()
{
    //used with the rest method
    crazy = crazy - 1;
}

void Player::wildFight(int monID)
{
    //function that initiates when the user is near a wild pokemon at the end of a turn
    CenterTele = 0;
    int i = 0;
    int j = 0;
    int input;
    string parsehold;
    string dummy0;
    int C = 1;
    int Cl = 1;
    int round = 0;
    //splcing wild pokemon
    parsehold = fullpokemon[monID];

    istringstream streamline;
    streamline.str(parsehold); 
    getline(streamline, dummy0, ',');
    getline(streamline, dummy0, ',');
    currentWild.setName(dummy0);
    getline(streamline, dummy0, ',');
    currentWild.setHP(stoi(dummy0));
    currentWild.setMaxHP(stoi(dummy0));
    getline(streamline, dummy0, ',');
    currentWild.setAttack(stoi(dummy0));
    getline(streamline, dummy0, ',');
    currentWild.setDefense(stoi(dummy0));
    getline(streamline, dummy0, ',');
    currentWild.setSpeed(stoi(dummy0));
    getline(streamline, dummy0, ',');
    currentWild.setMax(stoi(dummy0));
    getline(streamline, dummy0);
    currentWild.setType(dummy0);

    while ((activeParty[i].getHP() < 1) && (i < 6))// if I is 6 you are out of usable pokemon
    {
        i++;
    }

    if (i != 6)
    {
        while (round < 1)
        {
            cout << endl << "You ran into a wild Pokemon!" << endl;
            displayIndiv(currentWild);

            cout << endl << "Your ACTIVE Pokemon is: " << endl;
            displayIndiv(activeParty[i]);
        
            cout << endl << "What do you want to do (pick 1, 2 or 3):" << endl;
            cout << "1. Fight" << endl << "2. Switch Active Pokemon" << endl << "3. Run" << endl;
            cin >> input;

            if (input == 1) //fight
            {
                if (enCounter < 2)//change back to 2 // initial catch if beginner
                {
                    addPokemonToParty(monID);
                    round++;
                }
                else if((rand() % 100) > 30) //enemy attacks
                {
                    //attack
                    cout << "attack" << endl;
                    if (activeParty[i].getSpeed() > currentWild.getSpeed()) //your pokemon is faster
                    {
                            int yourAttack;
                            int wildAttack;
                            int yourDefense;
                            int wildDefense;
                            yourAttack = rand() % activeParty[i].getAttack();
                            wildAttack = rand() % currentWild.getAttack();
                            yourDefense = rand() % activeParty[i].getDefense();
                            wildDefense = rand() % currentWild.getDefense();
                            //cout  << endl << "your attack " << yourAttack << "wild attack" << wildAttack << endl;
                            //cout << "your defense " << yourDefense << "wild defense" << wildDefense << endl;

                            cout << endl << currentWild.getName() << " and " << activeParty[i].getName() << " both want to attack" << endl;
                            displayIndiv(currentWild);
                            displayIndiv(activeParty[i]);

                            if (yourAttack > wildDefense)//beginning of your turn
                            {
                                cout << endl << activeParty[i].getName() << " attacks first" << endl;
                                int healthHold = currentWild.getHP() - (yourAttack - wildDefense);
                                currentWild.setHP(healthHold);
                                cout << activeParty[i].getName() << " deals " << yourAttack - wildDefense << " damage" << endl;
                                displayIndiv(currentWild);
                                displayIndiv(activeParty[i]);
                            }
                            else
                            {
                                cout << endl << activeParty[i].getName() << " attacks first" << endl;
                                cout << activeParty[i].getName() << " deals no damage " << endl;
                                displayIndiv(currentWild);
                                displayIndiv(activeParty[i]);
                            }
                            if (currentWild.getHP() > 0)
                            {
                                if (wildAttack > yourDefense)//beginning of wild turn
                                {
                                    cout << endl << currentWild.getName() << " attacks next" << endl;
                                    int healthHold = activeParty[i].getHP() - (wildAttack - yourDefense);
                                    activeParty[i].setHP(healthHold);
                                    cout << currentWild.getName() << " deals " << wildAttack - yourDefense << " damage" << endl;
                                    displayIndiv(currentWild);
                                    displayIndiv(activeParty[i]);
                                }
                                else
                                {
                                    cout << endl << currentWild.getName() << " attacks next" << endl;
                                    cout << currentWild.getName() << " deals no damage" << endl;
                                    displayIndiv(currentWild);
                                    displayIndiv(activeParty[i]);
                                }
                            }

                            //cout << "your defense " << yourDefense << "wild defense" << wildDefense << endl;
                    }
                    else //wild pokemon is faster
                    {
                        
                        int yourAttack;
                        int wildAttack;
                        int yourDefense;
                        int wildDefense;
                        yourAttack = rand() % activeParty[i].getAttack();
                        wildAttack = rand() % currentWild.getAttack();
                        yourDefense = rand() % activeParty[i].getDefense();
                        wildDefense = rand() % currentWild.getDefense();
                        //cout  << endl << "your attack " << yourAttack << "wild attack" << wildAttack << endl;
                        //cout << "your defense " << yourDefense << "wild defense" << wildDefense << endl;

                        cout << endl << currentWild.getName() << " and " << activeParty[i].getName() << " both want to attack" << endl;
                        displayIndiv(currentWild);
                        displayIndiv(activeParty[i]);

                        if (wildAttack > yourDefense)//beginning of wild turn
                            {
                                cout << endl << currentWild.getName() << " attacks first" << endl;
                                int healthHold = activeParty[i].getHP() - (wildAttack - yourDefense);
                                activeParty[i].setHP(healthHold);
                                cout << currentWild.getName() << " deals " << wildAttack - yourDefense << " damage" << endl;;
                                displayIndiv(currentWild);
                                displayIndiv(activeParty[i]);
                            }
                            else
                            {
                                cout << endl << currentWild.getName() << " attacks first" << endl;
                                cout << currentWild.getName() << " deals no damage" << endl;
                                displayIndiv(currentWild);
                                displayIndiv(activeParty[i]);
                            }
                        if (activeParty[i].getHP() > 0)
                        {
                            if (yourAttack > wildDefense)//beginning of your turn
                                {
                                    cout << endl << activeParty[i].getName() << " attacks next" << endl;
                                    int healthHold = currentWild.getHP() - (yourAttack - wildDefense);
                                    currentWild.setHP(healthHold);
                                    cout << activeParty[i].getName() << " deals " << yourAttack - wildDefense << " damage" << endl;
                                    displayIndiv(currentWild);
                                    displayIndiv(activeParty[i]);
                                }
                                else
                                {
                                    cout << endl << activeParty[i].getName() << " attacks next" << endl;
                                    cout << activeParty[i].getName() << " deals no damage " << endl;
                                    displayIndiv(currentWild);
                                    displayIndiv(activeParty[i]);
                                }
                        }
                    }
                    
                    if (currentWild.getHP() < 1)
                        {
                            addPokemonToParty(monID);
                            activeParty[i].levelUp();
                            round++;
                        }
                    if (activeParty[i].getHP() < 1)
                    {
                        currentWild.levelUp();
                        i++;
                        if ((activeParty[i].getHP() > 1) || (activeParty[i].getHP() < 2))
                            {
                                int keepgoing;
                            }
                            else
                            {
                                cout << "game over" << endl;
                                GameoverCheck++;
                                i = 6;
                            }
                        //your pokemon fainted hp must be restored loops back to 1 2 3
                    }
                }
                else //enemy tries to flee
                {
                    //cout << "flee" << endl;
                    int f;
                    f = (((currentWild.getSpeed() * 32) / (activeParty[i].getSpeed() / 4) + 30) * C);
                    //cout << f << endl;
                    C++;
                    if (f > 255)
                    {
                        round++;
                    }
                    else
                    {
                        addPokemonToParty(monID);
                        cout << endl;
                        round++;
                    }
                    
                }  
            }
            else if (input == 2) //switch
            {
                int inputhold;
                cout << "Pick another pokemon" << endl;
                while (activeParty[j].getAttack() > 0)
                {
                    cout << j + 1 << ". " << activeParty[j].getName() << endl;
                    j++;
                }
                cin >> inputhold;
                if (inputhold > 0 && inputhold < 7)
                {
                    inputhold = inputhold - 1;
                    i = inputhold;
                }
                else
                {
                    cout << "try again" << endl;
                }
            }
            else // run
            {
                int fl;
                fl = (((activeParty[i].getSpeed() * 32) / (currentWild.getSpeed() / 4) + 30) * C);
                //cout << fl << endl;
                Cl++;
                if (fl > 255 || activeParty[i].getSpeed() > currentWild.getSpeed())
                {
                    CenterTele = 1;
                    round++;
                }
            }
        }

        enCounter++;
    }
    // else
    // {
    //     cout << "game over" << endl;
    //     GameoverCheck++;
    // }
}

void Player::fightGym(int mon2ID)
{
    //function that initiates when the user is on a gym tile
    int i = 0;
    int input;
    string parsehold;
    string dummy0;
    int C = 1;
    int Cl = 1;
    int round = 0;
    //splcing wild pokemon
    parsehold = fullpokemon[mon2ID];

    istringstream streamline;
    streamline.str(parsehold); 
    getline(streamline, dummy0, ',');
    getline(streamline, dummy0, ',');
    currentWild.setName(dummy0);
    getline(streamline, dummy0, ',');
    currentWild.setHP(stoi(dummy0));
    currentWild.setMaxHP(stoi(dummy0));
    getline(streamline, dummy0, ',');
    currentWild.setAttack(stoi(dummy0));
    getline(streamline, dummy0, ',');
    currentWild.setDefense(stoi(dummy0));
    getline(streamline, dummy0, ',');
    currentWild.setSpeed(stoi(dummy0));
    getline(streamline, dummy0, ',');
    currentWild.setMax(stoi(dummy0));
    getline(streamline, dummy0);
    currentWild.setType(dummy0);

    while ((activeParty[i].getHP() < 1) && (i < 6))// if I is 6 you are out of usable pokemon
    {
        i++;
    }
    
    cout << endl << "You have arrived at the gym and a trainer is there, they are going to fight you!" << endl;

    if (i != 6)
    {
        while (round < 1)
        {
            cout << endl;
            displayIndiv(currentWild);

            cout << endl << "Your ACTIVE Pokemon is: " << endl;
            displayIndiv(activeParty[i]);
        
            cout << endl << "What do you want to do (pick 1 or 2):" << endl;
            cout << "1. Fight" << endl << "2. Switch Active Pokemon" << endl;
            cin >> input;

            if (input == 1) //fight
            {
                    //attack
                    cout << "attack" << endl;
                    if (activeParty[i].getSpeed() > currentWild.getSpeed()) //your pokemon is faster
                    {
                            int yourAttack;
                            int wildAttack;
                            int yourDefense;
                            int wildDefense;
                            yourAttack = rand() % activeParty[i].getAttack();
                            wildAttack = rand() % currentWild.getAttack();
                            yourDefense = rand() % activeParty[i].getDefense();
                            wildDefense = rand() % currentWild.getDefense();
                            //cout  << endl << "your attack " << yourAttack << "wild attack" << wildAttack << endl;
                            //cout << "your defense " << yourDefense << "wild defense" << wildDefense << endl;

                            cout << endl << currentWild.getName() << " and " << activeParty[i].getName() << " both want to attack" << endl;
                            displayIndiv(currentWild);
                            displayIndiv(activeParty[i]);

                            if (yourAttack > wildDefense)//beginning of your turn
                            {
                                cout << endl << activeParty[i].getName() << " attacks first" << endl;
                                int healthHold = currentWild.getHP() - (yourAttack - wildDefense);
                                currentWild.setHP(healthHold);
                                cout << activeParty[i].getName() << " deals " << yourAttack - wildDefense << " damage" << endl;
                                displayIndiv(currentWild);
                                displayIndiv(activeParty[i]);
                            }
                            else
                            {
                                cout << endl << activeParty[i].getName() << " attacks first" << endl;
                                cout << activeParty[i].getName() << " deals no damage " << endl;
                                displayIndiv(currentWild);
                                displayIndiv(activeParty[i]);
                            }
                            if (currentWild.getHP() > 0)
                            {
                                if (wildAttack > yourDefense)//beginning of wild turn
                                {
                                    cout << endl << currentWild.getName() << " attacks next" << endl;
                                    int healthHold = activeParty[i].getHP() - (wildAttack - yourDefense);
                                    activeParty[i].setHP(healthHold);
                                    cout << currentWild.getName() << " deals " << wildAttack - yourDefense << " damage" << endl;
                                    displayIndiv(currentWild);
                                    displayIndiv(activeParty[i]);
                                }
                                else
                                {
                                    cout << endl << currentWild.getName() << " attacks next" << endl;
                                    cout << currentWild.getName() << " deals no damage" << endl;
                                    displayIndiv(currentWild);
                                    displayIndiv(activeParty[i]);
                                }
                            }

                            //cout << "your defense " << yourDefense << "wild defense" << wildDefense << endl;
                    }
                    else //wild pokemon is faster
                    {
                        
                        int yourAttack;
                        int wildAttack;
                        int yourDefense;
                        int wildDefense;
                        yourAttack = rand() % activeParty[i].getAttack();
                        wildAttack = rand() % currentWild.getAttack();
                        yourDefense = rand() % activeParty[i].getDefense();
                        wildDefense = rand() % currentWild.getDefense();
                        //cout  << endl << "your attack " << yourAttack << "wild attack" << wildAttack << endl;
                        //cout << "your defense " << yourDefense << "wild defense" << wildDefense << endl;

                        cout << endl << currentWild.getName() << " and " << activeParty[i].getName() << " both want to attack" << endl;
                        displayIndiv(currentWild);
                        displayIndiv(activeParty[i]);

                        if (wildAttack > yourDefense)//beginning of wild turn
                            {
                                cout << endl << currentWild.getName() << " attacks first" << endl;
                                int healthHold = activeParty[i].getHP() - (wildAttack - yourDefense);
                                activeParty[i].setHP(healthHold);
                                cout << currentWild.getName() << " deals " << wildAttack - yourDefense << " damage" << endl;;
                                displayIndiv(currentWild);
                                displayIndiv(activeParty[i]);
                            }
                            else
                            {
                                cout << endl << currentWild.getName() << " attacks first" << endl;
                                cout << currentWild.getName() << " deals no damage" << endl;
                                displayIndiv(currentWild);
                                displayIndiv(activeParty[i]);
                            }
                        if (activeParty[i].getHP() > 0)
                        {
                            if (yourAttack > wildDefense)//beginning of your turn
                                {
                                    cout << endl << activeParty[i].getName() << " attacks next" << endl;
                                    int healthHold = currentWild.getHP() - (yourAttack - wildDefense);
                                    currentWild.setHP(healthHold);
                                    cout << activeParty[i].getName() << " deals " << yourAttack - wildDefense << " damage" << endl;
                                    displayIndiv(currentWild);
                                    displayIndiv(activeParty[i]);
                                }
                                else
                                {
                                    cout << endl << activeParty[i].getName() << " attacks next" << endl;
                                    cout << activeParty[i].getName() << " deals no damage " << endl;
                                    displayIndiv(currentWild);
                                    displayIndiv(activeParty[i]);
                                }
                        }
                    }
                        if (currentWild.getHP() < 1)
                        {
                            cout << "Congratulations you have defeated the pokemon trainer and have earned badge number ";
                            numBadges++;
                            cout << numBadges << endl;
                            activeParty[i].levelUp();
                            round++;
                        }
                        if (activeParty[i].getHP() < 1)
                        {
                            currentWild.levelUp();
                            i++;
                            if ((activeParty[i].getHP() > 1) || (activeParty[i].getHP() < 2))
                            {
                                int keepgoing;
                            }
                            else
                            {
                                cout << "game over" << endl;
                                GameoverCheck++;
                                i = 6;
                            }
                            
                            //your pokemon fainted hp must be restored loops then  back to 1 2 3
                        }
                    
            }
            else if (input == 2) //switch
            {
                int j = 0;
                int inputhold;
                cout << "Pick another pokemon" << endl;
                while (activeParty[j].getAttack() > 0)
                {
                    cout << j + 1 << ". " << activeParty[j].getName() << endl;
                    j++;
                }
                cin >> inputhold;
                if (inputhold > 0 && inputhold < 7)
                {
                    inputhold = inputhold - 1;
                    i = inputhold;
                }
                else
                {
                    cout << "try again" << endl;
                }
            }
            else // edge
            {
                cout << "try again" << endl;
            }
        }
    }  
}


void Player::atCenter()
{
    //happens when user is at a pokemon center, their pokemon are healed
     int i = 0;
     int holdhp;
    while (activeParty[i].getAttack() > 0)
    {
        holdhp = activeParty[i].getMaxHP();
        activeParty[i].setHP(holdhp);
        i++;
    }
}


int Player::getGameover()
{
    return GameoverCheck;
}

int Player::getCenterTele()
{
    return CenterTele;
}

int Player::getnumBadges()
{
    return numBadges;
}


// void Player::addPokemonToPokedex()
// {
//     //code to add pokemon to pokedex array
// }
// void Player::switchBetweenPartyPokedex()
// {
//     //code to switch pokemon from pokedex and active pokemon arrays
// }
// string Player::getParty(int partyNumber)
// {
//     return activeParty[partyNumber];
// }
// string Player::getPokedex(int dexNumber)
// {
//     return pokedex[dexNumber];
// }
// void Player::setParty(string input0_party, int partyNumber1)
// {
//     activeParty[partyNumber1] = input0_party;
// }
// void Player::setDex(string input0_dex, int dexNumber1)
// {
//     pokedex[dexNumber1] = input0_dex;
// }