#ifndef AK_IT_P_NS_ANTONSCVETKOVS_1MD_CHARACTERCREATION_H
#define AK_IT_P_NS_ANTONSCVETKOVS_1MD_CHARACTERCREATION_H

using namespace std;

string newCharacterName() {
    string input;

    cout << "Enter new character name: ";
    getline(cin, input);
    cout << endl;

    return input;
}

int newCharacterHealth() {
    string input;

    cout << "Enter new character health value (must be > 0): ";
    getline(cin, input);
    cout << endl;

    int i = 0;
    while (i < input.length()) {
        if (!isdigit(input[i]) || stoi(input) < 1) {
            cout << "ERROR: Wrong value was entered. Health must be integer and greater then 0: ";
            getline(cin, input);
            cout << endl;

            i = 0;

            continue;
        }

        i++;
    }

    return stoi(input);
}

#endif //AK_IT_P_NS_ANTONSCVETKOVS_1MD_CHARACTERCREATION_H
