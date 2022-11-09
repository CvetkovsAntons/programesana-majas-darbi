#include <iostream>
#include "./Controller/PlayerVsCpu.h"
#include "./Controller/PlayerVsPlayer.h"

using namespace std;

string inputMainMenu() {
    string input;

    cout << "-------------------" << endl;
    cout << "1. Player vs Player" << endl;
    cout << "2. Player vs CPU" << endl;
    cout << "3. Exit" << endl;
    cout << "-------------------\n" << endl;
    cout << "Choose game type (enter numbers from 1 to 3): ";
    cin >> input;

    return input;
}

string inputConfirmationMenu() {
    string input;

    cout << "Are you sure? (Yes(1)   No(2))";
    cin >> input;

    return input;
}

int checkInputForSpecialCharacters(string numStr) {
    int i = 0;

    while (i < numStr.length()) {
        if (stoi(numStr) < 1 || stoi(numStr) > 3) {
            cout << "\n!!! You have to enter the number from 1 to 3 !!!" << endl;

            numStr = input();

            i = 0;

            continue;
        } else if (isdigit(numStr[i]) == false) {
            cout << "\n!!! You can enter only numbers !!!" << endl;

            numStr = input();

            i = 0;

            continue;
        }

        i++;
    }

    int num = stoi(numStr);

    return num;
}

bool confirmationMenu() {

}

bool mainMenu() {
    int menuInput = checkInputForSpecialCharacters(input());

    if(menuInput == 3) {

        return true;
    }

    if(menuInput == 1) {
        cout << "Player vs Player" << endl;
    }

    if(menuInput == 2) {
        cout << "Player vs CPU" << endl;
    }

    return false;
}

int main() {
    bool game = mainMenu();

    while (!game) {
        game = mainMenu();
    }

    return 0;
}
