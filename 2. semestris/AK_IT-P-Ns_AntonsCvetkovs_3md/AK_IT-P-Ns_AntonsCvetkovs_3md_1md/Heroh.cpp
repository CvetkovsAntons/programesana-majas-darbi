#include "Hero.h"

Hero::Hero(string name, int life) : Character(name, life) {
    Hero::experience = 0;
}

Hero::~Hero() {
    cout << "Game over for " << endl;
}

void Hero::Kill(Monster &monster) {
    Hero::experience += monster.GetLevel() * monster.GetLife()
}

void Hero::Print() {
    Hero::PrintCharacter();
    cout << "Experience: " << Hero::experience << endl;
}