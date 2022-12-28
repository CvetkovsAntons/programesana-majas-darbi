#include <iostream>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <random>

using namespace std;

// masivs ar vardiem
vector<string> wordsArray = {"basketball", "house", "mother", "boy", "girl",
                            "dad", "grandmother", "chain", "candy", "clan",
                            "book", "programming", "homework", "computer", "artificial",
                            "music", "symphony", "intelligence", "christmas", "winter"};

vector<string> usedLetters; // masivs ar nepareiziem burtiem

bool quit = false;

int errors = 0; // mainigais ar kludu skaitu
int wordsMeant = 0; // mainigais ar uzminetu vardu skaitu

// funkcija, kas izvelas vardu
vector<string> getWord() {
    string word; // mainigais, kas satur vardu
    string letter; // mainigas, kas satur burtu
    vector<string> array; // mainigais, kas

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> random(0,wordsArray.size()); // generajam nejusu skaitli

    word = wordsArray[random(gen)]; //izvelejamies nejausu vardu no masiva

    // nonemam izveleto vardu no masiva
    wordsArray.erase(remove(wordsArray.begin(), wordsArray.end(), word), wordsArray.end());

    // parversam izveleto vardu masiva
    for (int i = 0; i < word.length(); i++) {
        letter = word[i]; // izvedoju mainigu, jo masivaa, kas pienem string nevar push_back pointeru
        array.push_back(letter);
    }

    return array;
}

// funkcija. kas izvedio masivu no punktiem
vector<string> getPointArray(int size) {
    vector<string> array;

    for (int i = 0; i < size; i++) {
        array.push_back(".");
    }

    return array;
}

// funkcija, kura notiek vardu minesana
bool game(vector<string> word) {
    vector<string> pointArray = getPointArray(word.size()); // izveidojam masivu ar punktiem
    string letter; // mainigais, kas saglaba burtu

    while (errors < 10) { // cikls izpildisies kamer lietotajam nebus 10 kludas
        system("CLS");

        cout << "\nErrors: " << errors << endl; // izvadam kludu skaitu
        cout << "\nINCORRECT letters: "; // izvadam neparizus burtus
        for (int i = 0; i < usedLetters.size(); i++) {
            cout << usedLetters[i] << ", ";
        }

        cout << "\n\n";

        // izvadam punktus
        for (int i = 0; i < pointArray.size(); i++) {
            cout << pointArray[i] << " ";
        }

        cout << "\nEnter letter (enter 0 if you want to quit):";
        letter = getch(); // lietotajs ievada burtu

        // ja lietotajs ievada 0, tad izejam no pensijas
        if (letter == "0") {
            quit = true;
            return false;
        }

        int rightLetters = 0; // atmineto burtu skaits

        // parbaudam vai ievadits burts ir varda
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == letter) {
                pointArray[i] = letter;
                rightLetters += 1; // ja burts ir pareizs pieskaitam vieninieku
            }
        }

        // ja nav pareiza burta, tad pieskaitam kludu un pievienojam burtu masiva ar nepareiziem burtiem
        if (rightLetters == 0) {
            errors += 1;
            usedLetters.push_back(letter);
        }

        // parbaudam cik burtu sakrit
        rightLetters = 0;
        for (int i = 0; i < pointArray.size(); i++) {
            // ja burti sakrit, tad piskaitam 1 pie mainga
            if (pointArray[i] == word[i]) {
                rightLetters += 1;
            }
        }

        // ja burtu skaits sakrit ar minema vardu skaitu, tad vards ir atminets
        if (rightLetters == word.size()) {
            // atnemam kludas
            if (errors < 5) {
                errors -= errors;
            } else {
                errors -= 5;
            }

            wordsMeant += 1; // peiskaitam atmento vardu
            usedLetters = {}; // nonemam visas vertibas no masiva ar nepareiziem burtiem

            // parbaudam cik vardi ir atmineti
            if (wordsMeant < 20) {
                return true; // ja visi vardi nav atmineti, tad turpinam
            } else {
                return false; // ja ne, tad pabeidzam speli
            }
        }
    }

    return false;
}

int main() {
    bool gameRuns = true;

    while (gameRuns) { // spele turpinasies kamer gameRuns == true
        gameRuns = game(getWord());
    }

    system("CLS");

    if (quit) {
        cout << "\nGoodbye!" << endl;
    } else if (wordsMeant == 20) {
        cout << "Congratulations! You won! :)" << endl;
    } else {
        cout << "You have lost! You have meant " << wordsMeant << " words! :(" << endl;
    }

    system("pause");

    return 0;
}
