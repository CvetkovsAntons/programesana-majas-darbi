#include "Character.h"


Character::Character(string name, int life) {
    Character::name = name;
    Character::life = life;
}

bool Character::Hit(int damage) {
    Character::life--;

    if (Character::life == 0) {
        return false;
    }

    return true;
}

int Character::GetLife() {
    return Character::life;
}

void Character::Go(char direction) {
    for (int i = 0; i < 10; i++) {
        if (i != 9) {
            Character::path[i] = Character::path[i + 1];
        }
    }

    Character::path[9] = direction;
}

void Character::PrintCharacter() {
    cout << "Name: " << Character::name <<endl;

    if (Character::life > 0) {
        cout << "Status: Alive" << endl;
        cout << "Health: " << Character::life << endl;
    } else {
        cout << "Status: Dead" << endl;
    }

    cout << "Last 10 turns: ";

    for (int i = 0; i < 10; i++) {
        cout << Character::path[i] << " ";
    }
}

Character::~Character() {
    if (Character::life == 0) {
        cout << "Game over for " << Character::name << endl;
    }
}
