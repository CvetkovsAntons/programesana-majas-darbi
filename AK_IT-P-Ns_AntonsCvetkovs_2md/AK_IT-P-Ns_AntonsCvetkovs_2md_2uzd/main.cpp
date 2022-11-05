#include <iostream>
#include <cmath>

using namespace std;

string input() { // funkcija pieprasa lietotaju ievadit cik stundas vins izmantoja stavvietu
    string hours;

    cout << "Ievadiet cik ilgi masina staveja stavvieta:";

    cin >> hours;

    return hours;
}



double checkForSpecialCharacters(string hoursStr) { // funkcija parbauda vai lietotajs ir ievadijis skaitli
    int i = 0;

    while (i < hoursStr.length()) {
        if (isdigit(hoursStr[i]) == false && hoursStr[i] != '.') { // parbaudam, vai kads no simboliem ir burts
            cout << "\n!!! Ievadiet laiku stundas (0 - 24) (decimaldalam prieks izmantojiet '.') !!!" << endl; // atgrizam kludu

            hoursStr = input(); // pieprasim ievadit jaunu vertibu

            i = 0;

            continue;
        }

        i++;
    }

    double hours = stod(hoursStr);

    return hours;
}



double getHours() { // funkcija getHours() pieprasa lietotaju ievadit cik ilgi vins izmantoja stavvietu
    double hours = checkForSpecialCharacters(input()); // mainigajam hours pieskiram vertibu, kuru atgriezam no funkcijas
                                                               // checkForSpecialCharacters()

    while (hours < 0 || hours > 24) { // ja lietotajs ievada vertibu vairak par 24 vai mazak par 0, tad pieprasam ievadit jaunu vertibu
        cout << "\n!!! Ievadiet laiku stundas (0 - 24) !!!" << endl;

        hours = checkForSpecialCharacters(input());
    }

    return hours;
}



double getParkingPrice(double hours) { // funkcija atgriez stavvietas izmantosana cenu
    if (hours == 0) {
        return 0;
    }

    double price = 2;

    if (hours > 3) {
        hours = hours - 3;
        price = price + floor(hours) * 0.5; // funckija floor() no cmath bibliotekas noapalo skaitli uz leju
    }

    if (price > 10) {
        price = 10;
    }

    return price;
}



int main() {
    double price = getParkingPrice(getHours()); // izaucam funkciju getParkingPrice(), ka parametru padodam funkicju getHours()

    cout << "Jamaksa: " << price << " eiro";  // izvadam cik bus jasamaksa klientam

    return 0;
}
