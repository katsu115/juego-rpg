//created by Pc Andrea on 13/03/24
#include <iostream>
#include "Enemy/Enemy.h"
#include "Player/Player.h"
#include "Combat/Combat.h"


using namespace std;

int main() {

    Player *player = new Player("nodca", 4, 7, 2, 10);
    Enemy *enemy = new Enemy("katsu", 20, 5, 2, 7);
    Enemy *enemy2 = new Enemy("lolo", 10, 5, 5, 2);

    vector<Character*> participants;
    participants.push_back(player);
    participants.push_back(enemy);
    participants.push_back(enemy2);


    Combat* combat = new Combat(participants);
    combat -> doCombat();

    delete player;
    delete enemy;
    delete combat;

    return 0;
}
