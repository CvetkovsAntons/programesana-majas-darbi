#include <iostream>
#include <vector>
#include <random>

using namespace std;

// funkicja, kas piepras lietotaju ievadit tindas un kolonu skaitu
string getRowsAndColumns() {
    string rows;

    cout << "Ievadiet masiva rindu un kolonu skaitu (NxN):";

    cin >> rows;

    return rows;
}

// funkcija, kas parbauda vai lietotja ir ievadijis skaitlus
int checkInputForSpecialCharacters(string numStr, string input) {
    int i = 0;

    while (i < numStr.length()) {
        if (isdigit(numStr[i]) == false) {
            cout << "\n!!! Jaievada veselo skaitli!!!" << endl;

            numStr = getRowsAndColumns();

            i = 0;

            continue;
        }

        i++;
    }

    int num = stoi(numStr);

    return num;
}

// funkcija, kas pagriez masivu
void rotateArray(vector<vector<int>> &array) {
    reverse(array.begin(), array.end()); // funkcija reverse() aprgriez masivu

    int size = array.size(); // saglabajam masiva izmeru

    for(int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++) {
            swap(array[i][j], array[j][i]); // samainam ar vietam divas masiva vertibas
        }
    }
}



int main() {
    // pieprasam lietotaju ievadit rindu un kolonu skaitu
    int rowsAndColumns = checkInputForSpecialCharacters(getRowsAndColumns(), "row");

    vector<vector<int>> array;

    // iearksatam masiva nejausos skaitlus
    for(int i = 0; i < rowsAndColumns; i++) {

        vector<int> v1;

        for(int j = 0; j < rowsAndColumns; j++) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> random(10,99);

            v1.push_back(random(gen));
        }

        array.push_back(v1);
    }


    // izvadam origianlo masivu
    cout << "-----------------" << endl;
    cout << "Originals masivs:" << endl;
    cout << "-----------------" << endl;

    for(int i = 0; i < rowsAndColumns; i++) {
        for(int j = 0; j < rowsAndColumns; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }


    // apgriezam masivu
    rotateArray(array);

    // izvadam apgriezto masivu
    cout << "-----------------" << endl;
    cout << "Redigets masivs:" << endl;
    cout << "-----------------" << endl;

    for(int i = 0; i < rowsAndColumns; i++) {
        for(int j = 0; j < rowsAndColumns; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    cout << "-----------------\n\n\n";



    return 0;
}
