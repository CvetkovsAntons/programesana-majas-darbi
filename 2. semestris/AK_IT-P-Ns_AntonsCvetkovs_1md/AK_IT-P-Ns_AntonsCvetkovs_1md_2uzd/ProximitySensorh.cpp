#include "ProximitySensor.h"

using namespace std;

ProximitySensor::ProximitySensor(string serial_number, bool state = false) {
    ProximitySensor::serial_number = serial_number;
    ProximitySensor::state = state;
}

bool ProximitySensor::Scan(int area) {
    if (area % 2 == 0) {
        return false;
    }

    return true;
}

bool ProximitySensor::GetState() const {
    return ProximitySensor::state;
}

bool ProximitySensor::SetState() {
    ProximitySensor::state = !ProximitySensor::state;
    return ProximitySensor::state;
}

void ProximitySensor::PrintSensor() {
    cout << "Serial Number: " << ProximitySensor::serial_number << endl;
    cout << "State: " << ProximitySensor::state << endl;
}
