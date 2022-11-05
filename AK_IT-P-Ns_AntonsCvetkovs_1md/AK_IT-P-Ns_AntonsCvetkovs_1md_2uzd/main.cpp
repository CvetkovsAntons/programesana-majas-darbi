#include <iostream>
#include <random> // biblioteka, kas ir nepieciesama lai izveidot nejausu skaitli

using namespace std;

int randomNumber() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> random(0,100);

    return random(gen);
}



string input() {
    string num;

    cout << "Ievadiet veselo skaitli no 0 lidz 100:";

    cin >> num;

    return num;
}



int checkInputForSpecialCharacters(string numStr) {
    int i = 0;

    while (i < numStr.length()) {
        if (isdigit(numStr[i]) == false) {
            cout << "\n!!! Jaievada veselo skaitli intervala no 0 lidz 100 !!!" << endl;

            numStr = input();

            i = 0;

            continue;
        }

        i++;
    }

    int num = stoi(numStr);

    return num;
}



int userNumber() {
    int num = checkInputForSpecialCharacters(input());

    while (num < 0 || num > 100) {
        cout << "\n!!! Jaievada veselo skaitli intervala no 0 lidz 100 !!!" << endl;

        num = checkInputForSpecialCharacters(input());
    }

    return num;
}



bool game() {
    int random = randomNumber();

    for (int i = 1; i <= 10; i++) {

        int user = userNumber();

        if (user < random) {
            cout << "\nSkaitlis ir lielaks par ievadito!"  << endl;
            continue;
        }

        if (user > random) {
            cout << "\nSkaitlis ir mazaks par ievadito!"  << endl;
            continue;
        }

        if (user == random) {
            cout << "\nJus uzvarejat no " << i << ". meginajuma!"  << endl;
            return true;
        }
    }

    return false;
}



int main() {
    bool win = game();

    if (!win) {
        cout << "\nJus zaudejat!";
    }

    return 0;
}
