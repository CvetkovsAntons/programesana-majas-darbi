#ifndef AK_IT_P_NS_ANTONSCVETKOVS_1MD_PLAYERMOVE_H
#define AK_IT_P_NS_ANTONSCVETKOVS_1MD_PLAYERMOVE_H

using namespace std;

char getPlayerMove(Character character) {
    if (character.GetLife() > 0) {
        string input;

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

    return ' ';
}

#endif //AK_IT_P_NS_ANTONSCVETKOVS_1MD_PLAYERMOVE_H
