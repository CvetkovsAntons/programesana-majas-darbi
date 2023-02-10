#include <iostream>

using namespace std;

// funkcija, kas parbauda ivadito laiku
bool inputCheckForErrors(string input) {
    // pareiza laika formata jabut 8 simboliem
    if (input.length() != 8) {
        cout << "!!! Nepareizs formats. Jabut ievaditiem 8 simboliem !!!" << endl;
        return false;
    }

    for (int i = 0; i < input.length(); i++) {
        // pareiza laika formata tresais un sestais simboli ir ':'
        if (i == 2 || i == 5) {
            if (input[i] != ':' || input[i] != ':') {
                cout << "!!! Nepareizs formats. Nav ':' !!!" << endl;

                return false;
            }

            continue;
        }

        // pareiza laika formata nevar but burtu un specialu simbolu
        // ASCII tabula cipari ir no 48 lidz 57 elementam
        // es meginaju uzrakstit (input[i] <= 48 && input[i] >= 57), bet tas nosacijums visulaiku izvadija 'false'
        if (input[i] >= 48 && input[i] <= 57) {
            continue;
        } else {
            cout << "!!! Nepareizs formats. Nedrikst izmantot burtus un specialas zimes !!!" << endl;

            return false;
        }
    }

    // parbaudam vai visi laiku vertibas ir ievaditi pareizi
    if (stoi(input.substr(0, 2)) > 23 || stoi(input.substr(3, 5)) > 59 || stoi(input.substr(6, 8)) > 59) {
        cout << "!!! Nepareizs laiks !!!" << endl;

        return false;
    }

    return true;
}


int main() {
    string time;

    do {
        cout << "Ievadiet laiku (Pareizs formats: hh:mm:ss):"; // pieprasam lietotaju ievadit laiku
        cin >> time;
    } while (!inputCheckForErrors(time)); // programma izpildisies, kamer nebus ievadits pareisz laiks

    cout << "Laiks: " << time; // izvadam laiku

    return 0;
}
