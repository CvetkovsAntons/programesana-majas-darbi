#include "ProximitySensor.h"

using namespace std;

ProximitySensor::ProximitySensor(string serial_number) {
    ProximitySensor::serial_number = serial_number;
    ProximitySensor::state = false;
}

bool ProximitySensor::Scan(int area) {
    if (area % 2 == 0) { // ja skaitlis ir para
        return false; // tad atgriezam false
    }

    return true; // ja skaitlis ir ne para, tad atgriezam true
}

bool ProximitySensor::GetState() const {
    return ProximitySensor::state;
}

void ProximitySensor::SetState() {
    ProximitySensor::state = !ProximitySensor::state; // samainam state vertibu uz reteju (ja ir true, tad paliek false; ja ir false, tad paliek true)
}

void ProximitySensor::PrintSensor() {
    cout << "Serial Number: " << ProximitySensor::serial_number << endl;
    cout << "State: " << ProximitySensor::state << endl;
}
