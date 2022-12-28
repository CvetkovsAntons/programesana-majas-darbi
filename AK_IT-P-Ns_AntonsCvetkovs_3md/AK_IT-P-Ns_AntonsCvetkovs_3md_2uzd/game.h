#include <iostream>
#include <random>

using namespace std;

string player; // mainigas, kas saglaba simbolu ar kuru speles cilveks pret datoru
bool draw = false; // maingias, kas norada uz vai ir izloze
int row, column; // mainigi, kas saglaba rindu un kolonu
int moveIndex;

// funkcija, kas dabu no ievadita cipara vajadzigo rinu un kolonu
bool getRowAndColumn(int move) {
    switch (move) {
        case 1: // ja lietotajs, izvelejoties kvadratu #1 speles laukuma
            row = 0; column = 0; // tad pieskiram maingaiem row un column vertibas 0
            break;
        case 2:
            row = 0; column = 1;
            break;
        case 3:
            row = 0; column = 2;
            break;
        case 4:
            row = 1; column = 0;
            break;
        case 5:
            row = 1; column = 1;
            break;
        case 6:
            row = 1; column = 2;
            break;
        case 7:
            row = 2; column = 0;
            break;
        case 8:
            row = 2; column = 1;
            break;
        case 9:
            row = 2; column = 2;
            break;
        default:
            return false;
    }

    return true;
}

// funkcija, kas parbauda vai kvadrats ir tukshs un ta var ierakstit simoblu
bool isTaken() {
    if (board[row][column] == "X" || board[row][column] == "O") {
        return false;
    }

    return true;
}

// datora solis. Dators vienkarsi izvelas nejauso brivo kvadratu
void botTurn() {
    bool move = false;

    while(!move) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> random(1,9);

        getRowAndColumn(random(gen));

        if (isTaken()) {
            move = true;
        }
    }
}

// funkcija, kas parbauda vai spele beidzas
bool gameOver() {
    // parbaudam vai ir tris vienadi simboli horizontala un vertikala linijas
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] ||
            board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return false;
        }
    }

    // parbaudam vai ir tris vienadi simboli dioganale
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] ||
        board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return false;
    }

    // parbaudam vai neizskirts
    if (moveIndex == 9) {
        draw = true;

        return false;
    }

    return true;
}

// funkcija, kas izvada uzvaretaju un atajuno speles laukumu
void getWinner() {
    system("CLS");

    displayBoard();

    if (draw) {
        cout << "\nDRAW!" << endl;
        system("pause");
    }

    if (!draw){
        if (turn == "O") {
            cout << "\nGame Over! Player X wins!" << endl;
            system("pause");
        } else {
            cout << "\nGame Over! Player O wins!" << endl;
            system("pause");
        }
    }

    board = {{"1","2","3"},{"4","5","6"},{"7","8","9"}};
    turn = "X";
    draw = false;
}

// funkcija, kas ieraksta lietotaja soli
void insertMove() {
    if (turn == "X") {
        board[row][column] = "X";
        turn = "O";
    } else {
        board[row][column] = "O";
        turn = "X";
    }
}