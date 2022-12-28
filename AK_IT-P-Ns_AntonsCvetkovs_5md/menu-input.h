#include <iostream>

using namespace std;
// ievade galvena izvelne
string inputMenu() {
    string input;

    system("CLS");

    cout << "1. Add new client"
            "\n2. Delete the client"
            "\n3. Show all clients"
            "\n4. Find the client (by account number)"
            "\n5. Edit clients balance"
            "\n6. Show all debtors"
            "\n7. Show number of clients"
            "\n8. Create database copy"
            "\n9. Exit"
            << endl;

    cout << "-----------------------------------------------------" << endl;

    cout << "Select operation you want to execute(enter number from 1 to 9): ";
    cin >> input;

    return input;
}
// ievade izejas izvelne
string inputExitConfirmation() {
    string input;

    system("CLS");

    cout << "------------------------------" << endl;

    cout << "Are you sure you want to exit?" << endl;
    cout << "        Yes(1)  No(2)         " << endl;

    cout << "------------------------------" << endl;

    cout << "Select your option(enter number from 1 to 2): ";
    cin >> input;

    return input;
}
// ievade increase vai decrease lietotaju balansu izvelne
string increaseDecreaseBalance() {
    string input;

    system("CLS");

    cout << "1. INCREASE clients balance"
            "\n2. DECREASE balance"
         << endl;

    cout << "-----------------------------------------------------" << endl;

    cout << "Select your option(enter number from 1 to 3): ";
    cin >> input;

    return input;
}
// ievade lietotaja numuru lai atrast to
string inputAccountNumber() {
    string input;

    system("CLS");

    cout << "Enter clients account number that you want to find:";
    cin >> input;

    return input;
}
// ievade lietotaja numuru lai atrast to prieks balanas mainas
string changeBalanceAccountNumber() {
    string input;

    system("CLS");

    cout << "Enter account number of the client whom balance you want to change:";
    cin >> input;

    return input;
}
// ievade lietotaja numuru lai izdest to
string inputDeleteAccountNumber() {
    string input;

    system("CLS");

    cout << "Enter account number of the client you want to delete:";
    cin >> input;

    return input;
}
// ievade lietotaja balansu
string balanceInput() {
    string input;

    cout << "Balance (use float number seperated with the dot('.') symbol and maximum 2 characters after the dot('.') symbol):";
    cin >> input;

    return input;
}
// ievae palielina lietotaja balansu
string increaseBalanceInput() {
    string input;

    system("CLS");

    cout << "Increase the balance by:";
    cin >> input;

    return input;
}
// ievae samazina lietotaja balansu
string decreaseBalanceInput() {
    string input;

    system("CLS");

    cout << "Decrease the balance by:";
    cin >> input;

    return input;
}
// ievade galvena izvelne parbaude uz ievades kludam
int inputMenuError(string input) {
    int i = 0;

    system("CLS");

    while (i < input.length()) {
        if (isdigit(input[i]) == false || stoi(input) < 1 || stoi(input) > 9) {
            cout << "\nERROR! Please use numbers 1-9 to choose needed section in the main menu!" << endl;

            system("pause");

            input = inputMenu();

            i = 0;

            continue;
        }

        i++;
    }

    return stoi(input);
}
// ievade izejas izvelne uz ievades kludam
int inputExitConfirmationError(string input) {
    int i = 0;

    system("CLS");

    while (i < input.length()) {
        if (isdigit(input[i]) == false || stoi(input) < 1 || stoi(input) > 2) {
            cout << "\nERROR! Please use numbers 1-2!" << endl;

            system("pause");

            input = inputExitConfirmation();

            i = 0;

            continue;
        }

        i++;
    }

    return stoi(input);
}
// ievade increase vai decrease lietotaju balansu izvelne uz ievades kludam
int increaseDecreaseBalanceError(string input) {
    int i = 0;

    system("CLS");

    while (i < input.length()) {
        if (isdigit(input[i]) == false || stoi(input) < 1 || stoi(input) > 2) {
            cout << "\nERROR! Please use numbers 1-3!" << endl;

            system("pause");

            input = increaseDecreaseBalance();

            i = 0;

            continue;
        }

        i++;
    }

    return stoi(input);
}
// ievade lietotaja numuru lai atrast to uz ievades kludam
int inputAccountNumberError(string input) {
    int i = 0;

    system("CLS");

    while (i < input.length()) {
        if (isdigit(input[i]) == false) {
            cout << "\nERROR! Please use integer numbers!" << endl;

            system("pause");

            input = inputAccountNumber();

            i = 0;

            continue;
        }

        i++;
    }

    return stoi(input);
}
// ievade lietotaja numuru lai atrast to prieks balanas mainas uz ievades kludam
int inputDeleteAccountNumberError(string input) {
    int i = 0;

    system("CLS");

    while (i < input.length()) {
        if (isdigit(input[i]) == false) {
            cout << "\nERROR! Please use integer numbers!" << endl;

            system("pause");

            input = inputDeleteAccountNumber();

            i = 0;

            continue;
        }

        i++;
    }

    return stoi(input);
}
// ievade lietotaja numuru lai izdest to uz ievades kludam
int changeBalanceAccountNumberError(string input) {
    int i = 0;

    system("CLS");

    while (i < input.length()) {
        if (isdigit(input[i]) == false) {
            cout << "\nERROR! Please use integer numbers!" << endl;

            system("pause");

            input = changeBalanceAccountNumber();

            i = 0;

            continue;
        }

        i++;
    }

    return stoi(input);
}
// ievade lietotaja balansu uz ievades kludam
float balanceInputError(string input) {
    bool valid = false;

    system("CLS");

    while (!valid) {
        int numberOfDots = count(input.begin(), input.end(), '.');

        if (numberOfDots > 1) {
            cout << "\nERROR! Please use float number, seperated with the dot('.') symbol!" << endl;

            system("pause");

            input = balanceInput();

            continue;
        }

        bool skip = false;

        int i = 0;

        while (i < input.length()) {
            if (!isdigit(input[i]) && input[i] != '.') {
                cout << "\nERROR! Please use float number, seperated with the dot('.') symbol!" << endl;

                system("pause");

                input = balanceInput();

                i = 0;

                skip = true;

                continue;
            }

            i++;
        }

        if (skip) {
            continue;
        }

        if ((input.substr(input.find('.') + 1)).length() > 2 && numberOfDots != 0) {
            cout << "\nERROR! Too much characters after the dot('.') symbol!" << endl;

            system("pause");

            input = balanceInput();

            continue;
        }

        valid = true;
    }

    return stof(input);
}
// ievae palielina lietotaja balansu uz ievades kludam
float increaseBalanceInputError(string input) {
    bool valid = false;

    system("CLS");

    while (!valid) {
        int numberOfDots = count(input.begin(), input.end(), '.');

        if (numberOfDots > 1) {
            cout << "\nERROR! Please use float number, seperated with the dot('.') symbol!" << endl;

            system("pause");

            input = increaseBalanceInput();

            continue;
        }

        bool skip = false;

        int i = 0;

        while (i < input.length()) {
            if (!isdigit(input[i]) && input[i] != '.') {
                cout << "\nERROR! Please use float number, seperated with the dot('.') symbol!" << endl;

                system("pause");

                input = increaseBalanceInput();

                i = 0;

                skip = true;

                continue;
            }

            i++;
        }

        if (skip) {
            continue;
        }

        if ((input.substr(input.find('.') + 1)).length() > 2 && numberOfDots != 0) {
            cout << "\nERROR! Too much characters after the dot('.') symbol!" << endl;

            system("pause");

            input = increaseBalanceInput();

            continue;
        }

        valid = true;
    }

    return stof(input);
}
// ievae samazina lietotaja balansu uz ievades kludam
float decreaseBalanceInputError(string input) {
    bool valid = false;

    system("CLS");

    while (!valid) {
        int numberOfDots = count(input.begin(), input.end(), '.');

        if (numberOfDots > 1) {
            cout << "\nERROR! Please use float number, seperated with the dot('.') symbol!" << endl;

            system("pause");

            input = decreaseBalanceInput();

            continue;
        }

        bool skip = false;

        int i = 0;

        while (i < input.length()) {
            if (!isdigit(input[i]) && input[i] != '.') {
                cout << "\nERROR! Please use float number, seperated with the dot('.') symbol!" << endl;

                system("pause");

                input = decreaseBalanceInput();

                i = 0;

                skip = true;

                continue;
            }

            i++;
        }

        if (skip) {
            continue;
        }

        if ((input.substr(input.find('.') + 1)).length() > 2 && numberOfDots != 0) {
            cout << "\nERROR! Too much characters after the dot('.') symbol!" << endl;

            system("pause");

            input = decreaseBalanceInput();

            continue;
        }

        valid = true;
    }

    return stof(input);
}