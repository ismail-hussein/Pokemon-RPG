#include <iostream>
#include <fstream>
#include <sstream>
#include "Map.h"
using namespace std;


Map::Map()
{
    // initial constrctor
    // loop through making board array zero everywhere
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            board[i][j] = "";
            j++;
        }
        i++;
    }
}


void Map::setBoard(string input0_file)
{
    //takes file initially and fills two dimensional array with pokemon map
    int i = 0;
    int j = 0;
    string dummy0;
    string line;
    //opening the file
        ifstream myFile;
        myFile.open(input0_file);
        
        if (!myFile.is_open())
        {
            int ok;
        }
        else
        {
            while ((getline(myFile, line)) && i < 25)
            {
                istringstream streamline;
                streamline.str(line); 
                j = 0;
                while ((getline(streamline, dummy0, ',')) && j < 16)
                {
                    board[i][j] = dummy0;
                    j++;
                }
                i++;
            }
        }
}

// void Map::setPokemon(string input1_file)
// {
//     int i = 0;
//     string line;
//     string dummy0;
//     //opening the file
//         ifstream myFile;
//         myFile.open(input1_file);
        
//         if (!myFile.is_open())
//         {
//             int ok;
//         }
//         else
//         {
//             while (getline(myFile, line))
//             {
                
                
//                 istringstream streamline;
//                 streamline.str(line); 
                
//                 fullpokemon[i] = line;
//                 i++;
//             }
//         }
// }

// string Map::getFullPokemon(int input_which0)
// {
//     return fullpokemon[input_which0];
// }


void Map::initializeGyms()
{
    //did not end up using
    int k = 0;
    while (k < 15)
    {
        for (int i = 0; i < 25; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                if (board[i][j] == "G")
                {
                    //gyms[k].setlocation(i, j);
                    gyms[k].randomize();
                    //gyms[k].setTrainerName();
                    //cout << i << "." << j << endl;
                    k++;
                }
            }
            
        }
    }
}

int Map::getGymExtract(int Y, int X)
{
    //did not end up using
    int k = 0;
    while (k < 15)
    {
        for (int i = 0; i < 25; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                if (board[i][j] == "G")
                {
                    if ((gyms[k].getlocationYi() == Y) && (gyms[k].getlocationXj() == X))
                    {
                        return gyms[k].getpokemonNum();
                    }
                    
                    
                    //cout << i << "." << j << endl;
                    k++;
                }
            }
            
        }
    }
    return -1;
}

void Map::scatterPokemon()
{
    //randomly places 20 pokemon across 20 "p" tiles around the map and saves the pokemon ID to each pokemmon (class wild stores location and pokemon ID)
    int k = 0;
    
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            if ((board[i][j] == "p") && (i != 12) && ((rand() % 7 + 1) == 2) && (k < 20)) //spawning 20 random pokemon with a 20% chance on each p tile
            {
                wilds[k].setLocation(i, j);
                wilds[k].random();
                k++;
            }
        }
        
    }
}

int Map::checkWild()
{
    //checks if there is a wild pokemon in a 5x5 box around the user
//    int cplayery;
//    int cplayerx;
//    cplayery = playery;
//    cplayerx = playerx;
   //cout << "test1" << endl;
   for (int u = (playery - 3); u < (playery + 4); u++)
    {
        //cout << "test2" << endl;
        if ((u < 0) || (u > 25))
        {
            int skip;
        }
        else
        {
            for (int h = (playerx - 3); h < (playerx + 4); h++)
            {
                //cout << "test3" << endl;
                if ((h < 0) || (h > 16))
                {
                    int skip1;
                }
                else
                {
                    for (int i = 0; i < 20; i++)
                    {
                        //loop and find a wild pokemon at this location

                        if ((wilds[i].getLocationYi() == u) && (wilds[i].getLocationXj() == h))
                        {
                            //cout << wilds[i].getLocationYi() << "." << wilds[i].getLocationXj() << "." << wilds[i].getNum() << "." << "here" << endl;
                            //wilds[i].setLocation(100, 100);
                            //returns ID of wild pokemon found
                            return wilds[i].getNum();
                        } 
                    }
                }
            }
        }
    }
    return 0;
}

void Map::removeWild()
{
   //after an encounter of any sort with a wild pokemon if it is not caught it is deleted here to prevent any infinite loops and improve user experience
   for (int u = (playery - 3); u < (playery + 4); u++)
    {
        //cout << "test2" << endl;
        if ((u < 0) || (u > 25))
        {
            int skip;
        }
        else
        {
            for (int h = (playerx - 3); h < (playerx + 4); h++)
            {
                //cout << "test3" << endl;
                if ((h < 0) || (h > 16))
                {
                    int skip1;
                }
                else
                {
                    for (int i = 0; i < 20; i++)
                    {
                        //loop and find a wild pokemon at this location

                        if ((wilds[i].getLocationYi() == u) && (wilds[i].getLocationXj() == h))
                        {
                            //removing wild pokemon already added to active party
                            wilds[i].setLocation(100, 100);
                            i = 30;
                            h = 100;
                            u = 100;
                        } 
                    }
                }
            }
        }
    }
}

void Map::shuffleWild()
{
    //after every turn each remaining pokemon in the 7x7 box around the user will move one tile in a random direction
    //go through each unit in wilds (in vision box) and move them
    for (int u = (playery - 3); u < (playery + 4); u++)
    {
        //cout << "test2" << endl;
        if ((u < 0) || (u > 25))
        {
            int skip;
        }
        else
        {
            for (int h = (playerx - 3); h < (playerx + 4); h++)
            {
                //cout << "test3" << endl;
                if ((h < 0) || (h > 16))
                {
                    int skip1;
                }
                else
                {
                    for (int i = 0; i < 20; i++)
                    {
                        //loop and find a wild pokemon at this location

                        if ((wilds[i].getLocationYi() == u) && (wilds[i].getLocationXj() == h))
                        {
                            //moving wild pokemon in window around
                            if (u > 14 && (board[u - 1][h] == "p"))
                            {
                                wilds[i].setLocation(u - 1, h);
                            }
                            else if (u < 12 && (board[u + 1][h] == "p"))
                            {
                                wilds[i].setLocation(u + 1, h);
                            }
                            else if (h > 10 && (board[u][h - 1] == "p"))
                            {
                                wilds[i].setLocation(u, h -1);
                            }
                            else
                            {
                                wilds[i].setLocation(u, h+1);
                            }
                        } 
                    }
                }
            }
        }
    }

}




int Map::wildEncounter()
{
    //if there is a wild pokemon around the user this function will tell the main function what the pokemon ID is so the user can fight it
    for (int u = (playery - 2); u < (playery + 3); u++)
    {
        //cout << "test2" << endl;
        if ((u < 0) || (u > 25))
        {
            int skip;
        }
        else
        {
            for (int h = (playerx - 2); h < (playerx + 3); h++)
            {
                //cout << "test3" << endl;
                if ((h < 0) || (h > 16))
                {
                    int skip1;
                }
                else
                {
                    for (int i = 0; i < 20; i++)
                    {
                        //loop and find a wild pokemon at this location

                        if ((wilds[i].getLocationYi() == u) && (wilds[i].getLocationXj() == h))
                        {
                            //removing wild pokemon already added to active party;
                            return wilds[i].getNum();
                        } 
                    }
                }
            }
        }
    }
    return 0;
}




void Map::initialSpawn(int xcoord)
{
    //at the very start this function spawns the @ sign that represents the player
    holdspot = board[12][xcoord];
    board[12][xcoord] = "@";
    playery = 12;
    playerx = xcoord;
}

void Map::movePlayer(int direction)
{
    onCenter = 0;
    onGymX = 0;
    onGymY = 0;
    if (direction == 1)
    {
        if (playery != 0)
        {
            if (board[playery - 1][playerx] != "w")
            {
                if(board[playery - 1][playerx] == "C")
                {
                    onCenter = 1;
                }
                if(board[playery - 1][playerx] == "G")
                {
                    onGymY = playery - 1;
                    onGymX = playerx;
                }
                board[playery][playerx] = holdspot;
                holdspot = board[playery - 1][playerx];
                board[playery - 1][playerx] = "@";
                playery = playery - 1;
            }    
        }
    }
    else if (direction == 2)
    {
       if (playery != 24)
        {
            if (board[playery + 1][playerx] != "w")
            {
                if(board[playery + 1][playerx] == "C")
                {
                    onCenter = 1;
                }
                if(board[playery + 1][playerx] == "G")
                {
                    onGymY = playery + 1;
                    onGymX = playerx;
                }
                board[playery][playerx] = holdspot;
                holdspot = board[playery + 1][playerx];
                board[playery + 1][playerx] = "@";
                playery = playery + 1;
            }    
        } 
    }
    else if (direction == 3)
    {
       if (playerx < 15)
        {
            if (board[playery][playerx + 1] != "w")
            {
                if(board[playery][playerx + 1] == "C")
                {
                    onCenter = 1;
                }
                if(board[playery][playerx + 1] == "G")
                {
                    onGymY = playery;
                    onGymX = playerx + 1;
                }
                board[playery][playerx] = holdspot;
                holdspot = board[playery][playerx + 1];
                board[playery][playerx + 1] = "@";
                playerx = playerx + 1;
            }    
        } 
    }
    else
    {
       if (playerx != 0)
        {
            if (board[playery][playerx - 1] != "w")
            {
                if(board[playery][playerx - 1] == "C")
                {
                    onCenter = 1;
                }
                if(board[playery][playerx - 1] == "G")
                {
                    onGymY = playery;
                    onGymX = playerx - 1;
                }
                board[playery][playerx] = holdspot;
                holdspot = board[playery][playerx - 1];
                board[playery][playerx - 1] = "@";
                playerx = playerx - 1;
            }    
        } 
    }
    
}

// void Map::goCenter()
// {

// }

void Map::displayMap()
{
    int ihold;
    int jhold;
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            if (board[i][j] == "@")
            {
                ihold = i;
                jhold = j;
            }
        }
    }
    cout << endl;
    for (int u = (ihold - 3); u < (ihold + 4); u++)
    {
        if ((u < 0) || (u > 24))
        {
            int skip;
        }
        else
        {
            for (int h = (jhold - 3); h < (jhold + 4); h++)
            {
                if ((h < 0) || (h > 15))
                {
                    int skip1;
                }
                else
                {
                    cout << board[u][h] << " ";
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}

int Map::getonGymX()
{
    return onGymX;
}

int Map::getonGymY()
{
    return onGymY;
}

int Map::getonCenter()
{
    return onCenter;
}
// void initializeCenters
// {
//     k = 0;
    
//     for (i = 0; i < 25; i++)
//     {
//         for(j = 0; j < 16; j++)
//         {
//             gyms[k].setlocation(i, j);
//             k++;
//         }
        
//     }
// }

// string Map::getBoard() const
// {
//     //output file and save current board in it
// }