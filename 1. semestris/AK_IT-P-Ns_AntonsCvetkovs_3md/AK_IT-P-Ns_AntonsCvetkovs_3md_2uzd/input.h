#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> board = {{"1","2","3"},{"4","5","6"},{"7","8","9"}}; // spelu laukums
string menuType = "main"; // mainigais, kas saglaba atverto izvelni
string turn = "X"; // speletaja karta

// funkcija, kas izvada spelest laukumu
void displayBoard() {
    cout<<"    |    |    \n";
    cout<<" "<<board[0][0]<<"  | "<<board[0][1]<<"  |  "<<board[0][2]<<" \n";
    cout<<"____|____|____\n";
    cout<<"    |    |    \n";
    cout<<" "<<board[1][0]<<"  | "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
    cout<<"____|____|____\n";
    cout<<"    |    |    \n";
    cout<<" "<<board[2][0]<<"  | "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";
    cout<<"    |    |    \n";
}

// funkcija, kas izvada galvenu izvelni
string inputMainMenu() {
    string input;

    menuType = "main";

    system("CLS");
    cout << "-------------------" << endl;
    cout << "1. Player vs Player" << endl;
    cout << "2. Player vs BOT" << endl;
    cout << "3. Exit" << endl;
    cout << "-------------------\n" << endl;
    cout << "Choose game type (enter numbers from 1 to 3): " << flush;
    cin >> input;

    return input;
}

// funkcija, kas izvada izejas izvelni
string inputConfirmationMenu() {
    string input;

    menuType = "confirmation";

    system("CLS");
    cout << "--------------------------" << endl;
    cout << "Are you sure want to exit?" << endl;
    cout << "      Yes(1)   No(2)      " << endl;
    cout << "--------------------------\n" << endl;

    cout << "Your answer: " << flush;
    cin >> input;

    return input;
}

// funkcija, kas izvada speletaja sola izvelni
string inputPlayerTurn() {
    string input;

    menuType = "playerTurn";

    system("CLS");

    displayBoard();

    cout << "Player " << turn << " turn: " << flush;

    cin >> input;

    return input;
}

// funkcija, kas izvada speles atkartojuma izvelni
string inputRetryMenu() {
    string input;

    menuType = "retry";

    system("CLS");
    cout << "--------------------------" << endl;
    cout << "   Do you want to retry?  " << endl;
    cout << "      Yes(1)   No(2)      " << endl;
    cout << "--------------------------\n" << endl;

    cout << "Your answer: " << flush;
    cin >> input;

    return input;
}

// funkcija, kas izvada cilveka simbolu izvelni
string inputPlayerSymbol() {
    string input;

    menuType = "playerSymbol";

    system("CLS");
    cout << "--------------------------" << endl;
    cout << "    Choose your symbol    " << endl;
    cout << "       X(1)    O(2)       " << endl;
    cout << "--------------------------\n" << endl;

    cout << "Your answer:" << flush;
    cin >> input;

    return input;
}