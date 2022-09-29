#include <iostream>
#include <random> // biblioteka, kas ir nepieciesama lai izveidot nejausu skaitli

using namespace std;

int randomNumber() { // funkcija, kas izveido un atgriez random skaitli
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> random(0,100); // izveidojam nejausu skaitli diapazona no 0 lidz 100

    return random(gen); // funkcija atgriez random skaitli
}



string input() {
    string num; // lietotaja skaitla glabasanai prieks, tika izmantots mainigas ar data tipu string, jo
                // kad es meginaju uzrakstit algoritmu un mainigaja ar data tipu int bija ievadits float, burti vai
                // citi simboli, C++ visus burtus parversa par 0 un, piemeram bija ievaditi 5 burti,
                // tad '0' bija agtriezta  piecas reizes. Ja bija ievadits '0.591.5', tad funkcija 1. reizi atgrieza 0, 2.
                // izvadija kludu, ka lietotjama jaizmanto veselus skaitlus, 3. izvadija kludu, ka jaievada skaitli
                // intervala no 0 lidz 100, jo 561 > 100, 4. reizi izvadija kludu, ka lietotjama jaizmanto veselus skaitlus un
                // 5. reizi atrgrieza 5

    cout << "Ievadiet veselo skaitli no 0 lidz 100:";

    cin >> num; // lietotajs ievada skaitli

    return num; // atriezam ievadito vertibu
}



int checkInputForSpecialCharacters(string numStr) { // funkcija, kas parbauda vai lietotaja ievadita vertiba ir vesels skaitlis un atgriez to
    int i = 0;

    while (i < numStr.length()) { // cikls while, kas tiek izpildits kamer mainigais 'i' < mainiga 'numStr' garumu
        if (isdigit(numStr[i]) == false) { // if operators, kas parbauda katru simbolu no mainiga 'numStr' vai tas ir cipars
            cout << "\n!!! Jaievada veselo skaitli intervala no 0 lidz 100 !!!" << endl; // gadijuma, kad netiek ievadits veselais skaitlis, tiek izvadita kluda
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



int userNumber() {  // funkcija, kas izvada lietotaja ievadito skaitli
    int num = checkInputForSpecialCharacters(input()); // parbaudam, vai ievadita vertiba ir veselais skaitlis

    while (num < 0 || num > 100) { // cikls while, kas izpildisies, kamer mainigas 'num' ir mazaks par 0 vai lielaks par 100
        cout << "\n!!! Jaievada veselo skaitli intervala no 0 lidz 100 !!!" << endl; // ja ievaditais skaitlis ir mazaks par 0 vai lielaks par 100,
                                                                                     // tiek izvadita kluda un programma liek lietotajam ievadit jaunu skaitli

        num = checkInputForSpecialCharacters(input()); // parbaudam, vai jauna ievadita vertiba ir veselais skaitlis
    }

    return num; // atgriezam lietotaja skaitli
}



bool game() { // funkcija, kas parbauda vai lietotajs uzvareja vai zaudeja un atgriez true vai false
    int random = randomNumber(); // pieskiram mainigajam atgriezto vertibu no funkcijas randomNumber()

    for (int i = 1; i <= 10; i++) { // cikls for, kas izpildisies 10 reizes

        int user = userNumber(); // pieskiram mainigajam atgriezto vertibu no funkcijas userNumber()

        if (user < random) { // operators if, kas parbauda, vai lietotaja skaitlis ir mazaks par random skaitli
            cout << "\nSkaitlis ir lielaks par ievadito!"  << endl;
            continue; // parejam uz nakamo cikla atkartojumu
        }

        if (user > random) { // operators if, kas parbauda, vai lietotaja skaitlis ir lielaks par random skaitli
            cout << "\nSkaitlis ir mazaks par ievadito!"  << endl;
            continue;  // parejam uz nakamo cikla atkartojumu
        }

        if (user == random) {  // operators if, kas parbauda, vai lietotaja skaitlis ir vienads ar random skaitli
            cout << "\nJus uzvarejat no " << i << ". meginajuma!"  << endl; // izvadam pazinojumu, ka lietotajs uzvareja
            return true; // partraucam funkcijas izpildi un atgriezam true vertibu
        }
    }

    return false; // atgriezam false vertibu
}



int main() {
    bool win = game(); // pieskiram mainigajam atgriezto vertibu no funkcijas game()

    if (!win) { // ja tiek atgriezta false vertiba, tad izvadam pazinojumu, ka lietotajs zaudeja
        cout << "\nJus zaudejat!";
    }

    return 0;
}
