#include <iostream>
#include <fstream>
#include <sstream>
#include "Pokemon.h"
using namespace std;

Pokemon::Pokemon()
{
    // initial constrctor
    string name = "";
    int hp = 0;
    int attack = 0;
    int defense = 0;
    int speed = 0;
    int max = 0;
    string type = "";
    int level = 0;
}
 
void Pokemon::setName(string input0_name)
{
    name = input0_name;
}

void Pokemon::setHP(int input0_hp)
{
    hp = input0_hp;
}

void Pokemon::setAttack(int input0_attack)
{
    attack = input0_attack;
}

void Pokemon::setDefense(int input0_defense)
{
    defense = input0_defense;
}

void Pokemon::setSpeed(int input0_speed)
{
    speed = input0_speed;
}

void Pokemon::setMax(int input0_max)
{
    max = input0_max;
}

void Pokemon::setType(string input0_type)
{
    type = input0_type;
}

void Pokemon::setLevel(int input0_level)
{
    level = input0_level;
}

void Pokemon::setMaxHP(int input)
{
    maxhp = input;
}

string Pokemon::getName() const
{
    return name;
}

int Pokemon::getHP() const
{
    return hp;
}

int Pokemon::getAttack() const
{
    return attack;
}

int Pokemon::getDefense() const
{
    return defense;
}

int Pokemon::getSpeed() const
{
    return speed;
}

int Pokemon::getMax() const
{
    return max;
}

string Pokemon::getType() const
{
    return type;
}

int Pokemon::getLevel() const
{
    return level;
}

void Pokemon::resetHP()
{
    hp = 0;
}

void Pokemon::levelUp()
{
   //code for levelling up
    attack = attack + 2;
    defense = defense + 2;
    hp = hp + 2;
}

int Pokemon::getMaxHP() const
{
    return maxhp;
}