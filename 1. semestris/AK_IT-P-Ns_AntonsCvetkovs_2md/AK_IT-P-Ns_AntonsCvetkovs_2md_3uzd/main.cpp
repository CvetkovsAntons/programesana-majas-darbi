#include <iostream>
#include <cmath>

using namespace std;

int vms(int Vkmh) { // funkcija vms parveido atrumu no km/h uz m/s
    double ms = Vkmh * 1000 / 3600.0;

    return int(round(ms)); // funkicja round no cmath bibliotekas noapalo sakitli uz leju vai uz augsu
}



int meet_time(int kmh1, int kmh2, int km) { // funkcija meet_time atgriez laiku, pec kura divi objekti satiksies, sekundes
    int time = (km * 1000) / (kmh1 + kmh2);

    return time;
}

int main() {
    cout << "Ievadiet pirma objekta atrumu km/h:"; // lietotajs ievada pirma objekta atrumu km/h
    int kmh1;
    cin >> kmh1;

    cout << "\nIevadiet otra objekta atrumu km/h:"; // lietotajs ievada otra objekta atrumu km/h
    int kmh2;
    cin >> kmh2;

    cout << "\nIevadiet attalumu starp objektiem km:"; // lietotajs ievada attalumu starp objektiem km
    int km;
    cin >> km;

    int time = meet_time(vms(kmh1), vms(kmh2), km); // izsaucam funkcija meet_time un padodam ieksa
                                                                            // mainigos kmh1, kmh2 parveidojot tos m/s ar funkciju vms, un km

    cout << "Divi objekti satiksies: " << time << " sekundem"; // izvadam laiku pec kura divi objekti satiksies

    return 0;
}
