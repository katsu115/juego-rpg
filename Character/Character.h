//created by Pc Andrea on 13/03/24
#ifndef Jueguito_CHARACTER_H
#define Jueguito_CHARACTER_H
#include<string>
#include "../Combat/Action.h"
#include <vector>
#include <cstring>

using namespace std;

class Character {
protected:
    char name[30];
    int health;
    int attack;
    int defense;
    int speed;
    bool isPlayer;
    bool fleed;
    char arm[20];

public:
    Character(char[30], int, int, int, int, bool, char[20]);

    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;


    void setName(char[30]);
    char* getName();
    void setHealth(int);
    int getHealth();
    void setAttack(int);
    int getAttack();
    void setDefense(int);
    int getDefense();
    void setSpeed(int);
    int getSpeed();
    char toString();
    bool getIsPlayer();
    bool hasFleed();
    void setArm(char[20]);
    char* getArm();
};

#endif