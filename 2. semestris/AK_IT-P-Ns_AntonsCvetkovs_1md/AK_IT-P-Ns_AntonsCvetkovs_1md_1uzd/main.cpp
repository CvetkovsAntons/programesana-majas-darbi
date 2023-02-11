#include <iostream>
#include <conio.h>
#include <cstring>
#include <vector>

#include "Character.h"
#include "CharacterCreation.h"
#include "PlayerControl.h"

using namespace std;

void firsCharacterTest() {
    string name = newCharacterName();
    int health = newCharacterHealth();

    Character character1(name, health);

    character1.PrintCharacter();

    for (int i = 0; i < 5; i++) {
        character1.Go(getPlayerMove(character1));
        character1.Hit(1);
    }

    character1.PrintCharacter();
}

void secondCharacterTest() {
    string name = newCharacterName();
    int health = newCharacterHealth();

    Character character2(name, health);

    character2.PrintCharacter();

    while (character2.GetLife() > 0) {
        character2.Go(getPlayerMove(character2));

        if (!character2.Hit(1)) {
            character2.~Character();
        }
    }

    character2.PrintCharacter();

    cout << "Funckijas Go() izsaukums mirusam personazam" << endl;

    character2.Go(getPlayerMove(character2));

    cout << "Funckijas Hit() izsaukums mirusam personazam" << endl;

    character2.Hit(1000);
}

int main() {
    firsCharacterTest();

    cout << "----------------------------------" << endl;

    secondCharacterTest();

    return 0;
}
