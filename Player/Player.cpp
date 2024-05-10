//created by Pc Andrea on 13/03/24

#include "Player.h"
#include <iostream>
#include "../Utils.h"
#include <cstring>
#include "Combat.h"
using namespace std;
using namespace combat_utils;


bool compareSpeed(Enemy *a, Enemy *b) {
    return a->getSpeed() > b->getSpeed();
}

Player::Player(char name[30], int health, int attack, int defense, int speed, char arm[20], int experience, int level) : Character(name, health, attack, defense, speed, true, arm, experience, level) {

}

void Player::doAttack(Character *target) {
    int rolledAttack = getRolledAttack(getAttack());
    int trueDamage = target->getDefense() > rolledAttack ? 0 : rolledAttack - target->getDefense();
    target->takeDamage(trueDamage);
}

void Player::takeDamage(int damage) {
    setHealth(health - damage);
    cout << "You have taken " << damage << " damage whit a "<< getArm() << endl;
    if (health <= 0) {
        cout << "You have died  GAME OVER " << endl;
    }
}


void Player::flee(vector<Enemy*> enemies) {
    std::sort(enemies.begin(), enemies.end(), compareSpeed);
    Enemy *fastestEnemy = enemies[0];
    bool fleed = false;
    if (this->getSpeed() > fastestEnemy->getSpeed()) {
        fleed = true;
    } else {
        srand(time(NULL));
        int chance = rand() % 100;
        cout << "chance to flee " << chance << endl;
        if (fleed = chance > 90) {
            fleed = true;
        } else {
            cout << "You can't be fleed, fight homosexual " << endl;
        }
    }

    this->fleed = fleed;

}

void Player::emote() {
    cout<<"Jokes on you" << endl;
}


Character* Player::getTarget(vector<Enemy *> enemies) {
    cout << "Choose a target" << endl;
    int targetIndex = 0;
    for(int i = 0; i < enemies.size(); i++) {
        cout << i << ". " << enemies[i]->getName() << endl;
    }
    cin >> targetIndex;

    return enemies[targetIndex];
}

void Player::gainExperience(Enemy* enemy) {

    if (enemy && enemy->health <= 0) {

        experience += enemy->experience;

        LevelUp();
    }
}

void Player::LevelUp() {
    while (experience >= 100) {
        level++;
        experience -= 100;
        int healthGain = 10;
        int attackGain = 5;
        int defenseGain = 5;
        health += healthGain;
        attack += attackGain;
        defense += defenseGain;
        int totalPointsGained = healthGain + attackGain + defenseGain;
    }
}


Action Player::takeAction(vector<Enemy*>enemies) {
    int option = 0;
    cout<<"////////////////"<<endl;
    cout<<"Choose an action"<<endl;
    cout<<"1. Attack"<<endl;
    cout<<"2. Flee"<<endl;

    cin >> option;
    Character* target = nullptr;


    Action myAction;

    myAction.speed = this->getSpeed();
    myAction.subscriber = this;

    switch (option) {
        case 1:
            target = getTarget(enemies);
            myAction.target = target;
            //1.
            myAction.action = [this, target]() {
                doAttack(target);
            };
            break;
        case 2:
            myAction.action = [this, enemies]() {
                flee(enemies);
            };
            break;
        default:
            cout << "Invalid option" << endl;
            break;
    }


    return myAction;
}