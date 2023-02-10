#include <iostream>
#include <vector>

#include "structure.h"
#include "const.h"
#include "menu-input.h"
#include "functions.h"

using namespace std;


// izejas izvelne
bool exitConfirmation(int exit) {

    // ja funkcija atgriez 1, tad partraucam programmas darbu
    if (exit == 1) {
        return false;
    }

    return true;
}

// galvena izvelne
bool menu(int input) {
    // ja nevar atvert failu, tad atgriez kludu un partrauc programmas darbibu
    if (!openFileForReading(FILENAME)) {
        return false;
    }

    if (input == 1) {
        addData();
    }

    if (input == 2) {
        deleteData(inputDeleteAccountNumberError(inputDeleteAccountNumber()));
    }

    if (input == 3) {
        showData();
    }

    if (input == 4) {
        findClient(inputAccountNumberError(inputAccountNumber()));
    }

    if (input == 5) {
        editBalance(changeBalanceAccountNumberError(changeBalanceAccountNumber()));
    }

    if (input == 6) {
        showDebtors();
    }

    if (input == 7) {
        numOfClients();
    }

    if (input == 8) {
        copyFile();
    }

    if (input == 9) {
        return exitConfirmation(inputExitConfirmationError(inputExitConfirmation()));
    }

    return true;
}

int main() {
    // programma stadas, kamer lietotajs neizeis no ta
    while (menu(inputMenuError(inputMenu()))) {
        system("CLS");
    }

    return 0;
}
