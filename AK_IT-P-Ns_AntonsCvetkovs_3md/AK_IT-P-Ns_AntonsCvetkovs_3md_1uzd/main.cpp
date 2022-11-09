#include <iostream>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

string getRows() {
    string rows;

    cout << "Ievadiet masiva rindu skaitu:";

    cin >> rows;

    return rows;
}

string getColumns() {
    string columns;

    cout << "Ievadiet masiva kolonnu skaitu:";

    cin >> columns;

    return columns;
}

int checkInputForSpecialCharacters(string numStr, string input) {
    int i = 0;

    while (i < numStr.length()) {
        if (isdigit(numStr[i]) == false) {
            cout << "\n!!! Jaievada veselo skaitli!!!" << endl;

            if (input == "row") {
                numStr = getRows();
            }

            if (input == "column") {
                numStr = getColumns();
            }

            i = 0;

            continue;
        }

        i++;
    }

    int num = stoi(numStr);

    return num;
}

void rotateArray(vector<vector<int>> &array) {
    reverse(array.begin(), array.end());

    int size = array.size();

    for(int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++) {
            swap(array[i][j], array[j][i]);
        }
    }
}



int main() {
    int rows = checkInputForSpecialCharacters(getRows(), "row");

    int columns = checkInputForSpecialCharacters(getColumns(), "column");

    vector<vector<int>> array;

    for(int i = 0; i < rows; i++) {

        vector<int> v1;

        for(int j = 0; j < columns; j++) {

            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> random(10,99);

            v1.push_back(random(gen));
        }

        array.push_back(v1);
    }



    cout << "-----------------" << endl;
    cout << "Originals masivs:" << endl;
    cout << "-----------------" << endl;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    cout << "-----------------\n\n\n";



    rotateArray(array);

    cout << "-----------------" << endl;
    cout << "Redigets masivs:" << endl;
    cout << "-----------------" << endl;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    cout << "-----------------\n\n\n";



    return 0;
}
