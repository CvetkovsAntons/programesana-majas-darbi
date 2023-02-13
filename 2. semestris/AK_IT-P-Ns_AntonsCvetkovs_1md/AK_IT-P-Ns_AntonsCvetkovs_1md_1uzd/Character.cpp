#include <cstring>

#include "Character.h"

Character::Character(string name, int life) {
    Character::name = name;
    Character::life = life;
}

bool Character::Hit(int damage) {
    if (Character::life > 0) {
        if (damage >= Character::life) {
            Character::life -= Character::life;
        }

        Character::life -= damage;

        if (Character::life > 0) {
            return true;
        }
    }

    Character::~Character();

    return false;
}

int Character::GetLife() const {
    return Character::life;
}

void Character::Go(char direction) {
    if (direction != 't' && direction != 'r' && direction != 'l' && direction != 'b' && Character::life > 0) {
        cout << "Move direction is invalid" << endl;
        return;
    }

    if (Character::life > 0) {
        for (int i = 0; i < 10; i++) {
            if (i != 9) {
                Character::path[i] = Character::path[i + 1];
            }
        }

        Character::path[9] = direction;
        return;
    }

    Character::~Character();
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

    cout << endl;
}

Character::~Character() {
    if (Character::life < 1) {
        cout << "Game over for " << Character::name << endl;
    }
}
