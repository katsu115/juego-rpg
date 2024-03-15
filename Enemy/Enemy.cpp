//created by Pc Andrea on 13/03/24
#include "Enemy.h"
#include <iostream>


using namespace std;


int getRolledAttack(int attack) {
    int lowerLimit = attack * .80;
    return (rand() % (attack - lowerLimit)) + lowerLimit;
}

Enemy::Enemy(string name, int health, int attack, int defense, int speed) : Character(name, health, attack, defense, speed, false) {
}

void Enemy::doAttack(Character *target) {
    int rolledAttack = getRolledAttack(getAttack());
    int trueDamage = target->getDefense() > rolledAttack ? 0 : rolledAttack - target->getDefense();
    target->takeDamage(trueDamage);
}

void Enemy::takeDamage(int damage) {
    setHealth(getHealth() - damage);
    if(getHealth() <= 0) {
        cout<<getName()<<" has died"<<endl;
    }
    else {
        cout<<getName()<<" has taken " << damage << " damage" << endl;
    }
}

Character* Enemy::getTarget(vector<Player *> teamMembers) {

    int targetIndex = 0;
    int lowestHealth = INT_MAX;
    for(int i=0; i < teamMembers.size(); i++) {
        if(teamMembers[i]->getHealth() < lowestHealth) {
            lowestHealth = teamMembers[i]->getHealth();
            targetIndex = i;
        }
    }

    return teamMembers[targetIndex];
}

Action Enemy::takeAction(vector<Player *> players) {
    Action myAction;
    myAction.speed = getSpeed();
    myAction.subscriber = this;
    Character* target = getTarget(players);
    myAction.target = target;

    // Calcular la probabilidad de escape si el jugador tiene menos del 15% de vida
    if (target->getHealth() < target->getHealth() * 15) {
        // Generar un número aleatorio entre 1 y 100
        int escapeChance = rand() % 100 + 1;
        // Si el número aleatorio está dentro del 5%, el enemigo intenta escapar
        if (escapeChance <= 15) {
            myAction.action = [this]() {
                cout << getName() << " ha escapado." << endl;
            };
            return myAction;
        }
    }

    // Si no intenta escapar, realiza el ataque normal
    myAction.action = [this, target]() {
        doAttack(target);
    };

    return myAction;
}