//created by Pc Andrea on 13/03/24
#ifndef Juego_ENEMY_H
#define Juego_ENEMY_H
#include "../Character/Character.h"
#include "../Player/Player.h"
#include "../Combat/Action.h"


struct Action;
class Player;

class Enemy: public Character {
public:

    Enemy(char[30] , int, int, int, int, char[20] );
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    Character* getTarget(vector<Player*> teamMembers);
    Action takeAction(vector<Player*> player);


    //Para obtener el estado de salud de mi enemigo
    int MaxHealth;

};


#endif