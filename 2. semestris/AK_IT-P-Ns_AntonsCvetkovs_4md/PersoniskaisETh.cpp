#include "PersoniskaisET.h"

PersoniskaisET::PersoniskaisET(int t, string n, string s) {
    PersoniskaisET::trips = (t > 0) ? t : 1; // pieskiru trips vertibu
    PersoniskaisET::name = n; // vards
    PersoniskaisET::surname = s; // uzvards

    cout << "Personiskais E-Talons bija nopirkts" << endl;
}

void PersoniskaisET::Print() const {
    eTalons::Print();
    cout << "Name: " << PersoniskaisET::name << endl;
    cout << "Surname: " << PersoniskaisET::surname << endl;
    cout << "Trips: " << PersoniskaisET::trips << endl;
    cout << "Trips Made: " << PersoniskaisET::totalTrips << endl;
}

void PersoniskaisET::Use() {
    if (PersoniskaisET::trips > 0) { // ja ir vismaz viens brauciens, tad var registret to
        PersoniskaisET::trips -= 1;
        PersoniskaisET::totalTrips += 1;
        cout << "zals" << endl;
        return;
    }

    cout << "sarkans" << endl;
}

void PersoniskaisET::Add(int t) {
    PersoniskaisET::trips += t;
}