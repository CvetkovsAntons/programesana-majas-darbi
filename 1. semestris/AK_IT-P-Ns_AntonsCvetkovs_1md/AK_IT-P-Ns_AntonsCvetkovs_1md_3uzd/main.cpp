#include <iostream>
#include <random>  // biblioteka, kas ir nepieciesama lai izveidot nejausu skaitli

using namespace std;

int randomNumber(int min, int max) {  // funkcija, kas izveido un atgriez random skaitli un pienem divs vertibas min un max
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> random(min,max);  // izveidojam nejausu skaitli diapazona no min lidz max

    return random(gen);  // funkcija atgriez random skaitli
}



string input() {
    string num; // lietotaja skaitla glabasanai prieks, tika izmantots mainigas ar data tipu string, jo
                // kad es meginaju uzrakstit algoritmu un mainigaja ar data tipu int bija ievadits float, burti vai
                // citi simboli, C++ visus burtus parversa par 0 un, piemeram bija ievaditi 5 burti,
                // tad '0' bija agtriezta  piecas reizes. Ja bija ievadits '0.591.5', tad funkcija 1. reizi atgrieza 0, 2.
                // izvadija kludu, ka lietotjama jaizmanto veselus skaitlus, 3. izvadija kludu, ka jaievada skaitli
                // intervala no 0 lidz 100, jo 561 > 100, 4. reizi izvadija kludu, ka lietotjama jaizmanto veselus skaitlus un
                // 5. reizi atrgrieza 5

    cout << "Vai datora skaitlis ir pareizs? (ievadiet skaitli no 1-3)" << endl;
    cout << "1. Ja, datora skaitlis ir pareizs" << endl;
    cout << "2. Ne, datora skaitls ir mazaks" << endl;
    cout << "3. Ne, datora skaitlis ir lielaks" << endl;
    cout << "Atbilde: ";

    cin >> num;

    return num; // atriezam ievadito vertibu
}



int checkInputForSpecialCharacters(string numStr) { // funkcija, kas parbauda vai lietotaja ievadita vertiba ir vesels skaitlis un atgriez to
    int i = 0;

    while (i < numStr.length() || stoi(numStr) < 1 || stoi(numStr) > 3) { // cikls while, kas tiek izpildits kamer mainigais 'i' < mainiga 'numStr' garumu
        if (isdigit(numStr[i]) == false) { // if operators, kas parbauda katru simbolu no mainiga 'numStr' vai tas ir cipars
            cout << "\n!!! Jaievada veselo skaitli intervala no 1 lidz 3 !!!" << endl; // gadijuma, kad netiek ievadits veselais skaitlis, tiek izvadita kluda
                                                                                         // un programmaa liek leitotajam ievadit jaunu skaitli

            numStr = input(); // lietotajs ievada jaunu skaitli

            i = 0; // mainiga 'i' vertiba atjaunojas, jo bija ierakstits jauns skaitlis

            continue; // partraucam cikla atkartojumu un parejam uz nakamo
        }

        i++; // gadijuma, kad mainigaja 'numStr' simbols ir skaitlis, tad palielinajam mainiga 'i' vertibu pa 1
    }

    int num = stoi(numStr); // parversam mainigo 'numStr' no string uz int un pieskiram to vertibu mainigajam 'num'

    return num; // atriezam lietotaja skaitli
}



int userNumber() {

    int num = checkInputForSpecialCharacters(input()); // parbaudam, vai ievadita vertiba ir veselais skaitlis

    while (num < 0 || num > 100) { // cikls while, kas izpildisies, kamer mainigas 'num' ir mazaks par 0 vai lielaks par 100
        cout << "\n!!! Jaievada veselo skaitli intervala no 0 lidz 100 !!!" << endl; // ja ievaditais skaitlis ir mazaks par 0 vai lielaks par 100,
                                                                                     // tiek izvadita kluda un programma liek lietotajam ievadit jaunu skaitli

        num = checkInputForSpecialCharacters(input()); // parbaudam, vai jauna ievadita vertiba ir veselais skaitlis
    }

    return num; // atgriezam lietotaja skaitli
}


bool game() { // funkcija, kas parbauda vai lietotajs uzvareja vai zaudeja un atgriez true vai false
    int min = 0, max = 100; // mainigie ar data tipu int min un max, kas nosaka datoram, kura diapazona jamekle lietotaja skaitli

    for (int i = 1; i <= 10; i++) {  // cikls for, kas izpildisies 10 reizes

        int random = randomNumber(min, max); // pieskiram mainigajam atgriezto vertibu no funkcijas randomNumber()

        cout << "\nDators: 'Mans skaitlis ir' " << random << endl;

        int user = userNumber();

        if (user == 1) { // operators if, kas parbauda, vai lietotaja skaitlis ir vienads ar datora skaitli
            cout << "Jus zaudejat! Dators uzmineja skaitli no " << i << " meginajuma!" << endl; // izvadam pazinojumu, ka dators uzvareja
            return false; // partraucam funkcijas izpildi un atgriezam false vertibu
        }

        if (user == 2) { // operators if, kas parbauda, vai datora skaitlis ir mazaks par lietotaja skaitli
            min = random + 1; // ja datora skaitlis ir mazaks, tad mainigajam min pieskiram mainiga random + 1 vertibu, jo mazaks par so vertibu lietotaja skaitlis nevar but
            continue;
        }

        if (user == 3) { // operators if, kas parbauda, vai datora skaitlis ir lielaks par lietotaja skaitli
            max = random - 1; // ja datora skaitlis ir lielaks, tad mainigajam max pieskiram mainiga random - 1 vertibu, jo lielaks par so vertibu lietotaja skaitlis nevar but
            continue;
        }
    }

    return true;  // atgriezam true vertibu
}

int main() {
    bool win = game();  // pieskiram mainigajam atgriezto vertibu no funkcijas game()

    if (win) {  // ja tiek atgriezta true vertiba, tad izvadam pazinojumu, ka lietotajs uzvareja
        cout << "\nJus uzvarejat!";
    }

    return 0;
}
