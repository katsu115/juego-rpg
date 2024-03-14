//created by Pc Andrea on 13/03/24
#ifndef Jueguito_ENEMY_H
#define Jueguito_ENEMY_H
#include "../Character/Character.h"
#include "../Player/Player.h"
#include "../Combat/Action.h"


struct Action;
class Player;

class Enemy: public Character {
public:

    Enemy(string, int, int, int, int);
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    Character* getTarget(vector<Player*> teamMembers);
    Action takeAction(vector<Player*> player);

};


#endif