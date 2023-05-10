#include "Hero.h"

Hero::Hero(string name, int life, int experience) : Character(name, life) {
    Hero::experience = (experience > 0) ? experience : 1;
}

void Hero::Kill(Monster &monster) {
    Hero::experience += monster.GetOriginalLife() * monster.GetLevel();
    monster.Hit(monster.GetLife());
}

void Hero::Print() {
    Hero::PrintCharacter();
    cout << "Experience: " << Hero::experience << endl;
}