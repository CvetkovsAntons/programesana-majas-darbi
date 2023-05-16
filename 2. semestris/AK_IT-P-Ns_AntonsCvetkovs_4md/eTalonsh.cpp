#include "eTalons.h"

eTalons::eTalons() {
    eTalons::serial = eTalons::serialGenerator(); // kad eTalons objekts tiek izveidots, pieskiru vertibu mainigajiem serial
}

void eTalons::Print() const {
    cout << "Serial: " << eTalons::serial << endl;
}

string eTalons::serialGenerator() {
    string generatedSerial = "0" + to_string(randomNumber(1, 9)) + "-"; // deklareju string ar randomu vienskaitli ar 0 prieksa

    for (int i = 0; i < 15; i++) { // pieskiru vel 15 nejausus vienskaitlus, izmantojot funkciju, kuru es glabu Helpers.h
        generatedSerial += to_string(randomNumber(1, 9));
    }

    return generatedSerial;
}
