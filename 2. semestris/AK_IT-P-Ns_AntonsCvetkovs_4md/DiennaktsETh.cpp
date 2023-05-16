#include "DiennaktsET.h"

DiennaktsET::DiennaktsET() {
    cout << "Diennakts E-Talons bija nopirkts" << endl;
}

void DiennaktsET::Print() const {
    eTalons::Print();
    cout << "Activated: " << DiennaktsET::activated << endl;
    time_t activation = DiennaktsET::activation_date;
    cout << "Activation Date: " << ((DiennaktsET::activation_date == 0) ? "-" : ctime(&activation)) << endl; // ja etalons nebija aktivets, tad izvada "-"
    // otradak, konvertajam activation_date vertibu ar ctime biblioteku
    // ta parvers sekundes no 1970 izvadot dienu, laiku un gadu
}

void DiennaktsET::Use() {
    if (!DiennaktsET::activated) { // ja etalons nebija aktivets pirms izmantosans
        DiennaktsET::activated = true; // aktive etalonu
        DiennaktsET::activation_date = time(nullptr); // pieskiram pasreizejais datums/laiks (sekundes no 1970. gada)

        cout << "zals" << endl;

        return; // partraucu funkcijas darbu
    }

    time_t current_time = time(nullptr); // pasreizejais datums/laiks

    if (difftime(current_time, DiennaktsET::activation_date) < 24 * 60 * 60) { // salidzinam activation_date un pasreizejais laiks
        cout << "zals" << endl;
        return;
    }

    cout << "sarkans" << endl;
}

void DiennaktsET::Add(int) {}