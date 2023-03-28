#include "Character.h"

// klases kontruktors
Character::Character(string name, int life) {
    Character::name = name;

    if (life > 10) { // ja ievadits dzives skaits ir lielaks par 10, tad pieskiram maksimalu vertibu (10)
        Character::life = 10;
        return;
    }

    if (life < 1) { // ja ievadits dzives skaits ir mazaks par 1, tad pieskiram minimalu vertibu (1)
        Character::life = 1;
        return;
    }

    Character::life = life;
}

bool Character::Hit(int damage) {
    if (Character::life > 0) { // ja personazs ir dzivs tad atnemam dzives punktus
        if (damage >= Character::life) { // ja damage ir vienads vai lielaks par personaza dzives skaitu, tad vins ir miris
            Character::life = 0;

            cout << Character::name << " is dead!" << endl; // izvadam pazinojumu, ka personazs ir miris

            return false; // partraucam funkcijas darbu atgriezot false
        }

        Character::life -= damage;

        if (Character::life > 0) { // ja personazs ir dzivs tad atgriezam true
            return true;
        }
    }

    cout << Character::name << " is dead!" << endl; // izvadam pazinojumu, ka personazs ir miris

    return false; // atgriezam false
}

int Character::GetLife() const { // personaza dzives getters
    return Character::life;
}

void Character::Go(char direction) {
    // ja tiek ievadits nepareizs kustibas virziens, tad izvadam kludu
    if (direction != 't' && direction != 'r' && direction != 'l' && direction != 'b' && Character::life > 0) {
        cout << "Move direction is invalid" << endl;
        return; // ar return partraucam funkcijas darbu
    }

    if (Character::life > 0) { // nosacijums izpildas, ja personazs ir dzivs
        for (int i = 0; i < 10; i++) { // cikls for, kas izpildisies 10 reizes
            if (i != 9) { // ja i nav vienads ar pedeja masiva elementa ideksu, tad
                Character::path[i] = Character::path[i + 1]; // parnesam vertivas pa kreisis (1. vertiba vieta tiek novietota 2. vertiba, ta vieta 3. vertiba)
            }
        }

        Character::path[9] = direction; // pieskiram masiva pedejam elementam jaunu vertibu
        return; // partraucam funkcijas darbu
    }

    cout << Character::name << " is dead!" << endl; // ja personas ir miris, izvadam pazinojumu par to
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
    cout << "Game over for " << Character::name << endl;
}
