#include <iostream>

using namespace std;

string input() {
    string num;

    cout << "Ievadiet veselo skaitli:";

    cin >> num;

    return num;
}

// funkcija parbauda vai lietotajs ir ievadijis veselo skaitli
string checkInputForSpecialCharacters(string num) {
    int i = 0;

    while (i < num.length()) {
        if (isdigit(num[i]) == false) {
            cout << "\n!!! Jaievada veselo skaitli !!!" << endl;

            num = input();

            i = 0;

            continue;
        }

        i++;
    }

    return num;
}

// funkcija findPalindrome parbauda vai skaitlis ir palindroms
// ka parametru ta pieniem string konstanti, jo ta netiek mainita
// ar & izvedojam reference uz originalo vertibu atminā
bool findPalindrome(const string& num) {
    string numReverse = num;

    reverse(numReverse.begin(), numReverse.end()); // apgriezam mainigo numReverse

    if (num != numReverse) { // ja num nav vienads ar numReverse, atgriezam false
        return false;
    }

    return true; // ja num ir vienads ar numReverse, atgriezam true
}

int main() {
    // A dala
    string num = checkInputForSpecialCharacters(input()); // izveidam mainigo num ar data tipu string un vertibu,
                                                               // ko atgriez funkcija checkInputForSpecialCharacters() un
                                                               // ka parametru pienem vetibu, kuru atgriez funkcija input()

    if(!findPalindrome(num)) { // parbaudam vai skaitlis nav palindroms
        cout << "Skaitlis " + num + " nav palidnroms" << endl; // ja nav tad izvadam to skaitli ar nosacito pazinojumu
    } else {
        cout << "Skaitlis " + num + " ir palindroms" << endl; // ja sakilis ir plaindroms, tad izvadam to ar nosacito pazinojumu
    }

    // B dala
    for (int i = 100001; i < 1000000; i++) { // cikls for kas izpildas diapazona no 100 001 lidz 1 000 000
        if (findPalindrome(to_string(i))) { // ja sakitlis ir palindroms, tad izvadam to
            cout << i << endl;
        }
    }

    return 0;
}
