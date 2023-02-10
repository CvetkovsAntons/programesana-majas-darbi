#include <iostream>
#include <conio.h>
#include <cstring>
#include "Character.h"

using namespace std;

char playersMoveValidation() {
    string input;

    cout << "drage1" << endl;

    cout << "Enter the next move (t-top, b-bottom, l-left, r-right): ";
    cin >> input;
    cout << endl;

    bool valid = false;

    while (!valid) {
        if (input.length() > 1) {
            cout << "Entered move value length is too large, enter new one (t-top, b-bottom, l-left, r-right):  ";
            cin >> input;
            cout << endl;
            continue;
        }

        if (input != "t" && input != "b" && input != "l" && input != "r") {
            cout << "drage3" << endl;
            cout << "Entered move value is incorrect, enter new one (t-top, b-bottom, l-left, r-right): ";
            cin >> input;
            cout << endl;
            continue;
        }

        valid = true;
    }

    char move[2];
    strcpy(move, input.c_str());

    return move[0];
}

int main() {
    Character character("name", 10);

    character.Go(playersMoveValidation());

    character.Go(playersMoveValidation());

    character.PrintCharacter();



    return 0;
}
