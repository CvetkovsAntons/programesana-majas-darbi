#include "BraucienuskET.h"

BraucienuskET::BraucienuskET(int t) {
    BraucienuskET::trips = (t > 0) ? t : 1; // pieskiru veribu trips. Parbaudu vai tas ir pozitivs skaitlis, ja ne, tad bus pieskirta veriba 1
    cout << "Braucienu E-Talons bija nopirkts" << endl;
}

void BraucienuskET::Print() const {
    eTalons::Print();
    cout << "Trips left: " << BraucienuskET::trips << endl;
}

void BraucienuskET::Use() {
    if (BraucienuskET::trips > 0) { // ja trips ir lielaks par 0, tad var registret braucienu
        BraucienuskET::trips -= 1; // samazinam trips par 1
        cout << "zals" << endl;
        return;
    }

    cout << "sarkans" << endl;
}

void BraucienuskET::Add(int) {}
