#include <iostream>

#include "input.h"
#include "game.h"

using namespace std;

// funkcija, kas parbauda lietotaja ievadi uz kludam
int checkInputForErrors(string inputStr) {
    int i = 0;

    while (i < inputStr.length()) {

        system("CLS");

        // parbaudam vai ievade ir skaitlis
        if (isdigit(inputStr[i]) == false) {
            cout << "\n!!! You only can enter numbers !!!" << endl;

            system("pause");

            if (menuType == "main") {
                inputStr = inputMainMenu();
            }

            if (menuType == "confirmation") {
                inputStr = inputConfirmationMenu();
            }

            if (menuType == "playerTurn") {
                inputStr = inputPlayerTurn();
            }

            if (menuType == "playerSymbol") {
                inputStr = inputPlayerSymbol();
            }

            if (menuType == "retry") {
                inputStr = inputPlayerTurn();
            }

            i = 0;

            continue;
        }

        // ja ievads ir skaitlis, tad parbaudam vai ievadits skailtis atbilst izvelnes punktam
        if (menuType == "main") {
            if (stoi(inputStr) < 1 || stoi(inputStr) > 3) {
                cout << "\n!!! You have to enter the number from 1 to 3 !!!" << endl;

                system("pause");

                inputStr = inputMainMenu();

                i = 0;

                continue;
            }
        }

        if (menuType == "confirmation") {
            if (stoi(inputStr) < 1 || stoi(inputStr) > 2) {
                cout << "\n!!! You have to enter the number from 1 to 2 !!!" << endl;

                system("pause");

                inputStr = inputConfirmationMenu();

                i = 0;

                continue;
            }
        }

        if (menuType == "retry") {
            if (stoi(inputStr) < 1 || stoi(inputStr) > 2) {
                cout << "\n!!! You have to enter the number from 1 to 2 !!!" << endl;

                system("pause");

                inputStr = inputRetryMenu();

                i = 0;

                continue;
            }
        }

        if (menuType == "playerSymbol") {
            if (stoi(inputStr) < 1 || stoi(inputStr) > 2) {
                cout << "\n!!! You have to enter the number from 1 to 2 !!!" << endl;

                system("pause");

                inputStr = inputPlayerSymbol();

                i = 0;

                continue;
            }
        }

        if (menuType == "playerTurn") {
            if (!getRowAndColumn(stoi(inputStr))) {
                cout << "\n!!! You have to enter the number from 1 to 9 !!!" << endl;

                system("pause");

                inputStr = inputPlayerTurn();

                i = 0;

                continue;
            }

            if (!isTaken()) {
                cout << "\n!!! This field is already taken !!!" << endl;

                system("pause");

                inputStr = inputPlayerTurn();

                i = 0;

                continue;
            }
        }

        i++;
    }

    int input = stoi(inputStr);

    return input;
}

// funkicja, kas parbauda vai lietotaj grib atkartot speli
bool retry() {
    int input = checkInputForErrors(inputRetryMenu());

    if (input == 1) {
        return true;
    }

    return false;
}

// funkcija, kas uzsak cilveka pret cilveku speli
void playerVsPlayer() {
    moveIndex = 0;

    do {
        moveIndex++;

        checkInputForErrors(inputPlayerTurn()); // pieprasam lietotaju ievadit kvadratu speles laukuma

        insertMove(); // ierakstam spelejata soli
    } while (gameOver()); // spele turpinas, kamer ta nebeigsies :)

    getWinner(); // izvadam uzvaretaju
}

// funkcija, kas uzsak cilveka pret datoru speli
void playerVsBot() {
    moveIndex = 0;

    // pieprasam leitotaju izveleties ar kuru simoblu vins grib spelet
    if (checkInputForErrors(inputPlayerSymbol()) == 1) {
        player = "X";
    } else {
        player = "O";
    }

    do {
        moveIndex++;

        if (turn == player) {
            checkInputForErrors(inputPlayerTurn()); // pieprasam cilveku uzstaisit soli
        } else {
            botTurn(); // dators taisa soli
        }

        insertMove(); // ierakstam spelejata soli
    } while (gameOver()); // spele turpinas, kamer ta nebeigsies :)

    getWinner(); // izvadam uzvaretaju
}

// funkcija, kas pieprasa apstiptinat izeju no programmas
bool confirmationMenu() {
    int confirmationInput = checkInputForErrors(inputConfirmationMenu());

    if(confirmationInput == 1) {
        return false;
    }

    return true;
}

// funkcija, kas izvada galveno izvelni
bool mainMenu() {
    int menuInput = checkInputForErrors(inputMainMenu());

    // uzsakam speli cilveks pret cilveku
    if(menuInput == 1) {
        do {
            playerVsPlayer();
        } while(retry());
    }

    // uzsakam speli cilveks pret datoru
    if(menuInput == 2) {
        do {
            playerVsBot();
        } while(retry());
    }

    // izeja no programmas
    if(menuInput == 3) {
        bool exit = confirmationMenu();

        return exit;
    }

    return true;
}

int main() {
    bool game = mainMenu();

    while (game) {
        game = mainMenu();
    }

    return 0;
}