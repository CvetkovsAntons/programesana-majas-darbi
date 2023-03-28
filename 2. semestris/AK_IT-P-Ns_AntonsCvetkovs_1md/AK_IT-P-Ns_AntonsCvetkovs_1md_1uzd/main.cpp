#include <iostream>

#include "Character.h"

using namespace std;

// 1. persoanza tests
void firsCharacterTest() {
    Character character1("Character 1", 5);

    character1.PrintCharacter();

    cout << endl;

    character1.Go('r');
    character1.Hit(1);
    character1.Go('t');
    character1.Hit(1);
    character1.Go('l');
    character1.Hit(1);
    cout << "Ja tiek ievadits nepareizs kustibas virziens" << endl;
    character1.Go('a');
    character1.Go('b');
    character1.Hit(1);

    cout << endl;

    character1.PrintCharacter();

    cout << endl;
}

// 2. personaza test
void secondCharacterTest() {
    Character character2("Character 2", 12); // max dzives skaits ir 10, ja tiek ievadita lielaka vertiba tad pieskirta vertiba bus 10

    character2.PrintCharacter();

    cout << endl;

    character2.Go('t');
    character2.Hit(1);
    character2.Go('b');
    character2.Hit(1);
    character2.Go('l');
    character2.Hit(1);
    character2.Go('r');
    character2.Hit(1);
    character2.Go('t');
    character2.Hit(1);
    character2.Go('b');
    character2.Hit(1);
    character2.Go('l');
    character2.Hit(1);
    character2.Go('r');
    character2.Hit(1);
    character2.Go('l');
    character2.Go('r');
    character2.Go('t');
    character2.Hit(1);
    character2.Go('b');
    cout << "Kad personazs ir miris" << endl;
    character2.Hit(1);

    cout << endl;

    character2.PrintCharacter();

    cout << endl;

    cout << "Funckijas Go() izsaukums mirusam personazam" << endl;

    character2.Go('r');

    cout << endl;

    cout << "Funckijas Hit() izsaukums mirusam personazam" << endl;

    character2.Hit(1000);

    cout << endl;
}

int main() {
    cout << "----------------------------------" << endl;

    cout << "1. personazs\n\n";

    firsCharacterTest();

    cout << "----------------------------------" << endl;

    cout << "2. personazs\n\n";

    secondCharacterTest();

    cout << "----------------------------------" << endl;

    system("PAUSE");

    return 0;
}
